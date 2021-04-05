/*
 * Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 * 	1. Ingresar 1er operando (A=x)
 * 	2. Ingresar 2do operando (B=y)
 * 	3. Calcular todas las operaciones
 * 		a) Calcular la suma (A+B)
 * 		b) Calcular la resta (A-B)
 * 		c) Calcular la division (A/B)
 * 		d) Calcular la multiplicacion (A*B)
 * 		e) Calcular el factorial (A!)
 * 	4. Informar resultados
 * 		a) “El resultado de A+B es: r”
 * 		b) “El resultado de A-B es: r”
 * 		c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 * 		d) “El resultado de A*B es: r”
 * 		e) “El factorial de A es: r1 y El factorial de B es: r2”
 * 	5. Salir
 *
 * 	• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte, que contenga las funciones para realizar las cinco operaciones.
 * 	• En el menú deberán aparecer los valores actuales cargados en los operandos A y B (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 * 	• Deberán contemplarse los casos de error (división por cero, etc)
 * 	• Documentar todas las funciones
 *
 *  Rivero Johnatan
 */

#include "Calculator.h"

int main()
{
	float firstNumber;
	float secondNumber;
	char operation;
	char flag;

	setbuf(stdout, NULL);

	do {
		printf("Ingrese A: ");
		scanf("%f", &firstNumber);
		printf("Ingrese B: ");
		scanf("%f", &secondNumber);

		printf("Ingrese la operacion: Suma (s), Resta (r), División (d), Multiplicación (m) o Factorial (f)\n");
		__fpurge(stdin);
		scanf("%c", &operation);

		DoOperation(firstNumber, secondNumber, operation);

		printf("¿Desea realizar otra operacion? s/n");
		__fpurge(stdin);
		scanf("%c", &flag);

	}while(flag == 's');

	return 0;
}
