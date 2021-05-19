/*
 * Structure.h
 *
 *  Created on: Apr 12, 2021
 *      Author: jrivero
 */

#ifndef STRUCTURE_H_

typedef struct {
	float resultSum;
	float resultSub;
	float resultMult;
	float resultDiv;
	float resultFact1;
	float resultFact2;
}sResult;

typedef struct {
	short int isErrorDivision;
	short int isErrorFactorial1;
	short int isErrorFactorial2;
}sError;

typedef struct{
	float firstNumber;
	float secondNumber;
	sResult results;
	sError errors;
}sCalculator;

/**
 * @fn sCalculator InitStructure()
 * @brief Initialize all structure fields
 *
 * @return An Initialized structure
 */
sCalculator InitStructure();

#define STRUCTURE_H_

#endif /* STRUCTURE_H_ */
