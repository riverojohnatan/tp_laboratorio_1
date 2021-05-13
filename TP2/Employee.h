#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InputOutput.h"

#define FALSE 0
#define TRUE 1
#define MAX_STRING_SIZE 51

struct {
	int id;
	char name[MAX_STRING_SIZE];
	char lastName[MAX_STRING_SIZE];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

int initEmployees(Employee*, int);
int createEmployee(Employee*, int);
int editEmployee(Employee *, int);
Employee editEmployeeOne(Employee);
int getEmployeeFreeIndex(Employee* , int);
int getEmployeeIndexByID(Employee *, int, int);
int addEmployee(Employee*, int, int, char[], char[], float, int);
int findEmployeeById(Employee*, int, int);
int removeEmployee(Employee*, int, int);
int sortEmployees(Employee*, int, int);
int printEmployees(Employee*, int);
void showOneEmployee(Employee);
int countCreated(Employee*, int);
void calculateAndShowAverageSalaries(Employee *, int);

#endif /* EMPLOYEE_H_ */
