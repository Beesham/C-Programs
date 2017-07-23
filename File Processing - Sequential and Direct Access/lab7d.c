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
int readEmpList(const char *FileName);
void sortRecords(const char *FileName, size_t recordCount);

int main() {
    char *FILENAME = "employeeDA.dat";
    
    int count = readEmpList(FILENAME);
    sortRecords(FILENAME, count);
    readEmpList(FILENAME);
    
    return 0;
}

/*  
    readEmpList: Read employee records from a file and displays it
    input: the file to read from
    return: the number of records read
*/
int readEmpList(const char *FileName){
    FILE *filePtr;
    int count = 0;

    if((filePtr = fopen(FileName, "rb")) == NULL) puts("FILE COULD NOT BE OPENED");
    else{
        Employee emp = {0};
        
        printf("%-4s%-10s%-10s%-4s\n", "ID", "FIRSTNAME", "LASTNAME", "GPA");

        if(fread(&emp, sizeof(Employee), 1, filePtr) == 1)  count++;
        printf("%-4d%-10s%-10s%-4.1f\n", emp.id, emp.firstname, emp.lastname, emp.GPA);

        while(!feof(filePtr)){  
            Employee emp = {0};
            if(fread(&emp, sizeof(Employee), 1, filePtr) == 1){
                count++;
                printf("%-4d%-10s%-10s%-4.1f\n", emp.id, emp.firstname, emp.lastname, emp.GPA);
            }
        }
        fclose(filePtr);
    }
    
    return count;
}

void sortRecords(const char *FileName, size_t recordCount){
    FILE *filePtr;

    if((filePtr = fopen(FileName, "rb+")) == NULL) puts("FILE COULD NOT BE OPENED");
    else{
        for(size_t i = 0; i < recordCount; i++){
            Employee lowestGPAEmp = {0};
            unsigned int positionOfLowestGPA = 0;

            fseek(filePtr, sizeof(Employee) * 0, SEEK_SET);
            fread(&lowestGPAEmp, sizeof(Employee), 1, filePtr);
            fseek(filePtr, sizeof(Employee) * 0, SEEK_SET);
            
            for(size_t j = 0; j < recordCount - i; j++){ 
                Employee curEmp = {0};
                     
                if(fread(&curEmp, sizeof(Employee), 1, filePtr) == 1){
                    if(curEmp.GPA < lowestGPAEmp.GPA){
                        lowestGPAEmp = curEmp;
                        positionOfLowestGPA = j;
                    }
                }
            }
            
            Employee temp = {0};
            if(!fseek(filePtr, sizeof(Employee) * (recordCount - i - 1), SEEK_SET)){
                fread(&temp, sizeof(Employee), 1, filePtr);
            }
            
            if(!fseek(filePtr, sizeof(Employee) * (recordCount - i - 1), SEEK_SET)){
                fwrite(&lowestGPAEmp, sizeof(Employee), 1, filePtr);
            }
            
            if(!fseek(filePtr, sizeof(Employee) * positionOfLowestGPA, SEEK_SET)){
                fwrite(&temp, sizeof(Employee), 1, filePtr);
            }
        }

        fclose(filePtr);
    }
    
    
    
}