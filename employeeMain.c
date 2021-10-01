#include <string.h>
#include <stdlib.h>
#include "employee.h"

//In order to run must compile: employeeMain.c employeeTable.c employeeTwo.c
int main (void){
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;
    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByNumber (EmployeeTable, EmployeeTableEntries, 1045);
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
        if (matchPtr != NULL)
            printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
        else
            printf("Employee Tony Bobcat is NOT found in the record\n");
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-1235" );
        if (matchPtr != NULL)
            printf("Tony's number was found");
        else
            printf("Tony's number was not found");
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34 );
        if (matchPtr != NULL)
            printf("Employee salary 6.34 is in record %d\n", matchPtr-EmployeeTable);
        else 
            printf("Employee salary is NOT found within the record");
return 0;
}