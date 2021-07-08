
/* functions.h */

void master() { // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  //  
	char aux[5];
	int i=0;
	system("cls");
	printf(" A função MASTER foi iniciada...\n");
	
	label1:	//  LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1 // LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1 // LABEL 1	// LABEL 1  // LABEL 1	// LABEL 1	// LABEL 1 //
		
	printf(" ================================================== \n");
	printf("        TESTE DOS SISTEMAS REPRESENTACIONAIS        \n");
	printf(" ================================================== \n");
	printf("        1. Cadastrar questionário                   \n");
	printf("        2. Visualizar questionário                  \n");
	printf("        3. Realizar teste                           \n");
	printf("        4. Sobre o teste                            \n");
	printf("        F. Fim                                      \n");
	printf(" ================================================== \n");
	printf("        Escolha -> ");
		gets(aux);
	
	if (strlen(aux) > 1) {
			system("cls");
		printf(" Escolha inválida...\n");
		goto label1;
	}
	
	 switch (aux[0]) {
		
		case 49:
			system("cls");
		printf(" O número %d foi escolhido. \n", aux[0]-48);
		cadastrar();
		break;
		
		case 50:
			system("cls");
		printf(" O número %d foi escolhido. \n", aux[0]-48);
		visualizar();
		break;
		
		case 51:
			system("cls");
		printf(" O número %d foi escolhido. \n", aux[0]-48);
		realizar();
		break;
		
		case 52:
			system("cls");
		printf(" O número %d foi escolhido. \n", aux[0]-48);
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
		printf(" Escolha inválida... \n");
		break;
		
	}
	goto label1;


}

void cadastrar() { // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  

	char buffer1[255];
	int i, j, k, qtFrases, qtItens;
	int aux1 = 0;
	
	printf(" A função CADASTRAR foi iniciada...\n");
	sleep(2);
	
	printf(" Aqui você poderá registrar um novo questionário de acordo com a sua preferência. \n");
	
	FILE *questRegister, *questNovo;
	questRegister = fopen("questRegistrados.txt", "a");
	
	printf(" Digite o nome do questionário: ");
	gets(buffer1);
	localeAcc(buffer1);

	printf(" O nome %s foi registrado...\n", buffer1);
	
	fprintf(questRegister, "%s\n", buffer1);
	
	fclose(questRegister);
	
	printf(" Informe quantas frases o questionário terá: ");
	scanf(" %d", &qtFrases);
	
	printf(" Informe quantos itens de resposta terão em cada frase: ");
	scanf(" %d", &qtItens);
	fflush(stdin);
	
	replacestr(buffer1, " ", "_");
	strncat(buffer1, ".txt", 4);	
	questNovo = fopen(buffer1, "w");
	
	char quest[qtFrases+1][qtItens+2][255];
	
	strcpy(quest[0][0], "NroFrase");
	strcpy(quest[0][1], "Frase");
	for (j=2; j<qtItens+2; j++) {
		sprintf(quest[0][j], "item_%d", j-1);
		printf("quest[0][%d] : %s\n", j, quest[0][j]);
	}
	for (i=1; i<qtFrases+1; i++) {
		sprintf(quest[i][0], "%d", i);
		printf("quest[%d][0] : %s\n", i, quest[i][0]);
	}
	
		for (i=1; i<qtFrases+1; i++) {
			for (j=1; j<qtItens+2; j++) {
				if (j!=1) {
					printf(" Informe o %do Item da %da Frase: \n", j-1, i);
					gets(quest[i][j]);
					localeAcc(quest[i][j]);
				} else {
					printf(" Informe a %da Frase: \n", i);
					gets(quest[i][j]);
					localeAcc(quest[i][j]);
				}
			}
		}
	
	for (i=0; i<qtFrases+1; i++) {
		
		
		for (j=0; j<qtItens+2; j++) {
			
							
				fprintf(questNovo, "%s", quest[i][j]);
				
				for (k=0; k<qtFrases+1; k++) {
					
					if (strlen(quest[k][j]) >= aux1) {
						
						aux1 = strlen(quest[k][j]);
						
					}
					
				}
				aux1 = aux1 - strlen(quest[i][j]);
				for (k=0; k<aux1; k++) {
					fprintf(questNovo, " ");
				}
				
			if (j < qtItens+1) {
				
				fprintf(questNovo, " , ");
				
				}
			aux1 = 0;
			}	
			
			if (i<qtFrases) {
				fprintf(questNovo, "\n");
			}
	}
	
	fclose(questNovo);
	
	sleep(2);
	printf(" A função CADASTRAR encerrou...\n");
	
}

void realizar(char nome[255], char pront[10]) { //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //
	printf(" A função REALIZAR foi iniciada...\n");
	printf(" Nome: %s  Prontuário: %s", nome, pront);
}

void visualizar() { // VISUALIZAR  // VISUALIZAR  // VISUALIZAR  // VISUALIZAR  // VISUALIZAR  // VISUALIZAR  // VISUALIZAR  // VISUALIZAR  // VISUALIZAR  // VISUALIZAR  // VISUALIZAR  // VISUALIZAR  //
	printf(" A função VISUALIZAR foi iniciada...\n");
}

void sobre() { // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE // SOBRE //
	printf(" A função SOBRE foi iniciada...\n");
}

void fim() { //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //  FIM  //
	printf(" A função FIM foi iniciada...\n");
}

int replacestr(char *line, const char *search, const char *replace) { // REPLACE IN STRING  // REPLACE IN STRING  // REPLACE IN STRING  // REPLACE IN STRING  // REPLACE IN STRING  // REPLACE IN STRING  //
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

int localeAcc(char *line) // LOCALE.H FIX  // LOCALE.H FIX  // LOCALE.H FIX  // LOCALE.H FIX  // LOCALE.H FIX  // LOCALE.H FIX  // LOCALE.H FIX  // LOCALE.H FIX  // LOCALE.H FIX  // LOCALE.H FIX  // LOCALE.H FIX  // LOCALE.H FIX  //
{
	int i;
	int aux = strlen(line);
	for (i=0; i<aux; i++) {
		switch ((int)line[i]) {

			case -123 : {
				line[i] = 224;
				break;
			}
			case -96 : {
				line[i] = 225;
				break;
			}
			case -125 : {
				line[i] = 226;
				break;
			}
			case -121 : {
				line[i] = 231;
				break;
			}
			case -126 : {
				line[i] = 233;
				break;
			}
			case -120 : {
				line[i] = 234;
				break;
			}
			case -95 : {
				line[i] = 237;
				break;
			}
			case -94 : {
				line[i] = 243;
				break;
			}
			case -109 : {
				line[i] = 244;
				break;
			}
			case -93 : {
				line[i] = 250;
				break;
			}
			case -112 : {
				line[i] = 201;
				break;
			}
			default : {
				break;
			}
			
			
		}
	} 
}
