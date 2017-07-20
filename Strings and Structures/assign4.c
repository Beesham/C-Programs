/*
	Author: Beesham Sarendranauth, 104854956
	Date: 2017/07/27
	Description: This program processes a comma separated values (csv) file. New data can be added,
    searched, or displayed.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_COURSES 10
#define MAX_COURSE_NAME_LENGTH 50
#define MAX_COURSE_CODE_LENGTH 12
#define MAX_TERM_LENGTH 6



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