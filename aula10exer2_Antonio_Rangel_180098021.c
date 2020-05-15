#include <stdio.h>
//objetivo : mostrar o fatorial de um n�mero fornecido
//entrada : n�mero inteiro entre 0 e 19
//sa�da : fatorial desse n�mero
int main() {
	int valor,aux,fatorial;
	fatorial = 1;
	  scanf("%d",&valor);
    	while (valor < 0 || valor > 19){
    		printf("Valor invalido\n");
    		scanf("%d",&valor);
		}
		for(aux=1;aux<=valor;aux++){
			fatorial = fatorial * aux;
		}
	printf("Fatorial : %d\n",fatorial);
	return 0;
}
