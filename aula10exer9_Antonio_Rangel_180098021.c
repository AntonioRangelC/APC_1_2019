#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
//objetivo: mostrar a frase digitada maiuscula, e a quantidade de espaços em branco
//entrada: frase
//saída: a frase maiuscula e a quantidade de espaçoes em branco
int main() {
	char frase[25],auxiliar[25];
	int aux,contadorEB=0;
		gets(frase);
		strcpy(auxiliar,frase);
		 system("cls");
		 printf("\n");
		  for(aux=0;aux<strlen(frase);aux++){
		  	 if(auxiliar[aux]==' '){
		  	 	contadorEB++;
		  	 	printf(" ");
		     }
		     else{
		     	printf("%c",toupper(auxiliar[aux]));
			 }
		  }
		  printf("\n");
		  printf("Quantidade de espacos em branco : %d\n",contadorEB);
		  
	return 0;
}
