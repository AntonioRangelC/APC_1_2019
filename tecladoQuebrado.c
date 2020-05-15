#include <stdio.h>
#include <string.h>
int main (){
	char quebradas[21],frase[100],auxiliar[100];
	int linhas,colunas,aux=0,i;
	printf("Digite as teclas que estao quebradas\n");
	fflush(stdin);
	fgets(quebradas,21,stdin);
	printf("Digite a frase\n");
	fflush(stdin);
	fgets(frase,100,stdin);
	for(linhas=0;linhas<strlen(quebradas);linhas++){
		for(colunas=0;colunas<strlen(frase);colunas++){
			if(frase[colunas] == quebradas[linhas]){
				frase[colunas]='*';
			}
		}
	}
	for(i=0;i<strlen(frase);i++){
		if(frase[i] != '*'){
			auxiliar[aux]=frase[i];
			aux++;
		}
	}
	printf("Frase: %s\n",auxiliar);
	return 0;
}
