// Documentation Section:
/* 
   Author: Gabriel Samori Parreira & João Pedro Vanderlei 
   Date: 17 de Junho de 2021
   Description: Projeto Semestral LG1A1
*/
//Preprocessor Statements:

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//Global Declarations:

const char* getfield(char* line, int num)
{
	const char* tok;
	for (tok = strtok(line, ";");
			tok && *tok;
			tok = strtok(NULL, ";\n"))
	{
		if (!--num)
			return tok;
	}
	return NULL;
}

//The main() function:
int main()
{
	
char line[1024];
    while (fgets(line, 1024, stdin))
	{
		char* test = strdup(line);
		printf("Field 1 would be %s\n", getfield(test, 1));
		// NOTE strtok clobbers test
		free(test);
	}

}

//Secondary functions:
//the login() function:
void login(){
	
}

//the master() function:
void master(){
	
}

//the cadastrar() function:
void cadastrar(){
	
}

//the visualizar() function:
void visualizar(){
	
}

//the realizar() function:
void realizar(){
	
}

//the about() function:
void about(){
	
}

//the resultado() function:
void resultado(){
	
}
