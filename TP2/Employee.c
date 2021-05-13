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
	int response = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = TRUE;
		}
		response = 0;
	}

	return response;
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
	int response = -1;
	Employee aux;

	int index = getEmployeeFreeIndex(list, len);

	if (index != -1) {
		aux.id = id;
		strcpy(aux.name, name);
		strcpy(aux.lastName, lastName);
		aux.salary = salary;
		aux.sector = sector;
		aux.isEmpty = FALSE;
		list[index] = aux;

		response = 0;
	}

	return response;
}

/**
 * @fn int editEmployee(Employee*, int)
 * @brief Ask Id and data to edit employee
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return Return (-1) if [Invalid length, NULL pointer received or list is full] or 0 if OK
 */
int editEmployee(Employee * list, int len) {
	int response = -1;
	int idEmployee;
	int index;
	int flag = 0;
	int tries = 3;
	Employee aux;

	if (printEmployees(list, len) != -1) {
		flag = 1;
	}

	if (flag) {
		GetInt(&idEmployee, "Ingrese Id del empleado a modificar: ", "Ingreso erroneo");

		index = findEmployeeById(list, len, idEmployee);
		while (index == -1 && tries > 0) {
			puts("NO EXISTE ID.");
			GetInt(&idEmployee, "Ingrese Id del trabajo a modificar: ", "Ingreso erroneo");
			index = findEmployeeById(list, len, idEmployee);
			tries--;
		}

		if (tries > 0) {
			aux = editEmployeeOne(list[index]);

			if(ValidateAction("Estas seguro de querer modificar ese ID? SI (s) NO (n)\n") == 0) {
				list[index] = aux;
				response = 0;
			}
		}
	}

	return response;
}


Employee editEmployeeOne(Employee employee) {
	Employee aux = employee;
	int validAction;

	printf("Nombre: %s\n", employee.name);
	if(ValidateAction("¿Desea modificar el nombre? SI (s) NO (n)\n") == 0) {
		GetString(aux.name, MAX_STRING_SIZE, "", "Ingreso erroneo");
	} else {
		puts("Nombre sin modificar");
	}

	printf("Apellido: %s\n", employee.lastName);
	if(ValidateAction("¿Desea modificar el apellido? SI (s) NO (n)\n") == 0) {
		GetString(aux.lastName, MAX_STRING_SIZE, "", "Ingreso erroneo");
	} else {
		puts("Apellido sin modificar");
	}

	printf("Salario: %.2f\n", employee.salary);
	if(ValidateAction("¿Desea modificar el salario? SI (s) NO (n)\n") == 0) {
		GetFloat(&aux.salary, "", "Ingreso erroneo");
	} else {
		puts("Salario sin modificar");
	}

	printf("Sector: %d\n", employee.sector);
	if(ValidateAction("¿Desea modificar el sector? SI (s) NO (n)\n") == 0) {
		GetInt(&aux.sector, "", "Ingreso erroneo");
	} else {
		puts("Sector sin modificar");
	}

	return aux;
}

/**
 * @fn int getEmployeeFreeIndex(Employee*, int)
 * @brief find an empty index
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return Return (-1) if [Invalid length, NULL pointer received or list is full] or free index
 */
int getEmployeeFreeIndex(Employee * list, int len) {
	int response = -1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == TRUE) {
				response = i;
				break;
			}
		}
	}

	return response;
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
	int response = -1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == FALSE) {
				response = i;
				break;
			}
		}
	}

	return response;
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
	int response = -1;
	int index;

	index = findEmployeeById(list, len, id);

	if (index != -1) {
		list[index].isEmpty = TRUE;
		response = 0;
	}

	return response;
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
	int response = 0;
	int i;
	int j;
	Employee aux;

	if (list != NULL && len > 0) {
		for (i = 0; i < len - 1; i++) {
			for (j = i + 1; j < len; j++) {
				if (list[i].isEmpty == FALSE
						&& list[j].isEmpty == FALSE) {
					if(order == 1) {
						if (strcmp(list[i].lastName, list[i].lastName) > 0) {
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					} else {
						if (strcmp(list[i].lastName, list[i].lastName) < 0) {
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
		response = 1;
	}
	return response;
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
	int response = -1;

	if (countCreated(list, len) > 0) {
		puts("\n\t> LISTADO Trabajo");
		printf("%5s - %5s - %5s - %5s - %5s\n\n", "ID", "MARCA", "RODADO", "SERVICIO", "FECHA");

		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				showOneEmployee(list[i]);
			}
		}
		response = 0;
	}

	return response;

}

/**
 * @fn int countCreated(Employee*, int)
 * @brief how many created employees are
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Return (0) if it's empty
 */
int countCreated(Employee* list, int len) {
	int count=0;

	if (list != NULL && len > 0) {
		for(int i=0; i<len; i++) {
			if(list[i].isEmpty == FALSE) {
				count++;
			}
		}
	}
	return count;
}


/**
 * @fn void showOneEmployee(Employee)
 * @brief print an employee data
 *
 * @param employee Employee
 */
void showOneEmployee(Employee employee) {
	printf("%d - %s - %s - %.2f - %d\n",
			employee.id,
			employee.name,
			employee.lastName,
			employee.salary,
			employee.sector);
}

/**
 * @fn void calculateAndShowSalaries(Employee*, int)
 * @brief
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 */
void calculateAndShowAverageSalaries(Employee * list, int len) {
	int count=0;
	int employeeBeyondAverageCount = 0;
	float salariesCount = 0;
	float averageSalary;

	for(int i=0; i<len; i++) {
		if(list[i].isEmpty == FALSE) {
			salariesCount+= list[i].salary;
			count++;
		}
	}

	averageSalary = salariesCount / count;
	for(int i=0; i<len; i++) {
		if(list[i].isEmpty == FALSE && list[i].salary > averageSalary) {
			employeeBeyondAverageCount++;
		}
	}

	printf("Total de salarios: %.2f\n", salariesCount);
	printf("Promedio de salarios: %.2f\n", averageSalary);
	printf("%d Empleados superan el promedio\n", employeeBeyondAverageCount);
}
