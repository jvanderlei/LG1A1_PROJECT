#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese");

	
    char str[338];
    int result, i;
    
 	FILE* f = fopen("TESTE_SISTEMA_REPRESENTACIONAL.txt", "r");
    
    for (result = 0; result != EOF;) {
    	result = fscanf(f, "%338[^;|\n]", str);

    	if (result == 0){
    		result = fscanf(f, "%c");
		} else {
			printf("%s\n", str);
		}
	}
	
	//for (i = 0; i < 3; i++) {
	//	printf("O seu valor de 'i' : %d\n", i);
	//	}

	printf("A§ : ç; A£ : ã; Aµ : õ; é; A% : É; Aª : ê; A  : à; ú; A- : í; ô; A3 : ó; â; A¡ : á");
    return 0;
}
