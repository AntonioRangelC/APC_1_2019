#include <stdio.h>
//prototipos
void fazPorcentagem(float *pPrecoAtual, float *pPorcentagem);
void validaPrecoAtual(float *pPrecoAtual);
//objetivo: calcular o pre�o final a partir de um percentual de reajuste
//entrada: pre�o atual e percentual de reajuste
//sa�da: novo pre�o
int main(){
	float precoAtual,porcentagem;
	printf("Insira o preco atual do produto, ou aperte 0 para sair\n");
	scanf("%f",&precoAtual);
		while(precoAtual!=0){
			validaPrecoAtual(&precoAtual);
			printf("Insira o percentual de reajuste\n");
			scanf("%f",&porcentagem);
			fazPorcentagem(&precoAtual,&porcentagem);
			printf("Insira o preco atual do produto, ou aperte 0 para sair\n");
			scanf("%f",&precoAtual);
		}
	return 0;
}
//objetivo: validar o pre�o atual
//parametros: pre�o atual
//retorno: nenhum
void validaPrecoAtual(float *pPrecoAtual){
	while(*pPrecoAtual<0){
		printf("Preco invalido, digite novamente\n");
		scanf("%f",pPrecoAtual);
		if(*pPrecoAtual==0){
			break;
		}
	}
}
//objetivo: fazer o calculo do novo pre�o
//parametros: pre�o atual e porcentagem
//retorno: nenhum
void fazPorcentagem(float *pPrecoAtual, float *pPorcentagem){
	float novoPreco,valorDoAjuste;
	valorDoAjuste = *pPrecoAtual * (*pPorcentagem/100);
	novoPreco = *pPrecoAtual + valorDoAjuste;
	printf("O novo preco e %.2f R$\n",novoPreco);
	printf("O valor do ajuste foi de: %.2f R$\n",valorDoAjuste);
}

