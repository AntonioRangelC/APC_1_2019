//Síntese:
// Objetivo: Avaliar a risada digital mais engraçada
// Entrada: risada
// Saida: indica se risada eh mais engracada

#include <stdio.h>
#include <string.h>

#define MAX_TAM 60

int validaRisada(char risada[MAX_TAM]);
void removeCaracter(char str[MAX_TAM], int pos);
void removeConsoantes(char risada[MAX_TAM]);
int ehEngracada(char risada[MAX_TAM]);

int main(){

	char risada[MAX_TAM];

	// ENTRADA
	scanf("%s", risada);

	if(validaRisada(risada)){
		removeConsoantes(risada);
		
		// SAIDA
		if(ehEngracada(risada))
			printf("S");
		else
			printf("N");
	}
	else
		printf("Valor invalido!\n");

	return 0;
}


//=====================================SUBPROGRAMAS=============================

//Objetivo: Validar a risada
//Parâmetros: risada
//Retorno: situacao da risada
int validaRisada(char risada[MAX_TAM])
{
	int aux, tamanho;
	tamanho = strlen(risada);
    if((tamanho == 0) || (tamanho >= MAX_TAM))
	    return 0;
	else{
		for (aux=0; aux < tamanho; aux++)
			switch(risada[aux]) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					return 1;
			}
		return 0;
	}
	    
}

//Objetivo: remove caracter da risada
//Parâmetros: risada e a posicao
//Retorno: sem retorno
void removeCaracter(char str[MAX_TAM], int pos){

	while(str[pos + 1] != '\0'){
		str[pos] = str[pos + 1];
		pos++;
	}
	str[pos] = '\0';
	return;
}

//Objetivo: remove as consoantes da risada
//Parâmetros: risada
//Retorno: sem retorno
void removeConsoantes(char risada[MAX_TAM]){
	int aux,tam;

    tam = strlen(risada);
	for(aux = 0; aux < tam; aux++){
		if(risada[aux] != 'a' &&	risada[aux] != 'e' && risada[aux] != 'i' &&
		   risada[aux] != 'o' &&	risada[aux] != 'u')
		{
			removeCaracter(risada, aux);
			aux--;
			tam--;
		}
	}
	return;
}

//Objetivo: Verificar se risada eh mais engracada
//Parâmetros: risada
//Retorno: indicacao da risada ser mais engracada
int ehEngracada(char risada[MAX_TAM]){
	int aux,tam;

	tam = strlen(risada);
	for(aux = 0; aux < tam/2; aux++){
		if(risada[aux] != risada[tam - 1 - aux]){
			return 0;
		}
	}
	return 1;
}

