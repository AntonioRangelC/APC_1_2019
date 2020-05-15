#include <stdio.h>
//objetivo: mostrar o(s) ganhador(es) de um concurso de piadas
//entrada: número de juízes, nota de cada participante para aquele juiz
//saída: ganhador(es) do concurso
int main ()
{
	int qtd,aux,notaA,notaB,notaC,somaA=0,somaB=0,somaC=0;
	  scanf("%d",&qtd);
	    for(aux=0;aux<qtd;aux++){	
	    	scanf("%d",&notaA);
	    	scanf("%d",&notaB);
	    	scanf("%d",&notaC);
	    	somaA+=notaA;
	    	somaB+=notaB;	
	    	somaC+=notaC;  	
	    }
	   if(somaA>somaB && somaA>somaC){
	   	printf("A\n");
	   }
	   else if(somaB>somaA && somaB>somaC){
	   	printf("B\n");
	   }
	   else if(somaC>somaB && somaC>somaA){
	   	printf("C\n");
	   }
	    else if(somaC==somaB && somaC != somaA){
	   	printf("B e C\n");
	   }
	    else if(somaC==somaA && somaC != somaB){
	   	printf("A e C\n");
	   }
	    else if(somaC==somaB && somaC==somaA){
	   	printf("A, B e C\n");
	   }
	    else if(somaA==somaB && somaA != somaC){
	   	printf("A e B\n");
	   }
  return 0;
}
