#ifndef INPUTOUTPUT_H_
#define INPUTOUTPUT_H_

#include <stdio_ext.h>
#include <stdlib.h>

#define MAX_TRIES 2

typedef struct {
	char code;
	char description[25];
} sMenu;

/* INPUTS */
int GetInt(int*, char*, char*);

int GetFloat(float*, char*, char*);

int GetChar(char*, char*, char*);

int GetString(char*, int, char*, char*);

/* OUTPUTS */
int ShowMenu(void);

void ShowInt(char[], int);

void ShowFloat(char[], float);

void ShowChar(char[], char);

void ShowString(char[], char[]);

void ShowPause();
/*
char ShowMenu(sMenu[], int, char *);*/

#endif /* INPUTOUTPUT_H_ */
