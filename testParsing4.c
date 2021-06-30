#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

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
  
// Driver Code
int main()
{
	setlocale(LC_ALL,"");
    // Substitute the full file path
    // for the string file_path
    char str1[10][70];
    int i,j;
    FILE* fp = fopen("TESTE_SISTEMA_REPRESENTACIONAL_ASCI.txt", "r");
  
    if (!fp)
        printf("Can't open file\n");
  
    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[350];
  
        int row = 0;
        int column = 0;
  
        while (fgets(buffer, 350, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            //if (row == 1)
            //    continue;
  
            // Splitting the data
            char* value = strtok(buffer, "[=,]");
            printf("%d\n", row);
  
            while (value) {
                
                if (*value < 53 && *value>=48) {
                	printf(" %d\n", *value-48);
				} else {
					printf(" %s\n", value);
				}
				replacestr(value, " ", "_");
				strcpy(str1[column], value);
                value = strtok(NULL, "[=,]");
                column++;
            }
  			
			for (i=0; i<10; i++) {
    			printf(" %s\n", str1[i]);	
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
