#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese");

	
    char str[336];
    int result, i;
    
 	FILE* f = fopen("TESTE_SISTEMA_REPRESENTACIONAL.txt", "r");
    
    for (result = 0; result != EOF;) {
    	result = fscanf(f, "%336[^;|\n]", str);

    	if (result == 0){
    		result = fscanf(f, "%c");
		} else {
			printf("%s\n", str);
		}
	}
	
	//for (i = 0; i < 3; i++) {
	//	printf("O seu valor de 'i' : %d\n", i);
	//	}

	printf("A� : �; A� : �; A� : �; �; A% : �; A� : �; A� : �; �; A- : �; �; A3 : �; �; A� : �");
    return 0;
}
