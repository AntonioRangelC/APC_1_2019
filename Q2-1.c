//Síntese:
// Objetivo: Verificar se risada digital eh muito engraçada ou nao
// Entrada: risada
// Saida: e ou nao engracada
#include<stdio.h>
#include<string.h>
#define MAX_TAM 60
int validaRisada(char risada[MAX_TAM]);
char ehEngracada(char risada[MAX_TAM]);
int main()
{
    char risada[MAX_TAM];

	// Entrada exigida
    scanf("%s", &risada);
    
    if(!validaRisada(risada))
    	printf("Valor invalido!");
    else
    {
	    // Saida exigida
		if (ehEngracada(risada))
	    	printf("S");
		else
			printf("N");
	}
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

//Objetivo: analise se risada eh muito engracada ou nao
//Parâmetros: risada
//Retorno: analise da risada ser muito engracada
char ehEngracada(char risada[MAX_TAM])
{
    int aux, outra, tamanho;
    tamanho = strlen(risada);
    if(tamanho == 1)  {
    	switch(risada[aux+1]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				return 'S';
				break;
			default:
				return 'N';
		}
	}
	else {
      for(aux=0; aux < tamanho-1; aux++)
      {
       	switch(risada[aux]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				return 'S';
			}
		}
	}
	return 'N';
}
