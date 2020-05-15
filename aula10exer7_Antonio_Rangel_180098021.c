#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//objetivo: calcular e mostrar a maior e menor altura de um grupo de 10 pessoas, a media de altura das mulheres e a quantidade de homens 
//entrada: sexo da pessoa e altura 
//saída: maior e menor altura, media de altura das mulheres e a quantidade de homens
/*
principal
  texto genero,masculino="masculino",feminino="feminino";
  inteiro aux,contadorHomens=0,contadorMulheres=0,contador;
  real somaAlturas=0,alturas[10],maior,menor;
  para(aux de 0 ate 10 passo 1)faca
  	 faca
  	 	escreval("Escreva 'masculino' para cadastrar a idade de um homem ou 'feminino' para cadastar a altura de uma mulher");
		leia(genero);
		limpaTela();
	 enquanto(tmanhoTexto(genero) <=0 e comparaTexto(genero,feminino) != 0 e comparaTexto(genero,masculino) != 0);
    se(comparaTexto(genero,masculino) == 0)entao
      contadorHomens = contadorHomens + 1;
      escreval("Qual é a altura deste homem?");
      leia(alturas[aux]);
      limpaTela();
         enquanto(alturas[aux]<=0)faca
            escreval("Altura inválida");
            leia(altura[aux]);
			limpaTela();
         fimEnquanto
    fimSe
       senao
       se(comparaTexto(genero,feminino) == 0)entao
          contadorMulheres++;
          escreval("Qual é a altura dessa mulher?");
          leia(alturas[aux]);
          limpaTela();
             enquanto(alturas[aux]<=0)faca
            	escreval("Altura inválida");
            	leia(altura[aux]);
            	limpaTela();
             fimEnquanto
          somaAlturas = somaAlturas + alturas[aux];
		fimSe
	  maior=0;
    menor=alturas[0];
    para(contador=0;contador<10;contador++)faca
    	se(alturas[contador]>maior)entao
    		maior = alturas[contador];
    		
		fimSe
	    se(alturas[contador]<=menor)entao
			menor = alturas[contador];
		fimSe
		
	fimPara
	limpaTela();
	escreval("Maior altura  : ",::2maior);
	escreval("Menor altura  : ",::2menor);
	
    se(contadorMulheres>0)entao
       escreval("Media de altura das mulheres : ",somaAlturas/contadorMulheres);
    senao
       se(contadorMulheres==0)entao
    	  escreval("Media de altura das mulheres : 0");
	    fimSe
	fimSe
	escreval("Numero de homens: ",contadorHomens);
	

fimPrincipal
*/
int main() {
	char genero[9],masculino[10]="masculino",feminino[9]="feminino";
	int aux,contadorHomens=0,contadorMulheres=0,contador;
	float somaAlturas=0,alturas[10],maior,menor;
	for(aux=0;aux<10;aux++){
		do{	
		  printf("Escreva 'masculino' para cadastrar a idade de um homem ou 'feminino' para cadatrar a altura de uma mulher\n");
		  scanf("%s",genero);
		  system("cls");
		}while(strlen(genero)<=0 && strcmp(genero,feminino) != 0 && strcmp(genero,masculino) != 0);
	  if(strcmp(genero,masculino)==0){
	  	contadorHomens++;
	  	printf("Qual é a altura deste homem?\n");
	  	scanf("%f",&alturas[aux]);
	  	system("cls");
	  	  while(alturas[aux]<=0){
	  	  	system("cls");
	  	  	printf("Altura invalida\n");
	  	  	scanf("%f",&alturas[aux]);
			}
	  }
	  else if(strcmp(genero,feminino)==0){
	  	contadorMulheres++;
	  	printf("Qual é a altura dessa mulher?\n");
	  	scanf("%f",&alturas[aux]);
	  	system("cls");
	  	while(alturas[aux]<=0){
	  	  	system("cls");
	  	  	printf("Altura inválida\n");
	  	  	scanf("%f",&alturas[aux]);
			}
	  	somaAlturas = somaAlturas + alturas[aux];
	  }
    }
    maior=0;
    menor=alturas[0];
    for(contador=0;contador<10;contador++){
    	if(alturas[contador]>maior){
    		maior = alturas[contador];
    		
		}
	    if(alturas[contador]<=menor){
			menor = alturas[contador];
		}
	}
	system("cls");
	printf("Maior altura  : %.2f\n",maior);
	printf("Menor altura  : %.2f\n",menor);
	
    if(contadorMulheres>0){
       printf("Media de altura das mulheres : %.2f\n",somaAlturas/contadorMulheres);
    }
    else if(contadorMulheres==0){
    	printf("Media de altura das mulheres : 0\n");
	}
	printf("Numero de homens: %d\n",contadorHomens);
	return 0;
}
