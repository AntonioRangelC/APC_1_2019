#include <stdio.h>
//objetivo : mostrar a m�dia de idades, a maior idade e sua posi��o
//entrada : idades dessas pessoas
//sa�da : m�dia das idades, maior idade e sua posi��o
int main ()
{
	int idades[80],maior,aux,posicao,media,soma;
	aux=0;
	maior=0;
	soma=0;
	  scanf("%d",&idades[aux]);
	   while(idades[aux] >= 0){  
	    	if(idades[aux] > maior){
	    		maior = idades[aux];
	    		posicao = aux;
	    	}
	      soma = soma + idades[aux];
	      aux++;
		  scanf("%d",&idades[aux]);
	    }
		if(soma<=0){
           printf("0\n");
	 	   printf("0 0\n");
		}
		else if(soma>0){
	     media = soma/aux;
	 	 printf("%.0d\n",media);
	 	 printf("%d %d\n",maior,posicao);
        }
        
  return 0;
 }
