/*
    Author: Beesham Sarendranauth, 104854956
    Date: 2017/08/22
    Description: This program maintains a file of students and their course info 
    using concepts of structures, pointers, memory allocation, and file manipulatino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STUDENT_ID_LEN 9
#define FIRST_NAME_LEN 20
#define LAST_NAME_LEN 25
#define COURSE_NAME_LEN 30
#define MAX_COURSES 10

#define EOF_MARKER "***"

//Course info struct
typedef struct {
    int courseId;
    char courseName[COURSE_NAME_LEN];
} CourseInfo;

//Student info struct
typedef struct {
    char studentId[STUDENT_ID_LEN + 1];
    char firstName[FIRST_NAME_LEN + 1];
    char lastName[LAST_NAME_LEN + 1];
    int numOfAttentingCourses;
    CourseInfo courseInfoArr[MAX_COURSES];
    struct StudentInfo *next;
} StudentInfo;


//prototypes
void addStudent();
void deleteStudent();
void searchStudentId();
void searchStudentName();
void displayStudentInfo();
void saveStudentInfo();
void loadStudentInfo(const char *fileName, StudentInfo *studentInfoPtr);
void terminate();


int main(void){
    
    char *fileName = "studentList.txt";
    StudentInfo *studentInfoPtr = NULL;

    
    loadStudentInfo(fileName, studentInfoPtr);
}

/*

*/
void addStudent(){

}

/*

*/
void deleteStudent(){
    
}

/*

*/
void searchStudentId(){
    
}

/*

*/
void searchStudentName(){
    
}

/*

*/
void displayStudentInfo(){
    
}

/*

*/
void saveStudentInfo(){
    
}

/*

*/
void loadStudentInfo(const char *fileName, StudentInfo *startStudentInfoPtr){
    FILE *filePtr;

    StudentInfo *newStudentInfoPtr = NULL;
    
    if((newStudentInfoPtr = malloc(sizeof(StudentInfo))) == NULL){
        puts("Unable to allocate memory");
        return;
    }
    
    StudentInfo *previousStudentInfoPtr;
    StudentInfo *currentStudentInfoPtr = startStudentInfoPtr;

    
    studentInfoPtr->next = NULL;
    //studentInfo->courseInfoArr = malloc(sizeof(StudentInfo))
    
    
    if((filePtr = fopen(fileName, "r")) == NULL) puts("FILE COULD NOT BE OPENED");
    else{
        while(1){
            fscanf(filePtr, "%9s", newStudentInfoPtr->studentId);
            if(!strcmp(newStudentInfoPtr->studentId, EOF_MARKER)){
                fclose(filePtr);
                break;
            }
            fscanf(filePtr, "%20s", newStudentInfoPtr->firstName);
            fscanf(filePtr, "%25s", newStudentInfoPtr->lastName);
            fscanf(filePtr, "%d", &newStudentInfoPtr->numOfAttentingCourses);
            
            for(int i = 0; i < newStudentInfoPtr->numOfAttentingCourses; i++){
                fscanf(filePtr, "%29s %d", newStudentInfoPtr->courseInfoArr[i].courseName, &(newStudentInfoPtr->courseInfoArr[i]).courseId);
                printf("%s %d\n", newStudentInfoPtr->courseInfoArr[i].courseName, (newStudentInfoPtr->courseInfoArr[i].courseId));
            }
            
            

        }

    }
}

/*

*/
void terminate(){
    
}

