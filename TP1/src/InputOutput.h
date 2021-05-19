/*
 * InputOutput.h
 *
 *  Created on: Apr 12, 2021
 *      Author: jrivero
 */

#ifndef INPUTOUTPUT_H_


#include <stdio_ext.h>
#include "Structure.h"

/**
 * @fn int GetInt(char[])
 * @brief Request a integer number from terminal
 *
 * @param message - Message to request
 * @return Input integer number
 */
int GetInt(char[]);

/**
 * @fn float GetFloat(char[])
 * @brief Request a decimal number from terminal
 *
 * @param message
 * @return Input Float number
 */
float GetFloat(char[]);

/**
 * @fn char GetChar(char[])
 * @brief Request a character from terminal
 *
 * @param message
 * @return Input char number
 */
char GetChar(char[]);

/**
 * @fn void ShowResult(sCalculator)
 * @brief Show result on terminal by the operator selected
 *
 * @param response
 */
void ShowResult(sCalculator);
#define INPUTOUTPUT_H_

#endif /* INPUTOUTPUT_H_ */
