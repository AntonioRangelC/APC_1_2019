#include <stdio.h>
#include <math.h>
//objetivo: calcular e mostrar o resultado dos 30 primeiros termos da série 480/10 - 475/11...
//entrada:nenhuma
//saída: resultado da soma
/*algoritmo em calango:
principal
	real soma=0,auxNumerador=480,auxDenominador=10;
		para(auxDenominador de 10 ate 40-1 passo 1)faca
			soma = soma + ((auxNumerador/auxDenominador) * exp(-1,auxDenominador));
			auxNumerador = auxNumerador - 5;
		fimPara
	escreval(::3soma);

fimPrincipal
*/


int main() { 
	float soma=0,auxNumerador=480,auxDenominador=10;
		for(auxDenominador=10;auxDenominador<40;auxDenominador++){
			soma = soma + ((auxNumerador/auxDenominador) * pow(-1,auxDenominador));
			auxNumerador = auxNumerador - 5;
		}
	printf("%.3f\n",soma);
	return 0;
}
