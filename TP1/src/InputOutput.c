/*
 * InputOutput.c
 *
 *  Created on: Apr 12, 2021
 *      Author: jrivero
 */


#include "InputOutput.h"

int GetInt(char message[]) {
	int input;

	printf(message);
	scanf("%d", &input);

	return input;
}

float GetFloat(char message[]) {
	float input;

	printf(message);
	scanf("%f", &input);

	return input;
}

char GetChar(char message[]) {
	char input;

	printf(message);
	__fpurge(stdin);
	scanf("%c", &input);

	return input;
}

void ShowResult(sCalculator response) {
	printf("El resultado de %.2f + %.2f es: %.2f\n", response.firstNumber, response.secondNumber, response.results.resultSum);
	printf("El resultado de %.2f-%.2f es: %.2f\n", response.firstNumber, response.secondNumber, response.results.resultSub);
	printf("El resultado de %.2f*%.2f es: %.2f\n", response.firstNumber, response.secondNumber, response.results.resultMult);

	if (response.errors.isErrorDivision == 0) {
		printf("El resultado de %.2f/%.2f es: %.2f\n", response.firstNumber, response.secondNumber, response.results.resultDiv);
	} else {
		printf("No es posible dividir por cero\n");
	}

	if (response.errors.isErrorFactorial1 == 0) {
		printf("El factorial de %d es: %d\n", (int)response.firstNumber, (int)response.results.resultFact1);
	} else {
		printf("No es posible calcular el factorial de %d\n", (int)response.firstNumber);
	}

	if (response.errors.isErrorFactorial2 == 0) {
		printf("El factorial de %d es: %d\n", (int)response.secondNumber, (int)response.results.resultFact2);
	} else {
		printf("No es posible calcular el factorial de %d\n", (int)response.secondNumber);
	}
}
