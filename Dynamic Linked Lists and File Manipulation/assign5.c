/*
    Author: Beesham Sarendranauth, 104854956
    Date: 2017/08/22
    Description: This program maintains a file of students and their course info 
    using concepts of structures, pointers, memory allocation, and file manipulation.
    *Note: the output file can be read with a sophisticated text editor such as Notepad++ 
    for better human readability
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

#define FLAG_DISP_ALL 0
#define FLAG_DISP 1

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
    struct studentInfo *next;
} StudentInfo;

typedef StudentInfo* StudentInfoPtr;

enum choice{
    ADD = 1, DELETE, DISPLAY, SEARCH, SAVE, EXIT
};

//prototypes
void addStudent(StudentInfoPtr *head, StudentInfoPtr student);
void deleteStudent(StudentInfoPtr *head, const char *studentId);
StudentInfoPtr searchStudentId(StudentInfoPtr *head, const char *studentId);
StudentInfoPtr searchStudentName(StudentInfoPtr *head, const char *studentLastName);
void displayStudentInfo(StudentInfoPtr *head, int FLAG, StudentInfoPtr studentInfo);
void saveStudentInfo(StudentInfoPtr *head);
void loadStudentInfo(const char *fileName, StudentInfoPtr *studentInfoPtr);
void terminate(StudentInfoPtr *head);
void formatName(char *string);
void convertToUppercase(char *string);
StudentInfoPtr promptForStudentInfo();
int menu();


int main(void){
    
    char *fileName = "studentList.txt";
    StudentInfoPtr studentInfoPtr = NULL;   //Head of list (init no nodes)

    loadStudentInfo(fileName, &studentInfoPtr);
            
    int choice;
    
    while((choice = menu()) != EXIT) {
        switch(choice) {
            case ADD: {
                addStudent (&studentInfoPtr, promptForStudentInfo());
                break;
            }
            
            case DELETE: {
                char input[STUDENT_ID_LEN + 1];
                printf("%s", "Please enter student id to delete: ");
                scanf("%9s", input);
                if(input != NULL) deleteStudent(&studentInfoPtr, input);
                break;
            }          
            
            case DISPLAY: {
                displayStudentInfo(&studentInfoPtr, FLAG_DISP_ALL, NULL);
                break;          
            }
            
            case SEARCH: {
                char input[LAST_NAME_LEN + 1];
                printf("%s", "Please enter student id or last name to search: ");
                scanf("%s", input);
                
                //Validates the input from the user for either id or name
                {
                    char *strLeftovers = NULL;
                    long ret;
                    ret = strtol(input, &strLeftovers, 10);
                                    
                    if(ret > 0 && strlen(strLeftovers) != 0) {
                        puts("INVALID STUDENT INFORMATION!");
                    }
                    else if(ret > 0 && strlen(strLeftovers) == 0) {
                    
                        if(input != NULL && strlen(input) == STUDENT_ID_LEN) {
                            StudentInfoPtr ptr = searchStudentId(&studentInfoPtr, input);
                            if(ptr != NULL) displayStudentInfo(NULL, FLAG_DISP, ptr);
                            else puts("NO STUDENT INFORMATION!!");                        
                        }
                        else puts("INVALID STUDENT INFORMATION!!");
                    }
                    else if(ret == 0 && strlen(strLeftovers) != 0){
                    
                        if(input != NULL && strlen(input) <= LAST_NAME_LEN) {
                            formatName(input);
                            StudentInfoPtr ptr = searchStudentName(&studentInfoPtr, input);
                            if(ptr != NULL) displayStudentInfo(NULL, FLAG_DISP, ptr);    
                            else puts("NO STUDENT INFORMATION!!!");                          
                        }
                        else puts("INVALID STUDENT INFORMATION!!!");
                    }
                }
                break;               
            }
            
            case SAVE: {
                saveStudentInfo(&studentInfoPtr);
                break;               
            }
            
            default: puts("UNSUPPORTED ACTION!!");
        }        
    }
    
    terminate (&studentInfoPtr);

    return 0;
}

/*
    menu: displays a menu and prompt to the user
    output: the choice made by user
*/
int menu(){
    
    char choiceStr[2];
    int choice = 0;
    
    puts("");
    puts("1. Add Student");
    puts("2. Delete Student");
    puts("3. Display Students");
    puts("4. Search Student");
    puts("5. Save");
    puts("6. Exit");
    
    printf("%s", "Choice: ");
    scanf("%1s", choiceStr);
    getchar();
    
    choice = strtol(choiceStr, NULL, 10);
    
    return (int) choice;
}

/*
    promptForStudentInfo: prompts the user for a students info and stores it in a struct
    output: a pointer to the struct in memory
*/
StudentInfoPtr promptForStudentInfo() {
    
    StudentInfoPtr newStudentInfoPtr = NULL;    
    
    //If no space is available return
    if ((newStudentInfoPtr = malloc(sizeof(StudentInfo))) == NULL) {
        puts("Unable to allocate memory");
        return NULL;
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
        convertToUppercase(newStudentInfoPtr->courseInfoArr[i].courseName);
    }

    newStudentInfoPtr->next = NULL;
    
    return newStudentInfoPtr;
}

/*
    addStudent: adds a student to the linked list
    input: the beginning of the linked list
*/
void addStudent(StudentInfoPtr *head, StudentInfoPtr student) {
    
    StudentInfoPtr previousStudentInfoPtr = NULL;
    StudentInfoPtr currentStudentInfoPtr = *head;
    
    StudentInfoPtr newStudentInfoPtr = student;    

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
    deleteStudent: deletes a student from the linked list by id
    input: the beginning of the linked list (head), the id to be deleted (studentId)
    output:
*/
void deleteStudent(StudentInfoPtr *head, const char *studentId) {

    StudentInfoPtr currentStudentInfoPtr = *head;
    StudentInfoPtr previousStudentInfoPtr = NULL;
    
    if(!strcmp(currentStudentInfoPtr->studentId, studentId)){
        StudentInfoPtr hold = currentStudentInfoPtr;
        *head = currentStudentInfoPtr->next;
        free(hold);
    }
    else {  
        
        previousStudentInfoPtr = currentStudentInfoPtr;
        currentStudentInfoPtr = (StudentInfoPtr) currentStudentInfoPtr->next;        
        
        while(currentStudentInfoPtr != NULL) {
            if(!strcmp(currentStudentInfoPtr->studentId, studentId)) {
                break;
            }  
            
            previousStudentInfoPtr = currentStudentInfoPtr;
            currentStudentInfoPtr = (StudentInfoPtr) currentStudentInfoPtr->next;     
        }  
        
        StudentInfoPtr hold = currentStudentInfoPtr;
        previousStudentInfoPtr->next = currentStudentInfoPtr->next;
        currentStudentInfoPtr = currentStudentInfoPtr->next;
        free(hold);
    }
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
void displayStudentInfo(StudentInfoPtr *head, int FLAG, StudentInfoPtr studentInfoPtr) {
    
    StudentInfoPtr currentStudentInfoPtr = NULL;
    
    switch(FLAG) {
        
        case(FLAG_DISP_ALL): {
            currentStudentInfoPtr = *head;
        }
        break;
        
        case(FLAG_DISP): {
            if(studentInfoPtr != NULL) {
                StudentInfo studentInfoCopy = *studentInfoPtr;
                currentStudentInfoPtr = &studentInfoCopy;
                currentStudentInfoPtr->next = NULL;
            }
        }
        break;
    }
    
    if(currentStudentInfoPtr == NULL) puts("No data!");
    
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
    saveStudentInfo: saves the linked list to a file
    input: the beginning of the linked list (head)
*/
void saveStudentInfo(StudentInfoPtr *head) {
    
    char *fileName = "inputStudents.txt";
    FILE *filePtr = NULL;
    
    if((filePtr = fopen(fileName, "w")) == NULL) {
        puts("ERR IN SAVING TO FILE | FILE COULD NOT BE OPENED");
    }
    else {
        
        StudentInfoPtr currentStudentInfoPtr = *head;
        
        //writes the student infos to a file
        while(currentStudentInfoPtr != NULL) {
            
            fprintf(filePtr, "%s\n%s\n%s\n%d\n", 
                                currentStudentInfoPtr->studentId,
                                currentStudentInfoPtr->firstName,
                                currentStudentInfoPtr->lastName,
                                currentStudentInfoPtr->numOfAttentingCourses);
                                
            for(int i = 0; i < currentStudentInfoPtr->numOfAttentingCourses; i++){
                fprintf(filePtr, "%s %d\n", currentStudentInfoPtr->courseInfoArr[i].courseName, currentStudentInfoPtr->courseInfoArr[i].courseId);
            }            
            currentStudentInfoPtr = currentStudentInfoPtr->next;
        }
        
        fclose(filePtr);
    }
}

/*
    loadStudentInfo: reads student info from a sorted text file into a linked list
    input: the file name (fileName), the beginning of the linked list (startStudentInfoPtr)
*/
void loadStudentInfo(const char *fileName, StudentInfoPtr *startStudentInfoPtr) {
    
    FILE *filePtr;        
     
    if ((filePtr = fopen(fileName, "r")) == NULL) puts("FILE COULD NOT BE OPENED");
    else {
        while(1) {
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
                convertToUppercase(newStudentInfoPtr->courseInfoArr[i].courseName);
            }
                        
            newStudentInfoPtr->next = NULL;
            
            if(searchStudentId(startStudentInfoPtr, newStudentInfoPtr->studentId) == NULL) {               
                addStudent(startStudentInfoPtr, newStudentInfoPtr);
            }
            else printf("%s %s", "Duplicate student ID: ", newStudentInfoPtr->studentId);
        }
        
        fclose(filePtr);
    }
}

/*
    terminate: free the allocated space used in the linked list
    input: the beginning of the list (head)
*/
void terminate(StudentInfoPtr *head) {
    
    printf("%s", "Save students to file before exiting (Y/N) ? ");
    
    char decision;
    scanf("%c", &decision);
    
    if(decision == 'y' || decision == 'Y') {
        saveStudentInfo(head);
        puts("Students saved!");
    }
    
    StudentInfoPtr currentStudentInfoPtr = *head;
    StudentInfoPtr hold = NULL;

    //de-allocates memory used
    while (currentStudentInfoPtr != NULL) {
        hold = (StudentInfoPtr) currentStudentInfoPtr->next;
        currentStudentInfoPtr = (StudentInfoPtr) currentStudentInfoPtr->next;
        free(hold);
    }
    
    *head = NULL;
    
    puts("Exiting...");
}

/*
    formatName: converts a string to have the first letter upper-case
    input: the string to convert (string)
*/
void formatName(char *string) {
    
    char *temp = string;
    
    while(*temp != '\0'){
        *temp = tolower(*temp);
        temp++;
    }    
    
    *string = toupper(*string);
}

/*
    convertToUppercase: converts a string to all uppercase
    input: the string to convert (string)
*/
void convertToUppercase(char *string) {
    
    while(*string != '\0'){
        *string = toupper(*string);
        string++;
    }    
}



































