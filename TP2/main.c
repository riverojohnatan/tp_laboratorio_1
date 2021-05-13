/*
	Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
	dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
	Datos:
		Employee:
			int id
			char name[51]
			char lastName[51]
			float salary
			int sector
			int isEmpty

	El sistema deberá tener el siguiente menú de opciones:
		1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
			de Id. El resto de los campos se le pedirá al usuario.
		2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
			o Salario o Sector
		3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
		4. INFORMAR:
			1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
			2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

	NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
	Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
	carga de algún empleado.

	Para la realización de este programa, se utilizará una biblioteca llamada “ArrayEmployees” que
	facilitará el manejo de la lista de empleados y su modificación. En la sección siguiente se
	detallan las funciones que esta biblioteca debe tener.

	Rivero, Johnatan
 */

#include "Employee.h"

#define TAM_ESTRUCTURA 1000

int main(void) {
	setbuf(stdout, NULL);

	int opc;
	int listOpc;
	int id = 0;
	int idEmployee;
	int tries = 3;
	int index;
	Employee employees[TAM_ESTRUCTURA];
	Employee employee;

	int test;

	initEmployees(employees, TAM_ESTRUCTURA);

	do {
		puts("INGRESE OPCION:");
		puts("1- Alta Empleado");
		puts("2- Modificar Empleado");
		puts("3- Baja Empleado");
		puts("4- Informes");
		puts("\n0- Salir");
		scanf("%d", &opc);

		switch (opc) {
			case 1:
				if (getEmployeeFreeIndex(employees, TAM_ESTRUCTURA) > -1) {
					if(GetString(employee.name, MAX_STRING_SIZE, "Ingresar nombre: ", "Ingreso erroneo") == 0 &&
						GetString(employee.lastName, MAX_STRING_SIZE, "Ingresar apellido: ", "Ingreso erroneo") == 0 &&
						GetFloat(&employee.salary, "Ingresar salario: ", "Ingreso erroneo") == 0 &&
						GetInt(&employee.sector, "Ingresar número de sector: ", "Ingreso erroneo") == 0 &&
						addEmployee(employees, TAM_ESTRUCTURA, id, employee.name, employee.lastName,
								employee.salary, employee.sector) > -1) {
						puts(" * Empleado DADO DE ALTA EXITOSAMENTE");
						id++;
					} else {
						puts(" * ERROR Al ingresar Empleado * ");
					}
				} else {
					puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Empleados * ");
				}
				system("read -p 'Ingrese Enter para continuar...' var");
				break;
			case 2:
				if (editEmployee(employees, TAM_ESTRUCTURA) == 0) {
					puts("\n * MODIFICACION DE Empleado EXITOSA * \n");
					printEmployees(employees, TAM_ESTRUCTURA);
				} else {
					puts("\n * MODIFICACION DE Empleado CANCELADA * ");
				}
				system("read -p 'Ingrese Enter para continuar...' var");
				break;
			case 3:
				printEmployees(employees, TAM_ESTRUCTURA);
				GetInt(&idEmployee, "Ingrese Id del empleado a eliminar: ", "Ingreso erroneo");


				if (removeEmployee(employees, TAM_ESTRUCTURA, idEmployee) != -1) {
					puts("\n * BAJA DE Empleado EXITOSA");
					printEmployees(employees, TAM_ESTRUCTURA);
				} else {
					puts("\n * BAJA DE Empleado CANCELADA");
				}
				system("read -p 'Ingrese Enter para continuar...' var");
				break;
			case 4:
				do {
					puts("Elija el informe:");
					puts("1- Listado de empleados");
					puts("2- Total y promedio de los salarios, y cuantos empleados superan el salario promerio");
					scanf("%d", &listOpc);
					switch(listOpc) {
						case 1:
							sortEmployees(employees, TAM_ESTRUCTURA, listOpc);
							if (printEmployees(employees, TAM_ESTRUCTURA) == -1) {
								puts("\n * NO HAY EMPLEADOS * ");
							}
							break;
						case 2:
							break;
						default:
							puts("Ingreso erroneo");
					}
				} while (listOpc != 1 && listOpc != 2);
				system("read -p 'Ingrese Enter para continuar...' var");
				break;
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return EXIT_SUCCESS;
}
