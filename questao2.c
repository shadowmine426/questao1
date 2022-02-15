#include <stdio.h>
#include <stdlib.h>
/*
Marcos Luiz Landim Junqueira
14/02/2022   
*/
int main () {
	char senha[32];
	int tamanho;
  	
  	//leitura da string até a quebra de linha
	printf("Escreva uma senha.\n");
  	for (int i=0;;i++) {
		scanf("%c",&senha[i]);
		if(senha[i]=='\n') {
			tamanho=i;
			break;
		}
	}
	
  	// se o tamanho dela estiver no intervalo de 6 
	if (tamanho == 1) {
		printf("falta 5 digitos");
	}if (tamanho == 2) {
		printf("falta 4 digitos");
	}if (tamanho == 3) {
		printf("falta 3 digitos");
	}if (tamanho == 4) {
		printf("falta 2 digitos");
	}
  if (tamanho == 5) {
		printf("falta 1 digitos");
	}
  if (tamanho >= 6) {
		printf("senha cadastrada com sucesso");
	}
    
  
  return 0;
  }