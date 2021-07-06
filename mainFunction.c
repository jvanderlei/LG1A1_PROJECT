// Documentation Section:
/* 
   Author: Gabriel Samori Parreira & João Pedro Vanderlei 
   Date: 06 de Julho de 2021
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
#include "functions.h"

//Global Declarations:

//The main() function:
int main()
{
	//Local Declarations:
	setlocale(LC_ALL,"Portuguese");
	FILE *senha;
	char nome[255];
	char buffer1[255];
	char buffer2[255];
	char pront[10];
	int aux;
		
	//Program Statements & Expressions:
	
	//Introdução:
	printf("\n ==================================================================================== \n");
	printf("\n                            INSTITUTO FEDERAL DE SAO PAULO                            \n");
	printf("\n ==================================================================================== \n\n");
	printf("\n LLLL              GGGGGGGGGGG          111111               AA             111111    ");
	printf("\n LLLL            GGGGGGGGGGGGGGG       1111111              AAAA           1111111    ");
	printf("\n LLLL           GGGG         GGGG     111 1111             AA  AA         111 1111    ");
	printf("\n LLLL          GGGG                       1111            AA    AA            1111    ");
	printf("\n LLLL          GGGG       GGGGGGG         1111           AAA    AAA           1111    ");
	printf("\n LLLL          GGGG           GGG         1111          AAAAAAAAAAAA          1111    ");
	printf("\n LLLL           GGGG         GGGG         1111         AAAAAAAAAAAAAA         1111    ");
	printf("\n LLLLLLLLLL      GGGGGGGGGGGGGGG       1111111111     AAAA        AAAA     1111111111 ");
	printf("\n LLLLLLLLLL        GGGGGGGGGGG         1111111111    AAAAA        AAAAA    1111111111 \n\n");
	printf("\n ==================================================================================== \n");
	printf("\n                         PROFESSOR FRANCISCO VERISSIMO LUCIANO                        \n");
	printf("\n                                  PROJETO SEMESTRAL                                   \n");
	printf("\n                   GABRIEL SAMORI PARREIRA     JOAO PEDRO VANDERLEI                   \n");
	printf("                          SP3072819                 SP3069427                           \n");
	printf("\n ==================================================================================== \n");
	printf("\n Pressione qualquer tecla para continuar...                                           \n");
	getch();
	system("cls");
	nameget:
	printf("\n DIGITE SEU NOME            : ");
	gets(nome);
		for (aux = 0; aux < strlen(nome); aux++) {
			nome[aux] = toupper(nome[aux]);
		}
	aux = isspace(nome[0]);
	
	if (aux != 0) {
		printf(" SEU NOME DEVE COMEÇAR COM UMA LETRA... ");
		goto nameget;
	}
	
	aux = strcmp(nome,"MASTER");
	switch (aux) {
		
		case 0 :
			printf(" You are the boss! aux : %d", aux);
			printf("\n DIGITE A SENHA MESTRA      : ");
			gets(buffer1);
			senha = fopen("senha.txt","r");
			fscanf(senha, "%s", buffer2);
			aux = strcmp(buffer1, buffer2);
			while(aux != 0) {
				printf(" Senha incorreta. Digite novamente: ");
				gets(buffer1);
				aux = strcmp(buffer1, buffer2);
			}
			master();
		break;
		
		default : 
		printf(" You are no one! aux : %d\n", aux);
		printf(" DIGITE SEU PRONTUÁRIO      : ");
		gets(pront);
		realizar(nome, pront);
	}
	
	//Entrada:

	//Processamento:

	//Saída:
	
	return 0;
}

