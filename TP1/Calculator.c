/*
 * Calculator.c
 *
 *  Created on: Apr 5, 2021
 *      Author: jrivero
 */

#include "Calculator.h"
#include "Validations.h"

float DoAdditionOperation(float, float);
float DoSubtractionOperation(float, float);
float DoDivisionOperation(float, float);
float DoMultiplicationOperation(float, float);
int DoFactorialOperation(int);


/**
 * @fn sResponse DoOperation(float, float, char)
 * @brief Calculate the operation for the two numbers
 *
 * @param float firstNumber
 * @param float secondNumber
 * @param char operational
 * @return A structure with operation' status
 */
sCalculator DoOperation(sCalculator calculator){
	sCalculator response;

	response.firstNumber = calculator.firstNumber;
	response.secondNumber = calculator.secondNumber;
	response.operation = calculator.operation;
	response.isError = DoValidations(calculator);

	switch(response.operation) {
		case 's':
			response.result = DoAdditionOperation(response.firstNumber, response.secondNumber);
			break;
		case 'r':
			response.result = DoSubtractionOperation(response.firstNumber, response.secondNumber);
			break;
		case 'm':
			response.result = DoMultiplicationOperation(response.firstNumber, response.secondNumber);
			break;
		case 'd':
			if (response.isError == 0) {
				response.result = DoDivisionOperation(response.firstNumber, response.secondNumber);
			}
			break;
		case 'f':
			if (response.isError != 1) {
				response.result = DoFactorialOperation(response.firstNumber);
			}

			if (response.isError != 2) {
				response.result2 = DoFactorialOperation(response.secondNumber);
			}

			break;
		default:
			break;
	}

	return response;

}

float DoAdditionOperation(float firstNumber, float secondNumber){
	float response;

	response = firstNumber + secondNumber;

	return response;
}

float DoSubtractionOperation(float firstNumber, float secondNumber) {
	float response;

	response = firstNumber - secondNumber;

	return response;
}

float DoDivisionOperation(float firstNumber, float secondNumber) {
	float response;

	response = firstNumber / secondNumber;

	return response;
}

float DoMultiplicationOperation(float firstNumber, float secondNumber) {
	float response;

	response = firstNumber * secondNumber;

	return response;
}

int DoFactorialOperation(int number) {
	int factorialNumber;

	factorialNumber = 1;

	for(int i=1; i<=number; i++) {
		factorialNumber = factorialNumber * i;
	}

	return factorialNumber;
}
