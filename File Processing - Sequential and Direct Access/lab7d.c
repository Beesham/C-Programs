/*
    Author: Beesham Sarendranauth, 104854956
    Date: 2017/07/31
    Description: this program sorts the data in a .dat file
*/
#include <stdio.h>

struct employee {
    char firstname[40];
    char lastname[40];
    int id;
    float GPA;
};

typedef struct employee Employee;
    
/* Save the employee records from the list to the newly created text file specified by FileName */
void saveEmpList(const Employee *EmpList, const char *FileName);
void readEmpList(const char *FileName);

int main() {
    char *FILENAME = "employeeDA.dat";
    
    readEmpList(FILENAME);
    
    return 0;
}

/*  
    readEmpList: Read employee records from a file and displays it
    input: the file to read from
*/
void readEmpList(const char *FileName){
    FILE *filePtr;

    if((filePtr = fopen(FileName, "rb")) == NULL) puts("FILE COULD NOT BE OPENED");
    else{
        int count = 0;
        Employee emp = {0};
        
        printf("%-4s%-10s%-10s%-4s\n", "ID", "FIRSTNAME", "LASTNAME", "GPA");

        fscanf(filePtr, "%d%s%s%f\n", &(emp.id), emp.firstname, emp.lastname, &(emp.GPA));
        printf("%-4d%-10s%-10s%-4.1f\n", emp.id, emp.firstname, emp.lastname, emp.GPA);

        while(!feof(filePtr)){  
            count++;
            Employee emp = {0};
            fread(&emp, sizeof(Employee), 1, filePtr);
            printf("%-4d%-10s%-10s%-4.1f\n", emp.id, emp.firstname, emp.lastname, emp.GPA);
        }
        fclose(filePtr);
    }
}
