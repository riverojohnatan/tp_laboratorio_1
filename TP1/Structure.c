/*
 * Structure.c
 *
 *  Created on: Apr 16, 2021
 *      Author: jrivero
 */

#include "Structure.h"

sCalculator InitStructure() {

    sCalculator response;

	response.firstNumber = 0;
	response.secondNumber = 0;
	response.results.resultSum = 0;
	response.results.resultSub = 0;
	response.results.resultMult = 0;
	response.results.resultDiv = 0;
	response.results.resultFact1 = 0;
	response.results.resultFact2 = 0;
	response.errors.isErrorDivision = 0;
	response.errors.isErrorFactorial1 = 0;
	response.errors.isErrorFactorial2 = 0;

    return response;
}
