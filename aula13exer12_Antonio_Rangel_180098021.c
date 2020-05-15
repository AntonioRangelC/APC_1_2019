#include <stdio.h>
#define L 2
#define C 50
//objetivo: mostrar os números pares e ímpares e suas quantidades em uma matriz
//entrada: numeros
//saída: matriz com numeros pares na primeira linha, e numeros pares na segunda
void fazParidade(int *pNumeros, int matriz[L][C]);
void mostraDados(int *pContadoresPares,int *pContadoresImpares,int matriz[L][C]);
int main(){
	int qtd,numeros[100],aux,linhas,contadorPares=0,contadorImpares=0,matriz[L][C]={};
	printf("Digite a quantidade\n");
	scanf("%d",&qtd);
		for(aux=0;aux<qtd;aux++){
			printf("Digite o numero %d\n",aux+1);
			scanf("%d",&numeros[aux]);
			if(numeros[aux] % 2 ==0){
				contadorPares++;
			}
			else if(numeros[aux] % 2 ==1){
				contadorImpares++;
			}
		}
	    fazParidade(numeros,matriz);
		mostraDados(&contadorPares,&contadorImpares,matriz);
	return 0;
}
//objetivo: transformar o vetor em uma matriz
//parametros: numeros lidos, matriz
//retorno: nenhum
void fazParidade(int *pNumeros,int matriz[L][C]){
	int colunas,auxPar=0,auxImpar=0;
	for(colunas=0;colunas<50;colunas++){
		if(pNumeros[colunas]%2==0){
			matriz[0][auxPar]=pNumeros[colunas];
			auxPar++;
		}
		else if(pNumeros[colunas]%2==1){
			matriz[1][auxImpar]=pNumeros[colunas];
			auxImpar++;
		}
	}
	
}
//objetivo: imprimir a matriz
//parametros: contadores, matriz
//retorno: nenhum
void mostraDados(int *pContadoresPares,int *pContadoresImpares,int matriz[L][C]){
	int linhas,colunas;
	for(linhas=0;linhas<2;linhas++){
			if(linhas==0){
				for(colunas=0;colunas<*pContadoresPares;colunas++){
					printf("%d ",matriz[linhas][colunas]);
				}
				printf("\n");
			}
			else if(linhas==1){
				for(colunas=0;colunas<*pContadoresImpares;colunas++){
					printf("%d ",matriz[linhas][colunas]);
				}
				printf("\n");
			}
		}
		printf("Quantidade de pares: %d\n",*pContadoresPares);
		printf("Quantidade de impares: %d\n",*pContadoresImpares);
	
}
