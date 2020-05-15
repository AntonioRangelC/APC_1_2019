
#include <stdio.h>

//revisão ponteiros
//objetivo: digitar idades e validar
//entrada: idades
//saida: idades validadas
//prototipo
void validaIdade(int *idade, int aux);
int main(){
	int idade[100],aux,qtd;
	printf("Digite a quantidade\n");
	scanf("%d",&qtd);
	  for(aux=0;aux<qtd;aux++){
	  	printf("Digite a idade %d\n",aux+1);
	  	scanf("%d",&idade[aux]);
	  	validaIdade(idade,aux);
	  }
	  for(aux=0;aux<qtd;aux++){
	  	printf("idade %d e : %d\n",aux+1,idade[aux]);
	  }
	return 0;
}
void validaIdade(int *idade, int aux){
	while(*idade <= 0){
		printf("invalido\n");
		scanf("%d",&idade[aux]);
	}
}
