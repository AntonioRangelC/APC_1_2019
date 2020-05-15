#include <stdio.h>
#include<string.h>
#define MAX_TAM 1001
//objetivo: decodificar uma frase na lingua do p e escreve-la de forma normal
//entrada: frase na lingua do p
//saida: frase em portugues comum
int main (){
	char string[MAX_TAM];
	int contador=1,tamanho;
		scanf("%1000[^\n]",string);
		tamanho = strlen(string);
	   for(contador=1;contador<tamanho;contador+=2){
	   	   printf("%c",string[contador]);
	   		if(string[contador+1]==' '){
	   			printf("%c",string[contador+1]);
	   			contador++;
			}
	    
		}
		printf("\n");
	return 0;
}
