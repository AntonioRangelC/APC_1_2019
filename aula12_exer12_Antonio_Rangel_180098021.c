#include <stdio.h>
//objetivo:
//entrada:
//saída:
int main(){
	int	matriz[4][4],linha,coluna,k,j;
	scanf("%d",&k);
		for(linha=0;linha<4;linha++){
			for(coluna=0;coluna<4;coluna++){
				scanf("%d",matriz[linha][coluna]);
			}
			for(j=0;j<linha;j++){
			printf("%d",matriz[linha][coluna]*k);
			}
		}
		
	
	return 0;
}
