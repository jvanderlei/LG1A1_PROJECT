
/* functions.h */

void master() { // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  
	char aux[5];
	int i=0;
	system("cls");
	printf(" A fun��o MASTER foi iniciada...\n");
	
	label1:	//  LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1 // LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1 // LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1 //
		
	printf(" ================================================== \n");
	printf("        TESTE DOS SISTEMAS REPRESENTACIONAIS        \n");
	printf(" ================================================== \n");
	printf("        1. Cadastrar question�rio                   \n");
	printf("        2. Visualizar question�rio                  \n");
	printf("        3. Realizar teste                           \n");
	printf("        4. Sobre o teste                            \n");
	printf("        F. Fim                                      \n");
	printf(" ================================================== \n");
	printf("        Escolha -> ");
		gets(aux);
	
	if (strlen(aux) > 1) {
			system("cls");
		printf(" Escolha inv�lida...\n");
		goto label1;
	}
	
	 switch (aux[0]) {
		
		case 49:
			system("cls");
		printf(" O n�mero %d foi escolhido. \n", aux[0]-48);
		cadastrar();
		break;
		
		case 50:
			system("cls");
		printf(" O n�mero %d foi escolhido. \n", aux[0]-48);
		visualizar();
		break;
		
		case 51:
			system("cls");
		printf(" O n�mero %d foi escolhido. \n", aux[0]-48);
		realizar();
		break;
		
		case 52:
			system("cls");
		printf(" O n�mero %d foi escolhido. \n", aux[0]-48);
		sobre();
		break;
		
		case 70:
		case 102:
			system("cls");
		printf(" FIM foi escolhido. \n");
		fim();
		break;
		
		default:
			system("cls");
		printf(" Escolha inv�lida... \n");
		break;
		
	}
	goto label1;


}

void cadastrar() { // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  

	setlocale(LC_ALL,"Portuguese");

	char buffer1[255];
	int i;
	
	printf(" A fun��o CADASTRAR foi iniciada...\n");
	sleep(2);
	printf(" Aqui voc� poder� registrar um novo question�rio de acordo com a sua prefer�ncia. \n");
	FILE *questRegister, *questNovo;
	questRegister = fopen("questRegistrados.txt", "a");
	printf(" Digite o nome do question�rio: ");
	gets(buffer1);
	for (i=0; i<strlen(buffer1); i++) {
		printf(" buffer1[%d] - char:%c int:%d \n", i, buffer1[i], buffer1[i]);
	}
	printf(" %s\n", buffer1);
	fprintf(questRegister, "%s \n", buffer1);
	fclose(questRegister);
	sleep(2);
	printf(" A fun��o CADASTRAR encerrou...\n");
}

void realizar(char nome[255], char pront[10]) {
	printf(" A fun��o REALIZAR foi iniciada...\n");
	printf(" Nome: %s  Prontu�rio: %s", nome, pront);
}

void visualizar() {
	printf(" A fun��o VISUALIZAR foi iniciada...\n");
}

void sobre() {
	printf(" A fun��o SOBRE foi iniciada...\n");
}

void fim() {
	printf(" A fun��o FIM foi iniciada...\n");
}

int replacestr(char *line, const char *search, const char *replace)
{
   int count;
   char *sp; // start of pattern

   //printf("replacestr(%s, %s, %s)\n", line, search, replace);
   if ((sp = strstr(line, search)) == NULL) {
      return(0);
   }
   count = 1;
   int sLen = strlen(search);
   int rLen = strlen(replace);
   if (sLen > rLen) {
      // move from right to left
      char *src = sp + sLen;
      char *dst = sp + rLen;
      while((*dst = *src) != '\0') { dst++; src++; }
   } else if (sLen < rLen) {
      // move from left to right
      int tLen = strlen(sp) - sLen;
      char *stop = sp + rLen;
      char *src = sp + sLen + tLen;
      char *dst = sp + rLen + tLen;
      while(dst >= stop) { *dst = *src; dst--; src--; }
   }
   memcpy(sp, replace, rLen);

   count += replacestr(sp + rLen, search, replace);

   return(count);
}
