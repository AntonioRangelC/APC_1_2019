#include<stdio.h>
//objetivo: achar o segundo e o terceiro menor numero de um vetor
//entrada: numero de casos de teste, numeros do vetor
//saida: segundo e terceiro menor numero
int main (){
	int n,vetor[10000]={},aux1,aux2,aux3,primeiroMenor=100000,segundoMenor=100000,terceiroMenor=100000;
	  scanf("%d",&n);
		for(aux1=0;aux1<n;aux1++){
			scanf("%d",&vetor[aux1]);
			if(vetor[aux1]<primeiroMenor){
				primeiroMenor = vetor[aux1];
			}
		}
		for(aux2=0;aux2<n;aux2++){
			if(vetor[aux2] != primeiroMenor && vetor[aux2]<segundoMenor){
				segundoMenor = vetor[aux2];
			}
		}
		for(aux3=0;aux3<n;aux3++){
			if(vetor[aux3] != primeiroMenor && vetor[aux3] != segundoMenor  && vetor[aux3]<terceiroMenor){
				terceiroMenor = vetor[aux3];
			}

		}

//	printf("Primeiro menor : %d\n",primeiroMenor);
	printf("%d\n",segundoMenor);
	printf("%d\n",terceiroMenor);
		return 0;
}
