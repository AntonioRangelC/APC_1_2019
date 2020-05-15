#include <stdio.h>
#include <string.h>
#define MAX_TAM 61
//prototipos
int validaRisada(char risada[MAX_TAM]);
int ehEngracada(char risada[MAX_TAM]);
//objetivo: analisar se uma risada � engra�ada ou n�o
//entrada: risada 
//sa�da: uma linha dizendo se a risada � engra�ada, ou n�o ou inv�lida
int main (){
	char risada[MAX_TAM]="";
	int valida;
	scanf("%[^\n]",risada);
	valida=validaRisada(risada);
	if(valida==1){
		if(ehEngracada(risada)==0){
			printf("N\n");
		}
		else if(ehEngracada(risada)==1){
			printf("S\n");
		}
	}
	else if(valida==0){
		printf("Valor invalido!\n");
	}
	return 0;
}
//objetivo: validar a risada
//parametros: risada
//sa�da: 0 se for invalida, 1 se for valida
int validaRisada(char risada[MAX_TAM]){
	int aux;
	if(strlen(risada)<=0 || strlen(risada)>=MAX_TAM){
		return 0;
	}
	else if(strlen(risada)>0 && strlen(risada)<MAX_TAM){
		for(aux=0;aux<strlen(risada);aux++){
			if(risada[aux]=='a' || risada[aux]=='e'|| risada[aux]=='i' ||risada[aux]=='o' || risada[aux]=='u'){
				return 1;
			}
				
		}
	  return 0;
	}
	
}
//objetivo: verificar se a risada � engra�ada
//parametros: risada
//sa�da: 0 se for nao engra�ada, 1 se for engra�ada
int ehEngracada(char risada[MAX_TAM]){
	int aux,auxVogais=0,indo,tamanho;
	char vogais[MAX_TAM]="";
	
	for(aux=0;aux<strlen(risada);aux++){
		if(risada[aux]=='a'|| risada[aux]=='e'|| risada[aux]=='i'|| risada[aux]=='o'|| risada[aux]=='u'){
			vogais[auxVogais]= risada[aux];
			auxVogais++;
		}
	}
	vogais[auxVogais]='\0';
	tamanho=strlen(vogais);
	//printf("vogais: %s\n",vogais);
	for(indo=0;indo<tamanho/2;indo++){
		if(vogais[indo] != vogais[tamanho - 1 - indo]){
			return 0;
		}
	}
	return 1;
}
