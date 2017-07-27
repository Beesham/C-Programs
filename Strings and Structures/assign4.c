/*
	Author: Beesham Sarendranauth, 104854956
	Date: 2017/07/27
	Description: This program processes a comma separated values (csv) file. New data can be added,
    searched, or displayed.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define FOUND 1
#define NOT_FOUND -1

#define MAX_LINE_LENGTH 256
#define MAX_COURSES 10
#define MAX_COURSE_NAME_LENGTH 50
#define MAX_COURSE_CODE_LENGTH 12
#define MAX_TERM_LENGTH 6

#define COURSENAMEINDEX 1
#define FACULTYINDEX 2
#define SUBJECTINDEX 3
#define LEVELINDEX 4
#define SECTIONINDEX 5
#define SEMESTERINDEX 6
#define YEARINDEX 7

typedef enum { 
    NAME_FLAG,
    COURSE_CODE_FLAG
} searchFlag;        

typedef struct {
    int courseID;
    char courseName[MAX_COURSE_NAME_LENGTH];
    char courseCode[MAX_COURSE_CODE_LENGTH];
    char term[MAX_TERM_LENGTH];
} CourseInfo;

//prototypes
int loadCourseInfo(CourseInfo *courses);
void addCourseInfo(CourseInfo *courses, int *courseCount, char *record);
int searchCourseInfo(const CourseInfo *courses, size_t courseCount, int courseId, char *courseName);
void displayCourseInfo(const CourseInfo *courses, size_t courseCount);
void processCourseRecord(char *record, CourseInfo *courseInfo);
void convertToUppercase(char *string);
int binarySearch(const CourseInfo *courses, size_t courseCount, int searchKey);
int linearSearch(const CourseInfo *courses, size_t courseCount, searchFlag flag, char *searchKey);
void buildRecord(char *record, const char *s);


static int mCourseId = 1;


int main(void){
    
    CourseInfo courses[MAX_COURSES];
    int courseCount = 0;
        
    puts("LOADED COURSES:");
    courseCount = loadCourseInfo(courses);
    
    
   
    
    int selection = 0;
    
    while (selection != 4){
        //Displays menu
        puts("");
        puts("1. ADD NEW COURSE");
        puts("2. SEARCH FOR COURSE");
        puts("3. DISPLAY ALL COURSE DATA");
        puts("4. EXIT");
        
        //Handles menu selection
        printf("%s", "Enter option: ");
        scanf("%d", &selection);
    
        switch(selection){
            case 1:{
                char record[MAX_LINE_LENGTH];
                char course[MAX_COURSE_NAME_LENGTH];
                char facultyCode[3], subjectCode[3], levelCode[4], sectionNumber[3];
                char semester[2];
                char year[5];
                
                printf("%s", "Please enter course name: ");
                scanf("%s", course);
                
                printf("%s", "Faculty code: ");
                scanf("%s,", facultyCode);
                
                printf("%s", "Subject code: ");
                scanf("%s", subjectCode);
                
                printf("%s", "Level code: ");
                scanf("%s", levelCode);
                
                printf("%s", "Section number: ");
                scanf("%s", sectionNumber);
                
                printf("%s", "Semester ('S', 'F', 'W'): ");
                scanf("%s", semester);
                
                printf("%s", "Year: ");
                scanf("%s", year);
                
                //builds the record with comma separated values
                strcpy(record, course);
                buildRecord(record, facultyCode);
                buildRecord(record, subjectCode);
                buildRecord(record, levelCode);
                buildRecord(record, sectionNumber);
                buildRecord(record, semester);
                buildRecord(record, year);
                
                addCourseInfo(courses, &courseCount, record);                
            }break;
            
            case 2:{
                char course[MAX_COURSE_NAME_LENGTH];
                char *temp;
                long courseId = 0;
                printf("%s", "Please enter course name or ID to search for: ");
                scanf("%s", course);
                courseId = strtol(course, &temp, 10);
                
                if(courseId == 0){
                    searchCourseInfo(courses, courseCount, 0, course);
                }
                else{
                    searchCourseInfo(courses, courseCount, courseId, NULL);
                }
            }break;

            case 3:{
                displayCourseInfo(courses, courseCount);
            }break;
            
            case 4: return 0;
            
            default: puts("Unsupported action!");
        }
    }
        
    return 0;
}

/*
    loadCourseInfo: reads data relating to courses from a csv and stores it in an array of CourseInfo
    input: the array to store the data (courses)
    output: the number of records read/ number of courses (courseCount)
*/
int loadCourseInfo(CourseInfo *courses){
    
    FILE *filePtr = NULL;
    char fileName[50];

    char courseRecordBuffer[MAX_LINE_LENGTH];
    int courseCount = 0;
    
    printf("%s", "Enter file to load courses from: ");
    scanf("%s", fileName);
    
    if((filePtr = fopen(fileName, "r")) == NULL) puts("Unable to open file. Exiting...");
    else{
        while(fgets(courseRecordBuffer, MAX_LINE_LENGTH, filePtr) != NULL){
            addCourseInfo(courses, &courseCount, courseRecordBuffer);
        }
        fclose(filePtr);
    }
        
    return courseCount;
}

/*
    processCourseRecord: formats data relating to a course into readable output
    input: the data to be formatted (record), a struct to save the data (courseInfo)
*/
void processCourseRecord(char *record, CourseInfo *courseInfo){
    
    char *strTokPtr;
    int index = 1;  //the index of data to be processed

    strTokPtr = strtok(record, ",");
    while(strTokPtr != NULL){
        
        switch(index){
            
            //processes the name of the course
            case COURSENAMEINDEX:{
                convertToUppercase(strTokPtr);
                strcpy(courseInfo->courseName, strTokPtr);
            }
            break;
            
            //processes the course code of the course along with SUBJECTINDEX, LEVELINDEX, and SECTIONINDEX
            //concats the three codes together
            case FACULTYINDEX:{
                sprintf(courseInfo->courseCode, "%02d", atoi(strTokPtr));
            }
            break;
            
            case SUBJECTINDEX:{
                char subjectCode[3];
                               
                sprintf(subjectCode, "%02d", atoi(strTokPtr));

                strcat(courseInfo->courseCode, subjectCode);
            }
            break;
            
            case LEVELINDEX:{
                strcat(courseInfo->courseCode, "-");

                char levelCode[4];
                               
                sprintf(levelCode, "%03d", atoi(strTokPtr));

                strcat(courseInfo->courseCode, levelCode);
            }
            break;
            
            case SECTIONINDEX:{
                strcat(courseInfo->courseCode, "-");

                char sectionCode[3];
                               
                sprintf(sectionCode, "%02d", atoi(strTokPtr));

                strcat(courseInfo->courseCode, sectionCode);
            }
            break;
            
            //process the term 
            case SEMESTERINDEX:{
                convertToUppercase(strTokPtr);
                sprintf(courseInfo->term, "%s", strTokPtr);
            }
            break;
            
            case YEARINDEX:{
                int year = atoi(strTokPtr);
                char temp[4];            
                sprintf(temp, "%d", year);
                strcat(courseInfo->term, temp);
            }
            break;
        }
                
        index++;
        
        strTokPtr = strtok(NULL, ",");
    }
    courseInfo->courseID = mCourseId++;
}

/*
    convertToUppercase: converts a string to all uppercase
    input: the string to convert (string)
*/
void convertToUppercase(char *string){
    while(*string != '\0'){
        *string = toupper(*string);
        string++;
    }    
}

/*
    addCourseInfo: adds a new course to the courses array
    input: the array to be added to, the number of courses existing (courseCount), the course data to be added (record)
*/
void addCourseInfo(CourseInfo *courses, int *courseCount, char *record){
    int validateData(const CourseInfo *courses, size_t courseCount, CourseInfo courseInfo);

    int index = *courseCount;
    CourseInfo newCourseInfo = {0};
    processCourseRecord(record, &newCourseInfo);
    
    
    if(validateData(courses, *courseCount, newCourseInfo) != FOUND){
        courses[index] = newCourseInfo;
        (*courseCount)++;
    }
    else printf("%s %s\n","*DUPLICATE COURSE ID OR CODE* UNABLE TO ADD:", newCourseInfo.courseName);
}

/*
    searchCourseInfo: searches through an array for a value, only one value can be searched at a time, either name or id
    input: the array to be searched (courses), the size of array (courseCount), the searchKey (courseId or courseName)
    output: if found key 1, or -1 if not found
*/
int searchCourseInfo(const CourseInfo *courses, size_t courseCount, int courseId, char *courseName){
    
    int resultIndex;
    
    int isFound = NOT_FOUND;
    
    //search for course id
    if(courseId != 0){
        
        resultIndex = binarySearch(courses, courseCount, courseId);
        if(resultIndex != NOT_FOUND){
            courses += resultIndex;
            displayCourseInfo(courses, 1);
            isFound = FOUND;
        }
        else printf("%s %d %s\n", "COURSE ID:", courseId, "WAS NOT FOUND");
    }
    //search for course name
    else if(courseName != NULL){

        resultIndex = linearSearch(courses, courseCount, NAME_FLAG, courseName);
        if(resultIndex != NOT_FOUND){
            courses += resultIndex;
            displayCourseInfo(courses, 1);
            isFound = FOUND;
        }
        else printf("%s %s %s\n", "COURSE NAME:", courseName, "WAS NOT FOUND");

    }
    
    return isFound;
}

/*
    validateData: checks for violations of unique constraints (courseID, courseCode)
    input: the array to be searched (courses), the size of array (courseCount), the struct to validate (courseInfo)
    output: 1 if found, else -1
*/
int validateData(const CourseInfo *courses, size_t courseCount, CourseInfo courseInfo){
    
    if(linearSearch(courses, courseCount, COURSE_CODE_FLAG, courseInfo.courseCode) != NOT_FOUND) return FOUND;
    if(binarySearch(courses, courseCount, courseInfo.courseID) != NOT_FOUND) return FOUND;

    return NOT_FOUND;
}

/*
    buildRecord: builds a course record with relating fields seperated with commas
    input: the record being build (record), the field to add (s)
*/
void buildRecord(char *record, const char *s){
    strcat(record, ",");
    strcat(record, s);
}

/*
    linearSearch: searches through an array for a value using linear search algorithm
    input: the array to be searched (courses), the size of array (courseCount), the flag to indicate
    what is being searched for, the searchKey (searchKey)
    output: the index of the found key in the array, or -1 if not found
*/
int linearSearch(const CourseInfo *courses, size_t courseCount, searchFlag flag, char *searchKey){

    switch(flag){
        case NAME_FLAG:{
            convertToUppercase(searchKey);

            for(size_t i = 0; i < courseCount; i++){
                if (!strcmp(searchKey, courses[i].courseName)) return i;
            }
        }break;
        
        case COURSE_CODE_FLAG:{
            for(size_t i = 0; i < courseCount; i++){
                if (!strcmp(searchKey, courses[i].courseCode)) return i;
            }
        }break;
    }
    
    return NOT_FOUND;
}

/*
    binarySearch: searches through an array for a value using binary search algorithm
    input: the array to be searched (courses), the size of array (courseCount), the searchKey (searchKey)
    output: the index of the found key in the array, or -1 if not found
*/
int binarySearch(const CourseInfo *courses, size_t courseCount, int searchKey){
    int low = 0, high = courseCount - 1;
    
    while(low <= high){
        int middle = (low + high)/2;

        if(courses[middle].courseID == searchKey){
            return middle;
        }
        else if(searchKey < courses[middle].courseID){
            high = middle - 1;
        }
        else{ //(searchKey > courses[middle].courseID){
            low = middle + 1;
        }

        
    }
    
    return NOT_FOUND;
}

/*
    displayCourseInfo: displays the all courses information 
    input: an array of courses to display (courses), the number of courses to display (courseCount)
*/
void displayCourseInfo(const CourseInfo *courses, size_t courseCount){
    printf("%-5s%-20s%-20s%-8s\n", "ID","Name","Code","Term");
    for(size_t i = 0; i < courseCount; i++){
        printf("%-5d%-20s%-20s%-8s\n", courses[i].courseID, courses[i].courseName, courses[i].courseCode, courses[i].term);
    }
}