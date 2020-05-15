#include <stdio.h>
//objetivo: mostrar a posiçao dos numeros pares e impares de um vetor
//entrada: quantidade de numeros do vetor, numeros do vetor
//saida: posiçao dos numeros pares e posiçao dos numeros impares
int main (){
	int n,aux,auxPares=0,auxImpares=0,auxiliar;
		scanf("%d",&n);
		int vetor[n],impares[n],pares[n];
		  for(aux=0;aux<n;aux++){
		  	scanf("%d",&vetor[aux]);
		  	if(vetor[aux] % 2 ==0){
		  		pares[auxPares] = aux;
		  		auxPares++;
			  }
			else if(vetor[aux] % 2 != 0){
				impares[auxImpares] = aux;
				auxImpares++;
			}
		  }
		  for(auxiliar=0;auxiliar<auxPares;auxiliar++){
		    if(auxiliar == auxPares-1){
		    	printf("%d\n",pares[auxiliar]);
			}
		    else 
				printf("%d ",pares[auxiliar]);
		  
		  }
		  //printf("\n");
		  for(auxiliar=0;auxiliar<auxImpares;auxiliar++){
		  	if(auxiliar == auxImpares-1){
		  		printf("%d\n",impares[auxiliar]);
			  }
			else 
			  printf("%d ",impares[auxiliar]);
			
		  }
		  //printf("\n");
		  
	return 0;
}
