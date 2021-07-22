
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
		realizar("MASTER", "MASTER");
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
	
	// Registrando o nome do questionário para uso nas funções realizar() e visualizar();
	FILE *questRegister, *questNovo;
	questRegister = fopen("questRegistrados.txt", "a");
	
	printf(" Digite o nome do questionário: ");
	gets(buffer1);
	// localeAcc() é uma função que fiz para consertar a acentuação por conta de uma incompatibilidade entre a locale.h e a stdio.h;
	localeAcc(buffer1);
	replacestr(buffer1, " ", "_"); // Subst. " " por "_" para facilitar o acesso;
	strncat(buffer1, ".txt", 4); // Concatena ".txt" ao fim da string buffer1 que contém o nome do arquivo;

	printf(" O nome %s foi registrado...\n", buffer1);
	
	fprintf(questRegister, "%s\n", buffer1);
	
	fclose(questRegister);
	
	//Definição de alguns parâmetros (qtd de frases/perguntas e itens resposta por frase) pelo usuário para customização do questionário;
	printf(" Informe quantas frases o questionário terá: ");
	scanf(" %d", &qtFrases);
	
	printf(" Informe quantos itens de resposta terão em cada frase: ");
	scanf(" %d", &qtItens);
	fflush(stdin);
	
	// Criação do arquivo do questionário
	questNovo = fopen(buffer1, "w");
	
	char quest[qtFrases+1][qtItens+2][255];
	
	// Definição da primeira linha da matriz "quest[][][]", que será padronizada;
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
	
	// Input das frases e de seus itens (as demais linhas);
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
	
	// Registro das informações inputadas no arquivo criado;
	for (i=0; i<qtFrases+1; i++) {		
		for (j=0; j<qtItens+2; j++) {			
							
				fprintf(questNovo, "%s", quest[i][j]);
				
				// Formatação de espaços no arquivo;
					for (k=0; k<qtFrases+1; k++) {					
						if (strlen(quest[k][j]) >= aux1) {						
							aux1 = strlen(quest[k][j]);						
						}
					}

					aux1 = aux1 - strlen(quest[i][j]);

					for (k=0; k<aux1; k++) {
						fprintf(questNovo, " ");
					}
			
			// Formatação das vírgulas para leitura do arquivo;	
			if (j < qtItens+1) {
				
				fprintf(questNovo, " , ");
				
				}
			// Resetando aux1 para que seja usado quando a formatação da próxima coluna comece;
			aux1 = 0;
		}	
		
		//Fim da linha gera um \n
		if (i<qtFrases) {
			fprintf(questNovo, "\n");
		}
	}
	
	fclose(questNovo);
	
	sleep(2);
	printf(" A função CADASTRAR encerrou...\n");
	
}

void realizar(char nome[255], char pront[10]) { //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //  REALIZAR  //
	printf(" A função REALIZAR foi iniciada...\n\n");
	sleep(2);
	system("cls");
	setlocale(LC_ALL,"");
    int x;
    x = 0;
    char perfil[4][30];
    strcpy(perfil[0], "Cinestésico");
    strcpy(perfil[1], "Auditivo");
    strcpy(perfil[2], "Visual");
    strcpy(perfil[3], "Digital");

//    for(int o = 0; o < 4; o++){
//        strcpy(perfil[o], <Variavel do perfil representacional>)
//    }
    char str1[10][70];//matriz de 10 strings com 70 bytes cada (sujeito a mudança).
    char letra[4] = {'A', 'B', 'C', 'D'};
    int res[5][4];
    int soma[4] = {0,0,0,0};
    int i, y, k, j, m, n, count;
    int ver[4] = {0, 0, 0, 0};
    i = -2;
    y = 1;
    FILE* fp = fopen("TESTE_SISTEMA_REPRESENTACIONAL_ASCI.txt", "r"); //Nesse arquivo, a maior string possui 69 caracteres, por isso aloquei 70 bytes por string

    if (!fp) //Mensagem de erro caso o arquivo não esteja presente no diretório
        printf("Erro na abertura do arquivo...\n");

    else {

        char frase[350]; //Buffer contém memória temporária para armazenar cada linha do arquivo
        char ignore[350]; //Buffer contém memória temporária para armazenar cada linha do arquivo

        while (fgets(frase, 350, fp)) { //Leitura da linha inteira e armazenamento em frase
                if(i == -2 || i == -1 || i == 5){
                   i++;
                } else {
                    for(k = 0; k < 4; k++){
                        ver[k] = 0;
                    }
                    printf("\n Nas frases a seguir, pontue com:\n");
                    printf(" 4 a que melhor te descreve;\n");
                    printf(" 3 a próxima que melhor descrição;\n");
                    printf(" 2 a próxima melhor;\n");
                    printf(" 1 aquela que menos te descreve.\n");
                    printf("\n Por favor, não digite o mesmo número 2 vezes.\n\n");


                    char* imprimir = strtok(frase, "[=,]"); //Quebra a string "buffer" sempre que encontra = ou , (ou qualquer outro parametro) e armazena em "imprimir"
			k = 0;
                    while (imprimir) {

                    if (*imprimir <= 53 && *imprimir>=48) {
                        // printf(" %d\n", *imprimir-48); // caso ele leia um número entre 0 e 5, ele printará o número. Serve para ler o No das questões e o valor resposta delas.
                    } else {
                        if (k == 0) {
                    		printf(" %s\n", imprimir);
                    		k++;
			} else {
				printf(" %c -) %s\n", letra[k-1], imprimir); //senão, printará a string de texto. Usada pra ler registrar as questões e possíveis respostas.
                    		k++;
			}
                    }
                    imprimir = strtok(NULL, "[=,]"); //"imprimir" ganha valor NULL quando encontra = ou , (ou qualquer outro parametro) para indicar o fim de "imprimir"
                }
			k = 0;
                    printf("\n");
                    count = 0;
                      for(j = 0; j < 4;j++){
                            do {
                                printf("\n %c -) ", letra[j]);
                                scanf(" %d", &res[i][j]);
                                x = res[i][j];
                                if( x < 1 || x > 4){
                                    printf(" Número inválido");
                                    y = 1;
                                    getchar();
                                }
                                else {
                                    y = 0;
                                    if(ver[x-1] == 1) {
                                        printf(" Você não pode repetir os números -- Escreva novamente a resposta \n");
                                        y = 1;
                                    }
                                    else {
                                        ver[x-1] = 1;
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
    strcat(strcat(strcat(nome, " "), pront), ".txt");
    replacestr(nome," ", "_");
	printf(" O arquivo %s foi gerado...\n Nele você poderá ver o resultado do questionário.", nome);
    questResp = fopen(nome, "w");

    for(m = 0; m < 5; m++){
        for(n = 0; n < 4; n++){
            soma[n] += res[m][n];
        }
    }

    int bigger;
    char perfilBigger[30];
    bigger = 0;
    fprintf(questResp, "%s", "Resultados");
    fprintf(questResp,"%s", "\n======================================================================================================================================\n");

    for(m = 0; m < 4; m++){
        fprintf(questResp,"   %d %%   %s", 2* soma[m], perfil[m]);
        if(soma[m] > bigger){
            bigger = soma[m];
            strcpy(perfilBigger, perfil[m]);
        }

    }

    //char fras[300] = "Algumas pessoas captam melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas.\n";
    fprintf(questResp,"%s", "\n=========================================================================================================================================\n");
    fprintf(questResp,"%s", "Algumas pessoas captam melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas.\n");
    fprintf(questResp,"%s", "Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais.\n");
    fprintf(questResp,"%s", "As cinestésicas aprendem melhor por meio das sensações táteis, como o tato, a temperatura, a umidade, as sensações internas e as emoções.\n");
    fprintf(questResp,"%s", "Já as pessoas visuais aprendem melhor quando se valem da visão.\n");
    fprintf(questResp,"%s %s", "O seu perfil representacional é:", perfilBigger);
    fprintf(questResp,"%s", "\n=========================================================================================================================================\n");

    fclose(questResp);
	
	sleep(1);
	printf("\n\n A função REALIZAR encerrou...\n);
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
   char *sp; // começo do padrão para leitura da string
// Tire o comentário abaixo ↓ para que a função printe os parâmetros usados: line, search e replace
   //printf("replacestr(%s, %s, %s)\n", line, search, replace); 
	
   if ((sp = strstr(line, search)) == NULL) { // Se ele não encontra a agulha "search" no palheiro "line", retorna 0 pois não há o que substituir
      return(0);
   }
// definição inicial das variáveis necessárias:
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
   memcpy(sp, replace, rLen); //copia "replace" pra dentro de "sp" alocando "rLen" bytes de memória

   count += replacestr(sp + rLen, search, replace); //contador pra registrar quantas substituições foram feitas e efetuá-las em cada repetição de "search" após a primeira

   return(count);
}

int localeAcc(char *line) //  LOCALE ACC  //  LOCALE ACC  //  LOCALE ACC  //  LOCALE ACC  //  LOCALE ACC  //  LOCALE ACC  //  LOCALE ACC  //  LOCALE ACC  //  LOCALE ACC  //  LOCALE ACC  //  LOCALE ACC  // 
{
	int i;
	int aux = strlen(line);
	for (i=0; i<aux; i++) {
		switch ((int)line[i]) {
			
			// fix para à
			case -123 : {
				line[i] = 224;
				break;
			}
				
			//fix para á
			case -96 : {
				line[i] = 225;
				break;
			}
				
			// fix para â
			case -125 : {
				line[i] = 226;
				break;
			}
				
			// fix para ç
			case -121 : {
				line[i] = 231;
				break;
			}
				
			// fix para é
			case -126 : {
				line[i] = 233;
				break;
			}
				
			// fix para ê
			case -120 : {
				line[i] = 234;
				break;
			}
				
			// fix para í
			case -95 : {
				line[i] = 237;
				break;
			}
				
			// fix para ó
			case -94 : {
				line[i] = 243;
				break;
			}
				
			// fix para ô
			case -109 : {
				line[i] = 244;
				break;
			}
				
			// fix para ú
			case -93 : {
				line[i] = 250;
				break;
			}
				
			// fix para É
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
