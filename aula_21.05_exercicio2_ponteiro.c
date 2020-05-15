#include <stdio.h>
//prototipo reajuste
float reajuste(float reajuste, float* precoAtual);

//objetivo: mostrar o novo preço depois de um reajuste
//entrada: preço e reajuste
//saida: novo preço
int main (){
	float reajuste,precoAtual;
	do{
		printf("Digite o preco do produto, ou digite '0' para sair\n");
		scanf("%f",&precoAtual);
		printf("Digite o percentual do reajuste, ou digite 0 para sair\n");
		scanf("%f",&reajuste);
		printf("Novo Preco :\n",precoAtual);
		reajuste(reajuste,&precoAtual);
	}while(precoAtual!=0);
	return 0;
}
void reajuste(float reajuste, float *precoAtual){
	(*precoAtual)= (reajuste/100) * (*precoAtual);
	return 0;
}

