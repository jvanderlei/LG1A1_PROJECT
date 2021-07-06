#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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

char tabela[6][8][70] = {};

int main()
{
	setlocale(LC_ALL,"Portuguese");
	
    char str[70];
    int result, i, j, aux;
    
 	FILE* f = fopen("TESTE_SISTEMA_REPRESENTACIONAL.txt", "r");
    
    for (result = 0, i = 0, j = 0; result != EOF;) {
    	result = fscanf(f, "%70[^;|=\n]", str);

    	if (result == 0){
    		result = fscanf(f, "%c");
		} else {
			if (i < 7 || (i==7 && j==5)) {
				for (aux = 0; aux < strlen(str); aux++) {
					tabela[j][i][aux] = str[aux];
				}
				printf("ixj : %dx%d\n", i, j);
				i++;
			} else if (j != 5) {
				for (aux = 0; aux < strlen(str); aux++) {
					tabela[j][i][aux] = str[aux];
				}
				printf("ixj : %dx%d\n", i, j);
				i = 0;
				j++;
			}
		}
	}
		/*  replacestr(str, "A§", "ç");
			replacestr(str, "A£", "ã");
			replacestr(str, "Aµ", "õ");
			replacestr(str, "A%", "É");
			replacestr(str, "Aª", "ê");
			replacestr(str, "A ", "à");
			replacestr(str, "A-", "í");
			replacestr(str, "A3", "ó");
			replacestr(str, "A¡", "á"); */
	
	for(i=0;i<6;i++)
	{
		for(j=0;j<8;j++)
		{
			for(aux=0;aux<70;aux++)
			{
				printf("\t%c", tabela[i][j][aux]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("A§ : ç; A£ : ã; Aµ : õ; é; A% : É; Aª : ê; A  : à; ú; A- : í; ô; A3 : ó; â; A¡ : á");
    return 0;
}
