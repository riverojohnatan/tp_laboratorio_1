/*
 * InputOutput.c
 *
 *  Created on: Apr 12, 2021
 *      Author: jrivero
 */


#include "InputOutput.h"

/**
 * @fn int GetInt(char[])
 * @brief Request a integer number from terminal
 *
 * @param message - Message to request
 * @return Input integer number
 */
int GetInt(char message[]) {
	int input;

	printf(message);
	scanf("%d", &input);

	return input;
}

/**
 * @fn float GetFloat(char[])
 * @brief Request a decimal number from terminal
 *
 * @param message
 * @return Input Float number
 */
float GetFloat(char message[]) {
	float input;

	printf(message);
	scanf("%f", &input);

	return input;
}

/**
 * @fn char GetChar(char[])
 * @brief Request a character from terminal
 *
 * @param message
 * @return Input char number
 */
char GetChar(char message[]) {
	char input;

	printf(message);
	__fpurge(stdin);
	scanf("%c", &input);

	return input;
}

/**
 * @fn void ShowResult(sCalculator)
 * @brief Show result on terminal by the operator selected
 *
 * @param response
 */
void ShowResult(sCalculator response) {
	switch(response.operation) {
		case 's':
			printf("El resultado de %.2f + %.2f es: %.2f\n", response.firstNumber, response.secondNumber, response.result);
			break;
		case 'r':
			printf("El resultado de %.2f-%.2f es: %.2f\n", response.firstNumber, response.secondNumber, response.result);
			break;
		case 'm':
			printf("El resultado de %.2f*%.2f es: %.2f\n", response.firstNumber, response.secondNumber, response.result);
			break;
		case 'd':
			if (response.isError == 0) {
				printf("El resultado de %.2f-%.2f es: %.2f\n", response.firstNumber, response.secondNumber, response.result);
			} else {
				printf("No es posible dividir por cero\n");
			}

			break;
		case 'f':
			if (response.isError == 1) {
				printf("No es posible calcular el factorial de %d\n", (int)response.firstNumber);
			} else {
				printf("El factorial de %d es: %d\n", (int)response.firstNumber, (int)response.result);
			}
			if (response.isError == 2) {
				printf("No es posible calcular el factorial de %d\n", (int)response.secondNumber);
			} else {
				printf("El factorial de %d es: %d\n", (int)response.secondNumber, (int)response.result2);
			}
			break;
		default:
			break;
	}
}
