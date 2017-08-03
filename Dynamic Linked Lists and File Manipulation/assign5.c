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
typedef struct courseInfo {
    int courseId;
    char courseName[COURSE_NAME_LEN];
} CourseInfo;

//Student info struct
typedef struct studentInfo {
    char studentId[STUDENT_ID_LEN + 1];
    char firstName[FIRST_NAME_LEN + 1];
    char lastName[LAST_NAME_LEN + 1];
    int numOfAttentingCourses;
    CourseInfo courseInfoArr[MAX_COURSES];
    struct StudentInfo *next;
} StudentInfo;

typedef StudentInfo* StudentInfoPtr;

//prototypes
void addStudent();
void deleteStudent();
void searchStudentId();
void searchStudentName();
void displayStudentInfo(StudentInfoPtr *head);
void saveStudentInfo();
void loadStudentInfo(const char *fileName, StudentInfoPtr *studentInfoPtr);
void terminate();


int main(void){
    
    char *fileName = "studentList.txt";
    StudentInfoPtr studentInfoPtr = NULL;   //Head of list (init no nodes)

    
    loadStudentInfo(fileName, &studentInfoPtr);
    displayStudentInfo(&studentInfoPtr);
    terminate(&studentInfoPtr);
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
    displayStudentInfo: displays the current student information in a linked list
*/
void displayStudentInfo (StudentInfoPtr *head) {
    StudentInfoPtr currentStudentInfoPtr = *head;
    
    if(currentStudentInfoPtr == NULL) puts("List is empty");
    
    while (currentStudentInfoPtr != NULL) {
        printf("%s", currentStudentInfoPtr->firstName);    
        currentStudentInfoPtr = (StudentInfoPtr) currentStudentInfoPtr->next;
    }
}

/*

*/
void saveStudentInfo(){
    
}

/*

*/
void loadStudentInfo (const char *fileName, StudentInfoPtr *startStudentInfoPtr) {
    FILE *filePtr;

    StudentInfoPtr previousStudentInfoPtr = NULL;
    StudentInfoPtr currentStudentInfoPtr = *startStudentInfoPtr;
        
    
    
    if ((filePtr = fopen(fileName, "r")) == NULL) puts("FILE COULD NOT BE OPENED");
    else{
        while (1) {
            StudentInfoPtr newStudentInfoPtr = NULL;    

            //If no space is available return
            if ((newStudentInfoPtr = malloc(sizeof(StudentInfo))) == NULL) {
                puts("Unable to allocate memory");
                break;
            }
            
            //Reads student info
            {
                fscanf(filePtr, "%9s", newStudentInfoPtr->studentId);
                
                //Tests for end of file marker
                if (!strcmp(newStudentInfoPtr->studentId, EOF_MARKER)) {
                    fclose(filePtr);
                    break;
                }
                
                fscanf(filePtr, "%20s", newStudentInfoPtr->firstName);
                fscanf(filePtr, "%25s", newStudentInfoPtr->lastName);
                fscanf(filePtr, "%d", &newStudentInfoPtr->numOfAttentingCourses);
            }
            
            //Reads each course data
            for (int i = 0; i < newStudentInfoPtr->numOfAttentingCourses; i++) {
                fscanf(filePtr, "%29s %d", newStudentInfoPtr->courseInfoArr[i].courseName, &(newStudentInfoPtr->courseInfoArr[i]).courseId);
            }

            printf("%s\n", newStudentInfoPtr->firstName);

            newStudentInfoPtr->next = NULL;
            
            //Loops through the list to find suitable node to insert to
            while (currentStudentInfoPtr != NULL && 
                    strtol(newStudentInfoPtr->studentId, NULL, 10) > strtol(currentStudentInfoPtr->studentId, NULL, 10)) {
                previousStudentInfoPtr = currentStudentInfoPtr;
                currentStudentInfoPtr = (StudentInfoPtr) currentStudentInfoPtr->next;
            }  
            
            if (previousStudentInfoPtr == NULL) {
                newStudentInfoPtr->next = *startStudentInfoPtr;
                *startStudentInfoPtr = newStudentInfoPtr;
            }
            else { 
                previousStudentInfoPtr->next = newStudentInfoPtr;
                newStudentInfoPtr->next = currentStudentInfoPtr;
            }
        }
    }
}

/*
    terminate: free the allocated space used in the linked list
    input: the beginning of the list
*/
void terminate(StudentInfoPtr *head){
    StudentInfoPtr currentStudentInfoPtr = *head;
    StudentInfoPtr hold = NULL;

    if(currentStudentInfoPtr == NULL) puts("List is empty");
    else{
        while (currentStudentInfoPtr != NULL) {
            hold = (StudentInfoPtr) currentStudentInfoPtr->next;
            currentStudentInfoPtr = (StudentInfoPtr) currentStudentInfoPtr->next;
            free(hold);
        }
        
        *head = NULL;
    }
}






































