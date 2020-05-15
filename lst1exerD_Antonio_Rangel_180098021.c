#include <stdio.h>

//objetivo: calcular e escrever o valor a ser pago à provedora de acesso
//entrada: valor de horas de uso da internet
//saída: valor a ser pago para a provedora

int main() {
	int horas,resultado;
	  scanf("%d",&horas);
	    if(horas<=20){
	    	printf("30\n");
		}
		else if(horas>20){
			resultado = horas - 20;
			printf("%d\n",(resultado*3)+30);
		}
	return 0;
}
