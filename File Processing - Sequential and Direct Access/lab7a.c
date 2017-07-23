/*
    Author: Beesham Sarendranauth, 104854956
    Date: 2017/07/31
    Description: this program interactively generates employee records storing them in a .dat file
*/
#include <stdio.h>

struct employee {
    char firstname[40];
    char lastname[40];
    int id;
    int GPA;
};

typedef struct employee Employee;
    
/* Input the employee data interactively from the keyboard */
void InputEmpRecord(Employee *EmpList);
/* Display the contents of Employee records from the list */
void PrintEmpList(const Employee *EmpList);
/* Save the employee records from the list to the newly created text file specified by FileName */
void SaveEmpList(const Employee *EmpList, const char *FileName);


int main() {
    Employee EmpList[3];
    
    InputEmpRecord(EmpList);
    PrintEmpList(EmpList);
    SaveEmpList(EmpList, "employee.dat");
    
    return 0;
}