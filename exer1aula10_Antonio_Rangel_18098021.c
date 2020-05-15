#include <stdio.h>
/*Objetivo: mostrar todos os numeros pares em um intervalo entre número fornecido e 2000.
  entrada: número
  saída : todos os números pares entre número e 2000.*/	   
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
