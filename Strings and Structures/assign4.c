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

typedef struct {
    int courseID;
    char courseName[MAX_COURSE_NAME_LENGTH];
    char courseCode[MAX_COURSE_CODE_LENGTH];
    char term[MAX_TERM_LENGTH];
} CourseInfo;

//prototypes
int loadCourseInfo(CourseInfo *courses);
void addCourseInfo(CourseInfo *courses, int *courseCount);
void searchCourseInfo();
void displayCourseInfo(CourseInfo *courses, size_t courseCount);
void processCourseRecord(char *record, CourseInfo *courseInfo);
void convertToUppercase(char *string);

static int mCourseId = 1;


int main(void){
    
    CourseInfo courses[MAX_COURSES];
    int courseCount = 0;
    
    courseCount = loadCourseInfo(courses);
    displayCourseInfo(courses, courseCount);
    //addCourseInfo(courses, &courseCount);
    
    return 0;
}

/*
    loadCourseInfo: reads data relating to courses from a csv and stores it in an array of CourseInfo
    input: the array to store the data (courses)
    output: the number of records read/ number of courses (courseCount)
*/
int loadCourseInfo(CourseInfo *courses){
        
    char courseRecordBuffer[MAX_LINE_LENGTH];
    int courseCount = 0;
    
    while(fgets(courseRecordBuffer, MAX_LINE_LENGTH, stdin) != NULL){
        CourseInfo ci = {0};
        processCourseRecord(courseRecordBuffer, &ci);
        courses[courseCount++] = ci;
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

void convertToUppercase(char *string){
    while(*string != '\0'){
        *string = toupper(*string);
        string++;
    }    
}

/*

*/
void addCourseInfo(CourseInfo *courses, int *courseCount){
    int index = (*courseCount) - 1;
    printf("%s", "Please enter course info as [Name, Code(XXXX-XXX-XX), Term(TYYYY)]");
    scanf("%s %s %s", courses[index].courseName, courses[index].courseCode, courses[index].term);
    courses[index].courseID = mCourseId++;
    (*courseCount)++;
}

/*

*/
void searchCourseInfo(){
    
}

/*
    displayCourseInfo: displays the all courses information 
    input: an array of courses to display (courses), the number of courses to display (courseCount)
*/
void displayCourseInfo(CourseInfo *courses, size_t courseCount){
    printf("%-5s%-20s%-20s%-8s\n", "ID","Name","Code","Term");
    for(size_t i = 0; i < courseCount; i++){
        printf("%-5d%-20s%-20s%-8s\n", courses[i].courseID, courses[i].courseName, courses[i].courseCode, courses[i].term);
    }
}