#include <stdio.h>
/*Objetivo: mostrar todos os numeros pares em um intervalo entre n�mero fornecido e 2000.
  entrada: n�mero
  sa�da : todos os n�meros pares entre n�mero e 2000.*/	   
  /* algoritmo no calango:
principal
  inteiro aux,numero,limite=2000;
   leia(numero);
     para(aux de numero ate limite passo 1)faca
	   se(aux % 2 == 0)entao
	     escreval(aux);
	   fimSe
	 fimPara 
fimPrincipal    
  */
int main() {
	int aux,numero;
	const int limite=2000;
	scanf("%d",&numero);
	for(aux=numero;aux<=limite;aux++){
		if(aux % 2 == 0){
			printf("%d\n",aux);
		}
	}  
	return 0;
}
