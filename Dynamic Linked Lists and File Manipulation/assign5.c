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
StudentInfoPtr searchStudentId(StudentInfoPtr *head, const char *studentId);
StudentInfoPtr searchStudentName(StudentInfoPtr *head, const char *studentLastName);
void displayStudentInfo(StudentInfoPtr *head);
void saveStudentInfo();
void loadStudentInfo(const char *fileName, StudentInfoPtr *studentInfoPtr);
void terminate();
void formatName(char *string);

//TODO: validate studnetID uniqueness
//TODO: sort students by ID

int main(void){
    
    char *fileName = "studentList.txt";
    StudentInfoPtr studentInfoPtr = NULL;   //Head of list (init no nodes)

    
    loadStudentInfo (fileName, &studentInfoPtr);
    //displayStudentInfo (&studentInfoPtr);
    //addStudent (&studentInfoPtr);
    displayStudentInfo (&studentInfoPtr);
    StudentInfoPtr stu = searchStudentId(&studentInfoPtr, "111111111");
    if(stu != NULL) printf("%s", stu->firstName);
    
    StudentInfoPtr stu2 = searchStudentName(&studentInfoPtr, "Porter");
    if(stu2 != NULL) printf("%s", stu2->lastName);
    
    terminate (&studentInfoPtr);
}

/*
    addStudent: adds a student to the linked list
    input: the beginning of the linked list
*/
void addStudent(StudentInfoPtr *head) {
    
    StudentInfoPtr previousStudentInfoPtr = NULL;
    StudentInfoPtr currentStudentInfoPtr = *head;
    
    StudentInfoPtr newStudentInfoPtr = NULL;    

    //If no space is available return
    if ((newStudentInfoPtr = malloc(sizeof(StudentInfo))) == NULL) {
        puts("Unable to allocate memory");
        return;
    }
    
    //Reads student info
    {
        printf("%s", "Student ID (9 digits): ");
        scanf("%9s", newStudentInfoPtr->studentId);
        
        printf("%s", "Student first name (20 characters max): ");
        scanf("%20s", newStudentInfoPtr->firstName);
        
        printf("%s", "Student last name (25 characters max): ");
        scanf("%25s", newStudentInfoPtr->lastName);
        
        formatName(newStudentInfoPtr->firstName);
        formatName(newStudentInfoPtr->lastName);
        
        printf("%s", "How many courses is the student attending: ");
        scanf("%d", &newStudentInfoPtr->numOfAttentingCourses);
    }
    
    //Reads each course data
    for (int i = 0; i < newStudentInfoPtr->numOfAttentingCourses; i++) {
        printf("%s", "Enter course info as CODE NUMBER e.g MATH 101: ");
        scanf("%29s %d", newStudentInfoPtr->courseInfoArr[i].courseName, &(newStudentInfoPtr->courseInfoArr[i]).courseId);
    }

    newStudentInfoPtr->next = NULL;
    
    //Loops through the list to find suitable node to insert to
    while (currentStudentInfoPtr != NULL && 
            strtol(newStudentInfoPtr->studentId, NULL, 10) > strtol(currentStudentInfoPtr->studentId, NULL, 10)) {
        previousStudentInfoPtr = currentStudentInfoPtr;
        currentStudentInfoPtr = (StudentInfoPtr) currentStudentInfoPtr->next;
    }  
    
    if (previousStudentInfoPtr == NULL) {
        newStudentInfoPtr->next = *head;
        *head = newStudentInfoPtr;
    }
    else { 
        previousStudentInfoPtr->next = newStudentInfoPtr;
        newStudentInfoPtr->next = currentStudentInfoPtr;
    }

}

/*

*/
void deleteStudent() {
    
}

/*
    searchStudentId: searches the linked list for a student by id
    input: the beginning of the linked list (head), the id to be searched (studentId)
    output: the found student or NULL if not found
*/
StudentInfoPtr searchStudentId(StudentInfoPtr *head, const char *studentId) {
    
    StudentInfoPtr currentStudentInfoPtr = *head;
    
    while (currentStudentInfoPtr != NULL) {
        if(!strcmp(currentStudentInfoPtr->studentId, studentId)){
            return currentStudentInfoPtr;
        }
        currentStudentInfoPtr = (StudentInfoPtr) currentStudentInfoPtr->next;
    }  
    
    return NULL;
}

/*
    searchStudentName: searches the linked list for a student by last name
    input: the beginning of the linked list (head), the last name of student to be searched (studentLastName)
    output: the found student or NULL if not found
*/
StudentInfoPtr searchStudentName(StudentInfoPtr *head, const char *studentLastName) {
    
    StudentInfoPtr currentStudentInfoPtr = *head;
    
    while (currentStudentInfoPtr != NULL) {
        if(!strcmp(currentStudentInfoPtr->lastName, studentLastName)){
            return currentStudentInfoPtr;
        }
        currentStudentInfoPtr = (StudentInfoPtr) currentStudentInfoPtr->next;
    }  
    
    return NULL;
}

/*
    displayStudentInfo: displays each student information in a linked list
    input: the beginning of the linked list (head)
*/
void displayStudentInfo(StudentInfoPtr *head) {
    
    StudentInfoPtr currentStudentInfoPtr = *head;
    
    if(currentStudentInfoPtr == NULL) puts("List is empty");
    
    int count = 1;
    
    //Prints each student info
    while (currentStudentInfoPtr != NULL) {
        puts("");
        printf("%s %d\n", "Student: ", count++);
        printf("%s\n", currentStudentInfoPtr->studentId);   
        printf("%s\n", currentStudentInfoPtr->firstName);   
        printf("%s\n", currentStudentInfoPtr->lastName);    
        printf("%d\n", currentStudentInfoPtr->numOfAttentingCourses);    

        for (int i = 0; i < currentStudentInfoPtr->numOfAttentingCourses; i++) {
            printf("%s %d\n", currentStudentInfoPtr->courseInfoArr[i].courseName, currentStudentInfoPtr->courseInfoArr[i].courseId);
        }
        
        currentStudentInfoPtr = (StudentInfoPtr) currentStudentInfoPtr->next;
    }
}

/*

*/
void saveStudentInfo() {
    
}

/*

*/
void loadStudentInfo(const char *fileName, StudentInfoPtr *startStudentInfoPtr) {
    
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
                
                formatName(newStudentInfoPtr->firstName);
                formatName(newStudentInfoPtr->lastName);
               
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
    input: the beginning of the list (head)
*/
void terminate(StudentInfoPtr *head){
    
    StudentInfoPtr currentStudentInfoPtr = *head;
    StudentInfoPtr hold = NULL;

    //de-allocates memory used
    while (currentStudentInfoPtr != NULL) {
        hold = (StudentInfoPtr) currentStudentInfoPtr->next;
        currentStudentInfoPtr = (StudentInfoPtr) currentStudentInfoPtr->next;
        free(hold);
    }
    
    *head = NULL;
}

/*
    formatName: converts a string to have the first letter uppercase
    input: the string to convert (string)
*/
void formatName(char *string){
    
    char *temp = string;
    
    while(*temp != '\0'){
        *temp = tolower(*temp);
        temp++;
    }    
    
    *string = toupper(*string);
    
}




































