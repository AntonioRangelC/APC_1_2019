#include <stdio.h>
//objetivo: mostrar o ganhador de uma partida de par ou impar
//entrada: nomes dos jogadores e o valor da jogada
//saida: nome do ganhador de cada rodada
int main (){
	int n,rodadas[1001],soma=0,aux,jogada1,jogada2,contador,contadorTestes=0;
	char primeiroNome[10],segundoNome[10];
		scanf("%d",&n);
		  while(n>0){
		  	//printf("Digite o nome do primeiro jogador\n");
		  	scanf("%s",primeiroNome);
		  	//printf("Digite o nome do segundo jogador\n");
		  	scanf("%s",segundoNome);
		  	for(aux=0;aux<n;aux++){
		  	//	printf("Rodada %d\n",aux+1);
		  		scanf("%d",&jogada1);
		  		scanf("%d",&jogada2);
		  		soma = jogada1 + jogada2;
		  		rodadas[aux]=soma;
			  }
			  contadorTestes++;
			  printf("Teste %d\n",contadorTestes);
			for(contador=0;contador<n;contador++){
				if(rodadas[contador] % 2 == 0){
					printf("%s\n",primeiroNome);
				}
				else if(rodadas[contador] % 2 == 1){
					printf("%s\n",segundoNome);
				}
			}
			scanf("%d",&n);
		  }
}
