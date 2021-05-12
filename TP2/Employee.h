#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <stdio.h>
#include <stdlib.h>
#include "InputOutput.h"

#define TRUE 0
#define FALSE 1

struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

int initEmployees(Employee*, int);
int addEmployee(Employee*, int, int, char[], char[], float, int);
int findEmployeeById(Employee*, int, int);
int removeEmployee(Employee*, int, int);
int sortEmployees(Employee*, int, int);
int printEmployees(Employee*, int);

#endif /* EMPLOYEE_H_ */
