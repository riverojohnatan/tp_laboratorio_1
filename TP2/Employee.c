/*
 * Employee.c
 *
 *  Created on: May 4, 2021
 *      Author: jrivero
 */

#include "Employee.h"

/**
 * @fn int initEmployees(Employee*, int)
 * @brief To indicate that all position in the array are empty,
 * 	this function put the flag (isEmpty) in TRUE in all position of the array
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list, int len) {
	return 0;
}

/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief add in a existing list of employees the values received as parameters
 * 		in the first empty position
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param salary float
 * @param sector int
 * @return int Return (-1) if Error [Invalid length, NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector) {
	return -1;
}

/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief find an Employee by Id en returns the index position in array.
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param id int
 * @return Return employee index position or (-1) if [Invalid length, NULL pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len,int id) {
	return NULL;
}

/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param id int
 * @return int Return (-1) if Error [Invalid length, NULL pointer or if can't find a employee] - (0) if Ok
 */
int removeEmployee(Employee* list, int len, int id) {
	return -1;
}

/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list, int len, int order) {
	return 0;
}

/**
 * @fn int printEmployees(Employee*, int)
 * @brief print the content of employees array
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printEmployees(Employee* list, int len) {
	return 0;
}
