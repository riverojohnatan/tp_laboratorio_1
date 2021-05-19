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


sCalculator DoOperation(sCalculator calculator){
    sCalculator response = InitStructure();

    response.firstNumber = calculator.firstNumber;
    response.secondNumber = calculator.secondNumber;

	response = DoValidations(response);

	response.results.resultSum = DoAdditionOperation(response.firstNumber, response.secondNumber);
	response.results.resultSub = DoSubtractionOperation(response.firstNumber, response.secondNumber);
	response.results.resultMult = DoMultiplicationOperation(response.firstNumber, response.secondNumber);

	if (response.errors.isErrorDivision == 0) {
		response.results.resultDiv = DoDivisionOperation(response.firstNumber, response.secondNumber);
	}
	if (response.errors.isErrorFactorial1 == 0) {
		response.results.resultFact1 = DoFactorialOperation(response.firstNumber);
	}
	if (response.errors.isErrorFactorial2 == 0) {
		response.results.resultFact2 = DoFactorialOperation(response.secondNumber);
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
