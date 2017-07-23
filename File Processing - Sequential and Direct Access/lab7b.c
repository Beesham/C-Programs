/*
    Author: Beesham Sarendranauth, 104854956
    Date: 2017/07/31
    Description: this program interactively generates employee records storing them in a .dat file, and reads
    that file and edits its content to capitalize the names
*/
#include <stdio.h>
#include <ctype.h>

#define EMP_ARR_SIZE 4

struct employee {
    char firstname[40];
    char lastname[40];
    int id;
    float GPA;
};

typedef struct employee Employee;
    
/* Input the employee data interactively from the keyboard */
void inputEmpRecord(Employee *EmpList);
/* Display the contents of Employee records from the list */
void printEmpList(const Employee *EmpList);
/* Save the employee records from the list to the newly created text file specified by FileName */
void saveEmpList(const Employee *EmpList, const char *FileName);
/* Read employee records from a file into an array of stucts */
void readEmpList(Employee *EmpList, const char *FileName);
/* Capitalizes the first letter of the word */
void wordCap(char *word);


int main() {
    Employee EmpList[EMP_ARR_SIZE];
    char *FILENAME = "employee.dat";
    
    //inputEmpRecord(EmpList);
    
    readEmpList(EmpList, FILENAME);
    printEmpList(EmpList);
    saveEmpList(EmpList, FILENAME);
    
    return 0;
}

/*  
    inputEmpRecord: Input the employee data interactively from the keyboard 
    input: the array for the data to be saved in
*/
void inputEmpRecord(Employee *EmpList){
    for(size_t i = 0; i < EMP_ARR_SIZE; i++){
        Employee emp = {0};
        printf("%s", "Please enter an employee record (ID FirstName LastName GPA):\n? ");
        scanf("%d %s %s %f", &(emp.id), emp.firstname, emp.lastname, &(emp.GPA));
        EmpList[i] = emp;
    }
}

/*  
    printEmpList: Display the contents of Employee records from the list 
    input: the array to read from
*/
void printEmpList(const Employee *EmpList){
    
    printf("%-4s%-10s%-10s%-4s\n", "ID", "FIRSTNAME", "LASTNAME", "GPA");
    
    for(size_t i = 0; i < EMP_ARR_SIZE; i++){     
        printf("%-4d%-10s%-10s%-4.1f\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
    }
}

/*  
    saveEmpList: Save the employee records from the list to the newly created text file specified by FileName
    input: the array to read from, the file to write to 
*/
void saveEmpList(const Employee *EmpList, const char *FileName){
    FILE *filePtr;

    if((filePtr = fopen(FileName, "w")) == NULL) puts("FILE COULD NOT BE OPENED");
    else{
        for(size_t i = 0; i < EMP_ARR_SIZE; i++){     
            fprintf(filePtr, "%d %s %s %.1f\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
        }
    }
}

/*  
    readEmpList: Read employee records from a file into an array of stucts 
    input: the array to save to, the file to read from
*/
void readEmpList(Employee *EmpList, const char *FileName){
    FILE *filePtr;

    if((filePtr = fopen(FileName, "r")) == NULL) puts("FILE COULD NOT BE OPENED");
    else{
        int count = 0;
        Employee emp = {0};
        fscanf(filePtr, "%d%s%s%f\n", &(emp.id), emp.firstname, emp.lastname, &(emp.GPA));
        wordCap(emp.firstname);
        wordCap(emp.lastname);
        EmpList[count] = emp;

        while(!feof(filePtr)){  
            count++;
            Employee emp = {0};
            fscanf(filePtr, "%d %s %s %f\n", &(emp.id), emp.firstname, emp.lastname, &(emp.GPA));
            wordCap(emp.firstname);
            wordCap(emp.lastname);
            EmpList[count] = emp;
        }
        fclose(filePtr);
    }
}

/*  
    wordCap: Capitalizes the first letter of the word 
    input: the word to capitalize
*/
void wordCap(char *word){
    *word = toupper(word[0]);
}
