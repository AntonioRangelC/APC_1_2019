#include <stdio.h>
#include <string.h>
int main ()
{
	int n,i,aux,contador;
	char primeiraString[1000],segundaString[1000],auxiliar[1000]={'\0'};
	//auxiliar[0]='\0';
		scanf("%d",&n);
		  for(i=0;i<n;i++){
		  	scanf("%s",primeiraString);
		  	scanf("%s",segundaString);
		  	contador=strlen(segundaString);
		      for(aux=strlen(primeiraString)-1;aux>(strlen(primeiraString)-strlen(segundaString))-1;aux--){
			  		contador--;
		  	     	auxiliar[contador]=primeiraString[aux];   	
		      }
		      if(strlen(primeiraString)==strlen(segundaString)){
		      	 if(strcmp(primeiraString,segundaString)==0){
		      	 	printf("encaixa\n");
			     }
			     else if(strcmp(primeiraString,segundaString)!=0){
			     	printf("nao encaixa\n");
				 }
			  }
			  else if(strlen(primeiraString)!=strlen(segundaString)){
		         if(strcmp(auxiliar,segundaString)==0){
		        	printf("encaixa\n");
		         }
		         else if(strcmp(auxiliar,segundaString)!=0){
		        	printf("nao encaixa\n");
		         }
		      }
	      }
	      
	return 0;
}
