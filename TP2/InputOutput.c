#include "InputOutput.h"

static int getValidInt(int* number);
static int isNumber(char* string);
static int getValidFloat(float* number);
static int isFloatNumber(char* string);
static int getValidChar(char* character);
static int getValidString(char* string);
static int isEmpty(char* string);

/**
 * @fn int GetInt(int*, char*, char*)
 * @brief Request a integer number from terminal
 *
 * @param number - Variable to set
 * @param message - Message to request
 * @param errorMessage - Message to show when it has an error
 * @return 0 if the input was OK, -1 if the user tried many times and fail
 */
int GetInt(int* number, char* message, char* errorMessage) {
	int ret;
	int input;
	int i;

	for (i=MAX_TRIES; i > 0; i--) {
		printf(message);

		if (getValidInt(&input) == 1) {
			break;
		}
		__fpurge(stdin);

		puts(errorMessage);
	}

	if(i == 0) {
		ret=-1;
	} else {
		ret=0;
		*number = input;
	}

	return ret;
}

/**
 * @fn int GetFloat(float*, char*, char*)
 * @brief Request a decimal number from terminal
 *
 * @param number - Variable to set
 * @param message - Message to request
 * @param errorMessage - Message to show when it has an error
 * @return 0 if the input was OK, -1 if the user tried many times and fail
 */
int GetFloat(float* number, char* message, char* errorMessage) {
	int ret;
	float input;
	int i;

	for (i=MAX_TRIES; i > 0; i--) {
		printf(message);

		if (getValidFloat(&input)==1) {
			break;
		}
		__fpurge(stdin);

		puts(errorMessage);
	}

	if(i == 0) {
		ret=-1;
	} else {
		ret=0;
		*number = input;
	}

	return ret;
}

/**
 * @fn int GetChar(char*, char*, char*)
 * @brief Request a character from terminal
 *
 * @param character - Variable to set
 * @param message - Message to request
 * @param errorMessage - Message to show when it has an error
 * @return 0 if the input was OK, -1 if the user tried many times and fail
 */
int GetChar(char* character, char* message, char* errorMessage) {
	int ret;
	char input;
	int i;

	for (i=MAX_TRIES; i > 0; i--) {
		printf(message);

		if (getValidChar(&input)==1) {
			break;
		}
		__fpurge(stdin);

		puts(errorMessage);
	}

	if(i == 0) {
		ret=-1;
	} else {
		ret=0;
		*character = input;
	}

	return ret;
}

/**
 * @fn int GetString(char*, char*, char*)
 * @brief Request a string from terminal
 *
 * @param character - Variable to set
 * @param message - Message to request
 * @param errorMessage - Message to show when it has an error
 * @return 0 if the input was OK, -1 if the user tried many times and fail
 */
int GetString(char* string, int SIZE, char* message, char* errorMessage) {
	int ret;
	char input[SIZE];
	int i;

	for (i=MAX_TRIES; i > 0; i--) {
		printf(message);

		if (getValidString(&input)==1) {
			break;
		}
		__fpurge(stdin);

		puts(errorMessage);
	}

	if(i == 0) {
		ret=-1;
	} else {
		ret=0;
		size_t ln = strlen(input)-1;
		if (input[ln] == '\n')
			input[ln] = '\0';
		strcpy(string, input);
	}

	return ret;
}

/**
 * @fn int ShowMenu()
 * @brief Show on terminal a menu
 *
 * @return selected menu
 */
int ShowMenu() {
	int response;

	response = GetInt(&response, "", "");

	return response;
}

/**
 * @fn void ShowInt(char[], int)
 * @brief Show message and output number
 *
 * @param message - Without any format
 * @param output
 */
void ShowInt(char message[], int output) {
	printf(message);
	printf("%d\n", output);
}

/**
 * @fn void ShowFloat(char[], float)
 * @brief Show message and output float number
 *
 * @param message - Without any format
 * @param output
 */
void ShowFloat(char message[], float output) {
	printf(message);
	printf("%.2f\n", output);
}

/**
 * @fn void ShowChar(char[], char)
 * @brief Show message and output character
 *
 * @param message - Without any format
 * @param output
 */
void ShowChar(char message[], char output) {
	printf(message);
	printf("%c\n", output);
}

/**
 * @fn void ShowString(char[], char[])
 * @brief Show message and output string
 *
 * @param message - Without any format
 * @param output
 */
void ShowString(char message[], char output[]) {
	printf(message);
	printf("%s\n", output);
}

/**
 * @fn void ShowPause()
 * @brief Print a pause so the user can read the information
 *
 */
void ShowPause() {
	system("read -p 'Ingrese Enter para continuar...' var");
}


/* VALIDATIONS */

static int getValidInt(int* number) {
	int response = -1;
	char buffer[64];
	__fpurge(stdin);
	fgets(buffer, sizeof(buffer), stdin);

	if (isNumber(buffer)) {
		*number = atoi(buffer);
		response = 1;
	}

	return response;
}

static int isNumber(char* string) {
	int i = 0;
	int response = 1;

	if (string != NULL && strlen(string) > 0) {
		if (string[0] == '\n') {
			response = 0;
		} else {
			while(string[i] != '\n') {
				if(string[i] < '0' || string[i] > '9') {
					response = 0;
					break;
				}
				i++;
			}
		}
	}

	return response;
}

static int getValidFloat(float* number) {
	int response = -1;
	char buffer[64];
	__fpurge(stdin);
	fgets(buffer, sizeof(buffer), stdin);

	if (isFloatNumber(buffer)) {
		*number = atof(buffer);
		response = 1;
	}

	return response;
}

static int isFloatNumber(char* string) {
	int i = 0;
	int response = 1;

	if (string != NULL && strlen(string) > 0) {
		if (string[0] == '\n') {
			response = 0;
		} else {
			while(string[i] != '\n') {
				if((string[i] < '0' || string[i] > '9') && string[i] != '.') {
					response = 0;
					break;
				}
				i++;
			}
		}
	}

	return response;
}

static int getValidChar(char* character) {
	int response = -1;
	char buffer[64];
	__fpurge(stdin);
	fgets(buffer, sizeof(buffer), stdin);

	if (buffer != NULL && strlen(buffer) > 0 && buffer[0] != '\0' && buffer[0] != '\n') {
		*character = buffer[0];
		response = 1;
	}

	return response;
}

static int getValidString(char* string) {
	int response = -1;
	char buffer[64];
	__fpurge(stdin);
	fgets(buffer, sizeof(buffer), stdin);

	if (isEmpty(buffer) == 1) {
		strcpy(string, buffer);
		response = 1;
	}

	return response;
}

static int isEmpty(char* string) {
	int i = 0;
	int response = 1;

	if (string != NULL && strlen(string) > 0) {
		if (string[0] == '\n') {
			response = 0;
		} else {
			while(string[i] != '\n') {
				if(string[i] == '\0') {
					response = 0;
					break;
				}
				i++;
			}
		}
	}

	return response;
}


int ValidateAction(char * message) {
	char opc;
	int response = 0;
	int tries = 3;

	GetChar(&opc, message, "");
	while (opc != 'n' && opc != 's' && tries > 1) {
		puts("Opcion invalida");
		GetChar(&opc, message, "");
		tries--;
	}

	if (tries > 1) {
		if (opc == 'n') {
			response = 1;
		}
	} else {
		response = -1;
	}

	return response;
}
