#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int replacestr(char *line, const char *search, const char *replace) //Declaração da função replacestr() que será usada para substituir " " por "_".
{
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

   count += replacestr(sp + rLen, search, replace); //contador pra registrar quantas substituições foram feitas

   return(count);
}
  
// Driver Code
int main()
{
	setlocale(LC_ALL,"");
    // Substitute the full file path
    // for the string file_path
    char str1[10][70]; //matriz de 10 strings com 70 bytes cada (sujeito a mudança).
    int i,j;
    FILE* fp = fopen("TESTE_SISTEMA_REPRESENTACIONAL_ASCI.txt", "r"); //Nesse arquivo, a maior string possui 69 caracteres, por isso aloquei 70 bytes por string
  
    if (!fp) //Mensagem de erro caso o arquivo não esteja presente no diretório
        printf("Can't open file\n");
  
    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[350]; //Buffer contém memória temporária para armazenar cada linha do arquivo
  
        int row = 0;
        int column = 0;
  
        while (fgets(buffer, 350, fp)) { //Leitura da linha inteira e armazenamento em buffer
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            //if (row == 1)
            //    continue;
  
            // Dividindo a string:
            char* value = strtok(buffer, "[=,]"); //Quebra a string "buffer" sempre que encontra = ou , (ou qualquer outro parametro) e armazena em "value"
            printf("%d\n", row);
  
            while (value) {
                
                if (*value < 53 && *value>=48) {
                	printf(" %d\n", *value-48); // caso ele leia um número entre 0 e 5, ele printará o número. Serve para ler o No das questões e o valor resposta delas.
				} else {
					printf(" %s\n", value); //senão, printará a string de texto. Usada pra ler registrar as questões e possíveis respostas.
				}
				replacestr(value, " ", "_"); //Aqui puxei a função replacestr() para ver se funciona sem a necessidade de armazenar dentro da str1[10][70]
				strcpy(str1[column], value); //Aqui usei strcpy pra armazenar cada string lida em value dentro de str1[column]
                value = strtok(NULL, "[=,]"); //"value" ganha valor NULL quando encontra = ou , (ou qualquer outro parametro) para indicar o fim de "value"
                column++;
            }
  			//Maneira alternativa de printagem:
			for (i=0; i<10; i++) {
    			printf(" %s\n", str1[i]); //printa individualmente cada string armazenada em str1 pela fn strcpy. Como veio depois da função replacestr(), esta printagem deve conter as substituições.
			}
            printf("\n");
        }
  
        // Close the file
        fclose(fp);
    }    
    /*fp = fopen("TESTE_SISTEMA_REPRESENTACIONAL.txt", "a");
   	 fprintf(fp,"\nç à á â ã é ê í ó ô õ ú");
    fclose(fp);*/
    return 0;
}
