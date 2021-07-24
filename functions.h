
/* functions.h */

void master() { // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  // MASTER  //
	char aux[5];
	int i=0;
	system("cls");
	printf(" A fun��o MASTER foi iniciada...\n");
	
	label1:	//  LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1 // LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1	// LABEL 1 // LABEL 1	// LABEL 1	//
		
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
		realizar("MASTER", "MASTER");
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
	fflush(stdin);
	goto label1;


}

void cadastrar() { // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  // CADASTRAR  //

	char buffer1[255];
	int i, j, k, qtFrases, qtItens;
	int aux1 = 0;
	
	printf(" A fun��o CADASTRAR foi iniciada...\n");
	sleep(2);
	
	printf(" Aqui voc� poder� registrar um novo question�rio de acordo com a sua prefer�ncia. \n");
	
	FILE *questRegister, *questNovo, *valoresRegister, *sobre;
	questRegister = fopen("questRegistrados.txt", "a");
	
	printf(" Digite o nome do question�rio: ");
	gets(buffer1);
	localeAcc(buffer1);
	replacestr(buffer1, " ", "_");
	strncat(buffer1, ".txt", 4);

	printf("\n O nome %s foi registrado...\n", buffer1);
	
	char buffer3[50];
	sprintf(buffer3, "sobre_%s", buffer1);
	sobre = fopen(buffer3, "w");
	fprintf(sobre, "%s","REFERENCIAL TE�RICO\n");
	fprintf(sobre, "%s", "-------------------\n\n\n");
	fclose(sobre);
	printf(" Um arquivo chamado 'sobre_%s' foi criado onde voc� poder� informar o referencial te�rico deste question�roio.\n", buffer1);
	
	fprintf(questRegister, "\n%s", buffer1);
	
	fclose(questRegister);
	
	printf(" Informe quantas frases o question�rio ter�: ");
	scanf(" %d", &qtFrases);
	
	printf(" Informe quantos itens de resposta ter�o em cada frase: ");
	scanf(" %d", &qtItens);
	
	fflush(stdin);
	
	char buffer2[255] = "valorResp_";
	strcat(buffer2, buffer1);
	char valorResp[2*qtItens][255];
	
	
	valoresRegister = fopen(buffer2, "w");
	
	for (i=0; i<2*qtItens; i++) {
		if (i % 2 == 0) {
			printf(" Informe o valor resposta do %do item: ", (i/2)+1);
			gets(valorResp[i]);
			localeAcc(valorResp[i]);
			fprintf(valoresRegister, "%s\n", valorResp[i]);
		} else {
			printf( " Escreva a descri��o que aparecer� no resultado do question�rio junto a este valor resposta: ");
			gets(valorResp[i]);
			localeAcc(valorResp[i]);
			if (i == (2*qtItens)-1) {
				fprintf(valoresRegister, "%s", valorResp[i]);
			} else {
				fprintf(valoresRegister, "%s\n", valorResp[i]);
			}
		}
	}
	
	fclose(valoresRegister);
	
	
	questNovo = fopen(buffer1, "w");
	
	char quest[qtFrases+1][qtItens+2][255];
	char valores[qtFrases+1][qtItens][50];
	
	strcpy(quest[0][0], "NroFrase");
	strcpy(quest[0][1], "Frase");
	for (j=2; j<qtItens+2; j++) {
		sprintf(quest[0][j], "item_%d", j-1);
		printf("quest[0][%d] : %s\n", j, quest[0][j]);
		
		sprintf(valores[0][j-2], "item_%d", j-1);
		printf("valores[0][%d] : %s\n", j-2, valores[0][j-2]);
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
				fprintf(questNovo, " \n");
			}
			
			if (i==qtFrases) {
				fprintf(questNovo, " ");
			}
	}		
	fclose(questNovo);
	
	sleep(2);
	printf(" A fun��o CADASTRAR encerrou...\n");
	
}

void realizar(char nome[255], char pront[10]) { //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //
	printf(" A fun��o REALIZAR foi iniciada...\n\n");
	sleep(2);
	system("cls");
	setlocale(LC_ALL,"");
	
	FILE *showQuest, *doQuest, *valoresQuest;

	showQuest = fopen("questRegistrados.txt", "r");
	
	char buffer1[255];
	int j = 0;
	
	while(fgets(buffer1, 255, showQuest)) {
		j++;
	}
	char buffer2[j][255];
	
	printf(" Escolha o question�rio dentre os listados: \n");
	
	showQuest = fopen("questRegistrados.txt", "r");
	int i = 0;
	
	while (fgets(buffer1, 255, showQuest)) {
		strcpy(buffer2[i], buffer1);
		if (i < j) {
			printf(" %d - %s", i+1, buffer2[i]);
		}
		i++;
	}
	i = 0;
	printf("\n");
	int aux;
	scanf(" %d", &aux);
	while(aux < 1 || aux > j) {
		printf(" N�mero inv�lido... Favor escolher um dos n�meros listados acima: ");
		scanf(" %d", &aux);
	}
	
	fclose(showQuest);   	
    
//	printf(" %s", buffer1); // controle
	printf(" Foi escolhido: %s", buffer2[aux-1]);
	printf("\n Pressione qualquer tecla para continuar...                                           \n");
	getch();
	system("cls");
	
	char buffer3[255];
	sprintf(buffer1, "valorResp_%s", buffer2[aux-1]);
	if(aux != j) {
		buffer1[strlen(buffer1)-1] = 0;
	}
	valoresQuest = fopen(buffer1, "r");
	if((valoresQuest = fopen(buffer1, "r")) == NULL) {
		printf("%s: cannot open\n", buffer1);
		exit(1);
	}
	int qtItens = 0;              
	while (fgets(buffer3, 255, valoresQuest)) {
		localeAcc(buffer3);
	//	printf(" %s", buffer3); // controle
		qtItens++;
	}
	qtItens = qtItens / 2;
	
	char perfil[qtItens][30];
	char descr[qtItens][255];
	
	valoresQuest = fopen(buffer1, "r");
	while (fgets(buffer3, 255, valoresQuest)) {
		if (i % 2 == 0) {
			strcpy(perfil[i/2], buffer3);
			perfil[i/2][strlen(perfil[i/2])-1] = 0;
			i++;
		} else {
			strcpy(descr[i/2], buffer3);
			if (i == (2*qtItens)-1) {
				descr[i/2][strlen(descr[i/2])] = 0;
			} else {
				descr[i/2][strlen(descr[i/2])-1] = 0;
			}
			i++;
		}
	}
	i = 0;
	fclose(valoresQuest);
//	getch(); // controle
	
    int x;
    x = 0;    
 //   char perfil[4][30];    
 //   strcpy(perfil[0], "Cinest�sico");
 //   strcpy(perfil[1], "Auditivo");
 //   strcpy(perfil[2], "Visual");
 //   strcpy(perfil[3], "Digital");

    char str1[10][70];//matriz de 10 strings com 70 bytes cada (sujeito a mudan�a).
    char letra[qtItens];
    for (i=0; i<qtItens; i++) {
    	letra[i] = 65 + i;
//    	printf("\n %c", letra[i]); // controle
	}
	
//	printf("\n %s", buffer2[aux-1]); // controle
	
	if (aux != j) {
		buffer2[aux-1][strlen(buffer2[aux-1])-1] = 0;
	}
    FILE* fp = fopen(buffer2[aux-1], "r");
    if (!fp) { //Mensagem de erro caso o arquivo n�o esteja presente no diret�rio
   		printf("Erro na abertura do arquivo...\n");
	}
	char buffer4[350];
	int qtFrases = -1;
	while (fgets(buffer4, 350, fp)) {
		qtFrases++;
	}
//	printf(" %d", qtFrases); // controle
	fclose(fp);
    
    int res[qtFrases][qtItens];
    
    int soma[qtItens];
    for (i=0; i<qtItens; i++) {
    	soma[i] = 0;
	}
    
    int y, k, m, n, count;
    
    int ver[255];
   		for (i=0; i< 3+ qtItens; i++) {
    	ver[i] = 0;
    	}
	
    
    i = -1;
    y = 1;
    fp = fopen(buffer2[aux-1], "r"); //Nesse arquivo, a maior string possui 69 caracteres, por isso aloquei 70 bytes por string
    if (!fp) //Mensagem de erro caso o arquivo n�o esteja presente no diret�rio
        printf("Erro na abertura do arquivo...\n");

    else {

        char frase[350]; //Buffer cont�m mem�ria tempor�ria para armazenar cada linha do arquivo
        char ignore[350]; //Buffer cont�m mem�ria tempor�ria para armazenar cada linha do arquivo

        while (fgets(frase, 350, fp)) { //Leitura da linha inteira e armazenamento em frase
                if(i == -1){
                   i++;
                } else {
                    for(k = 0; k < 3 + qtItens; k++){
                        ver[k] = 0;
                    }
                    printf("\n Nas frases a seguir, pontue com:\n");
                    int aux1;
                    for(aux1=qtItens; aux1>=1; aux1--) {
                    	if (aux1 == qtItens) {
                    		printf(" %d a que melhor te descreve;\n", aux1);
						} else if (aux1 == 1) {
							printf(" 1 aquela que menos te descreve.\n");
						} else {
							printf(" %d a pr�xima melhor descri��o;\n", aux1);
						}
					}
                    /* printf(" 4 a que melhor te descreve;\n");
                    printf(" 3 a pr�xima melhor descri��o;\n");
                    printf(" 2 a pr�xima melhor;\n");
                    printf(" 1 aquela que menos te descreve.\n"); */ 
                    
                    printf("\n Por favor, n�o digite o mesmo n�mero 2 vezes.\n\n");


                    char* imprimir = strtok(frase, "[=,]"); //Quebra a string "buffer" sempre que encontra = ou , (ou qualquer outro parametro) e armazena em "imprimir"
					k = -1;
                    while (imprimir) {

                    if (*imprimir <= 53 && *imprimir>=48) {
                        // printf(" %d\n", *imprimir-48); // caso ele leia um n�mero entre 0 e 5, ele printar� o n�mero. Serve para ler o No das quest�es e o valor resposta delas.
                    } else {
                        if (k == -1) {
                    		printf("%s\n", imprimir);
                    		k++;
			} else {
				printf(" %c -) %s\n", letra[k], imprimir); //sen�o, printar� a string de texto. Usada pra ler registrar as quest�es e poss�veis respostas.
                    		k++;
			}
                    }
                    imprimir = strtok(NULL, "[=,]"); //"imprimir" ganha valor NULL quando encontra = ou , (ou qualquer outro parametro) para indicar o fim de "imprimir"
                }
			k = 0;
                    printf("\n");
                    count = 0;
                      for(j = 0; j < qtItens;j++){
                            do {
                                printf("\n %c -) ", letra[j]);
                                scanf(" %d", &res[i][j]);
                                x = res[i][j];
                                
                                if (qtItens <= 4) {
                                	if( x < 1 || x > 4){
                                    printf(" N�mero inv�lido");
                                    y = 1;
                                    getchar();
	                                }
	                                else {
	                                    y = 0;
	                                    if(ver[x-1] == 1) {
	                                        printf(" Voc� n�o pode repetir os n�meros -- Escreva novamente a resposta \n");
	                                        y = 1;
	                                    }
	                                    else {
	                                        ver[x-1] = 1;
	                                    }
	                                }
								} else {
									if( x < 1 || x > qtItens){
                                    printf(" N�mero inv�lido");
                                    y = 1;
                                    getchar();
	                                }
	                                else {
	                                    y = 0;
	                                    if(ver[x-1] == 1) {
	                                        printf(" Voc� n�o pode repetir os n�meros -- Escreva novamente a resposta \n");
	                                        y = 1;
	                                    }
	                                    else {
	                                        ver[x-1] = 1;
	                                    }
	                                }
								}
								
                            }while(y == 1); // v <- 0
                    }
            i++;
            system("cls");

            }
        } //


        // Close the file
        fclose(fp);
    }
    // printf(" %s %s", nome, pront);
    FILE *questResp;
    char bufferNome[50];
    strcpy(bufferNome, "RESULTADO_");
    strcat(strcat(strcat(strcat(bufferNome, nome), " "), pront), ".txt");
    replacestr(bufferNome," ", "_");
	printf(" O arquivo %s foi gerado...\n Nele voc� poder� ver o resultado do question�rio.", bufferNome);
    questResp = fopen(bufferNome, "w");
    
	int total = 0;
	// printf("qtFrases: %d\nqtItens: %d", qtFrases, qtItens); // controle
    for(m = 0; m < qtFrases; m++){
        for(n = 0; n < qtItens; n++){
        	// printf("res %d\n", res[m][n]); controle
            	soma[n] += res[m][n];
            // printf("soma %d\n", soma[n]); controle
        }
    }
    for (i=0; i<qtItens; i++) {
    //	printf("soma %d\n", soma[i]); // controle
    		total = total + soma[i];
    //		printf("total %d\n", total); // controle
	}
    
    // printf(" %d", total); // controle
    // getch();

    int bigger;
    char perfilBigger[30];
    bigger = 0;
    fprintf(questResp, "%s", "Resultados");
    fprintf(questResp,"%s", "\n=========================================================================================================================================\n");

    for(m = 0; m < qtItens; m++){
        	fprintf(questResp,"    %4.2f %%   %s", 100 * (float)soma[m] / total, perfil[m]);
        if(soma[m] > bigger){
            bigger = soma[m];
            strcpy(perfilBigger, perfil[m]);
        }

    }

	// printf("\n %s\n %s", buffer1, buffer2[aux-1]); // controle
	// getch();
	
    //char fras[300] = "Algumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas chamadas auditivas.\n";
    fprintf(questResp,"%s", "\n=========================================================================================================================================\n");
    for (i=0; i<qtItens; i++) {
    	fprintf(questResp,"%s\n", descr[i]);
    	// printf(" %s\n", descr[i]); // controle
	}
    fprintf(questResp,"O seu perfil representacional �: %s", perfilBigger);
    fprintf(questResp, "\n=========================================================================================================================================\n");
	
	fclose(valoresQuest);
    fclose(questResp);
	
	sleep(1);
	printf("\n\n A fun��o REALIZAR encerrou...\n");
}

void visualizar() {
	printf(" A fun��o VISUALIZAR foi iniciada...\n");
	sleep(2);
	
	FILE *visQuest = fopen("questRegistrados.txt", "r");
	
	char buffer1[255];
	int j = 0;
	
	while(fgets(buffer1, 255, visQuest)) {
		j++;
	}
	char buffer2[j][255];
	
	printf(" Escolha o question�rio dentre os listados: \n");
	
	visQuest = fopen("questRegistrados.txt", "r");
	int i = 0;
	
	while (fgets(buffer1, 255, visQuest)) {
		strcpy(buffer2[i], buffer1);
		if (i < j) {
			printf(" %d - %s", i+1, buffer2[i]);
		}
		i++;
	}
	i = 0;
	printf("\n");
	int aux;
	scanf(" %d", &aux);
	while(aux < 1 || aux > j) {
		printf(" N�mero inv�lido... Favor escolher um dos n�meros listados acima: ");
		scanf(" %d", &aux);
	}
	
	fclose(visQuest);   	
    
//	printf(" %s", buffer1); // controle
	printf(" Foi escolhido: %s", buffer2[aux-1]);
	printf("\n Pressione qualquer tecla para continuar...                                           \n");
	getch();
	system("cls");
	
	// buffer2[aux-1][strlen(buffer2[aux-1])-1] = 0;
	printf("1 %s\n2 %s\n\n", buffer1, buffer2[aux-1]); // controle
	getch();

	int k;
    visQuest = fopen(buffer2[aux-1], "r");
    if (!visQuest)
        printf("Can't open file\n");
  
    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer3[350];
  
        int row = 0;
        int column = 0;
  
        while (fgets(buffer3, 350, visQuest)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            //if (row == 1)
            //    continue;
  
            // Splitting the data
            char* value = strtok(buffer3, "[,]");
            // printf("%d\n", row); // control
  
            while (value) {
                
				printf("%s\n", value);				
                value = strtok(NULL, "[,]");
                column++;
            }
            printf("\n");
        }
  
        // Close the file
        fclose(visQuest);
    }
	getch();
	
	
	
	
	
	sleep(1);
	printf("\n\n A fun��o REALIZAR encerrou...\n");
}

void sobre() {
	printf(" A fun��o SOBRE foi iniciada...\n");
	sleep(2);
	FILE *showQuest = fopen("questRegistrados.txt", "r");
	
	char buffer1[255];
	int j = 0;
	
	while(fgets(buffer1, 255, showQuest)) {
		j++;
	}
	char buffer2[j][255];
	
	printf("\n Escolha o question�rio dentre os listados: \n");
	
	showQuest = fopen("questRegistrados.txt", "r");
	int i = 0;
	
	while (fgets(buffer1, 255, showQuest)) {
		strcpy(buffer2[i], buffer1);
		if (i<j){
			printf("%d - %s", i+1, buffer2[i]);
		}
		i++;
	}
	printf("\n");
	i = 0;
	
	int aux;
	scanf(" %d", &aux);
	while(aux < 1 || aux > j) {
		printf(" N�mero inv�lido... Favor escolher um dos n�meros listados acima: ");
		scanf(" %d", &aux);
	}
	
	fclose(showQuest);
	
//	printf(" %s", buffer1); // controle
	printf(" Foi escolhido: %s", buffer2[aux-1]);
	printf("\n Pressione qualquer tecla para continuar...\n");
	getch();
	system("cls");
	
	char buffer3[255];
//	printf(" %s\n", buffer1); // controle
	sprintf(buffer1, "sobre_%s", buffer2[aux-1]);
//	printf(" %s\n", buffer1); // controle
	if(aux != j) {
		buffer1[strlen(buffer1)-1] = 0;
	}
//	printf(" %s\n", buffer1); // controle
	FILE *sobre = fopen(buffer1, "r");
	if (!sobre) {
		printf("Erro na abertura do arquivo...\n");
	} //Mensagem de erro caso o arquivo n�o esteja presente no diret�rio
        
	
	while (fgets(buffer3, 155, sobre)) {
		printf("%s", buffer3);
	}
	fclose(sobre);
	getch();
	printf("\n\n Pressione qualquer tecla para continuar...");
	sleep(1);
	printf("\n\n A fun��o SOBRE encerrou...\n");
}

void fim() {
	printf(" A fun��o FIM foi iniciada...\n");
	exit(1);
}

int replacestr(char *line, const char *search, const char *replace) //Declara��o da fun��o replacestr() que ser� usada para substituir " " por "_".
{
   int count;
   char *sp; // come�o do padr�o para leitura da string
// Tire o coment�rio abaixo ? para que a fun��o printe os par�metros usados: line, search e replace
   //printf("replacestr(%s, %s, %s)\n", line, search, replace); 
	
   if ((sp = strstr(line, search)) == NULL) { // Se ele n�o encontra a agulha "search" no palheiro "line", retorna 0 pois n�o h� o que substituir
      return(0);
   }
// defini��o inicial das vari�veis necess�rias:
   count = 1;
   int sLen = strlen(search); //search length
   int rLen = strlen(replace); //replace length
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
   memcpy(sp, replace, rLen); //copia "replace" pra dentro de "sp" alocando "rLen" bytes de mem�ria

   count += replacestr(sp + rLen, search, replace); //contador pra registrar quantas substitui��es foram feitas e efetu�las em cada repeti��o de "search" ap�s a primeira

   return(count);
}

int localeAcc(char *line)
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
