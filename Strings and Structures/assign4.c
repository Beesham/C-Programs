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
void loadCourseInfo(CourseInfo *courses);
void addCourseInfo();
void searchCourseInfo();
void displayCourseInfo();
CourseInfo* processCourseRecord(char *record, CourseInfo *courseInfo);
void convertToUppercase(char *string);

int main(void){
    
    CourseInfo courses[MAX_COURSES];
    
    loadCourseInfo(courses);
}

/*
    loadCourseInfo: reads data relating to courses from a csv and stores it in an array of CourseInfo
    input: the array to store the data (courses)
*/
void loadCourseInfo(CourseInfo *courses){
        
    char courseRecordBuffer[MAX_LINE_LENGTH];
    
    while(fgets(courseRecordBuffer, MAX_LINE_LENGTH, stdin) != NULL){
        printf("%s", courseRecordBuffer);
        CourseInfo ci = {0};
        processCourseRecord(courseRecordBuffer, &ci);
    }
    
}

CourseInfo* processCourseRecord(char *record, CourseInfo *courseInfo){
    
    int recordLength = strlen(record);
    char *strTokPtr;
    int index = 1;
    
    strTokPtr = strtok(record, ",");
    
    while(strTokPtr != NULL){
                printf("token: %s\n", strTokPtr);
        
        switch(index){
            
            case COURSENAMEINDEX:{
                convertToUppercase(strTokPtr);
                strcpy(courseInfo->courseName, strTokPtr);
            }
            break;
            
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
                printf("course code : %s\n", courseInfo->courseCode);   
            }
            break;
            
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
                printf("term code : %s\n", courseInfo->term);   

            }
            break;
        }
        
        index++;
        
        strTokPtr = strtok(NULL, ",");
    }
    
    
    return courseInfo;
}

void convertToUppercase(char *string){
    while(*string++ != '\0'){
        *string = toupper(*string);
    }    
}

/*

*/
void addCourseInfo(){
    
}

/*

*/
void searchCourseInfo(){
    
}

/*

*/
void displayCourseInfo(){
    
}