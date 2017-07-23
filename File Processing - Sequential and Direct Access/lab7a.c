/*
    Author: Beesham Sarendranauth, 104854956
    Date: 2017/07/31
    Description: this program interactively generates employee records storing them in a .dat file
*/
#include <stdio.h>

#define EMP_ARR_SIZE 3

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


int main() {
    Employee EmpList[EMP_ARR_SIZE];
    
    inputEmpRecord(EmpList);
    printEmpList(EmpList);
    
    saveEmpList(EmpList, "employee.dat");
    
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
        fclose(filePtr);
    }    
}