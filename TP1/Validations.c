/*
 * Validations.c
 *
 *  Created on: Apr 5, 2021
 *      Author: jrivero
 */

#include "Validations.h"

short int IsValidForDivision(float);
short int IsValidForFactorial(int);

/**
 * @fn short int DoValidations(sCalculator)
 * @brief Check operation to do validation for division and factorial
 *
 * @param calculator
 * @return
 */
short int DoValidations(sCalculator calculator) {

	short int response;

	response = 0;

	if (calculator.operation == 'd' && IsValidForDivision(calculator.secondNumber) != 0) {
		response = 1;
	} else if (calculator.operation == 'f' && IsValidForFactorial(calculator.firstNumber) != 0) {
		response = 1;
	}else if (calculator.operation == 'f' && IsValidForFactorial(calculator.secondNumber) != 0) {
		response = 2;
	}

	return response;
}

short int IsValidForDivision(float divider) {
	short int response = 0;

	if (divider < 1) {
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
