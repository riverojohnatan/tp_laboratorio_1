/*
 * Validations.c
 *
 *  Created on: Apr 5, 2021
 *      Author: jrivero
 */

#include "Validations.h"

short int IsValidForDivision(float);
short int IsValidForFactorial(int);


sCalculator DoValidations(sCalculator calculator) {
    sCalculator response;

    response.firstNumber = calculator.firstNumber;
    response.secondNumber = calculator.secondNumber;
    response.results = calculator.results;
    response.errors = calculator.errors;

	if (IsValidForDivision(response.secondNumber) != 0) {
		response.errors.isErrorDivision = 1;
	}
	if (IsValidForFactorial(response.firstNumber) != 0) {
		response.errors.isErrorFactorial1 = 1;
	}
	if (IsValidForFactorial(response.secondNumber) != 0) {
		response.errors.isErrorFactorial2 = 1;
	}

	return response;
}

short int IsValidForDivision(float divider) {
	short int response = 0;

	if (divider == 0) {
		response = 1;
	}

	return response;
}

short int IsValidForFactorial(int number) {
	short int response = 0;

	if (number < 0) {
		response = 1;
	}

	return response;
}
