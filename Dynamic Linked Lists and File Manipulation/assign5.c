/*
    Author: Beesham Sarendranauth, 104854956
    Date: 2017/08/22
    Description: This program maintains a file of students and their course info 
    using concepts of structures, pointers, memory allocation, and file manipulatino.
*/
#include <stdio.h>

//prototypes
void addStudent();
void deleteStudent();
void searchStudentId();
void searchStudentName();
void displayStudentInfo();
void saveStudentInfo();
void loadStudentInfo();
void terminate();

//Course info struct
typedef struct {
    int courseId;
    char courseName[30];
} CourseInfo;

//Student info struct
typedef struct {
    char studentId[10];
    char firstName[21];
    char lastName[26];
    int numOfAttentingCourses;
    CourseInfo courseInfoArr[10];
    struct StudentInfo *next;
} StudentInfo;

int main(void){

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
void loadStudentInfo(){
    
}

/*

*/
void terminate(){
    
}