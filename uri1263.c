#include <stdio.h>
#include <string.h>
int main ()
{
	char string[100],auxiliar[100];
	int aux,contador=1,aux2,i,iguais=0,logico=0;
		gets(string);
		auxiliar[0] = string[0];
		  for(aux=1;aux<strlen(string);aux++){
		  	if(string[aux-1]==' '){
		  		auxiliar[contador]=string[aux];
		  		contador++;
			  }
		  }
		  for(aux2=0;aux2<strlen(auxiliar);aux2++){
		     if(aux2>0 && aux2<strlen(auxiliar)){
			     if(auxiliar[aux2]==auxiliar[aux2-1] && auxiliar[aux2]!=auxiliar[aux+1]){
			    	iguais++;
			     }
			     /*else if(auxiliar[aux2]!=auxiliar[aux2-1] && auxiliar[aux2]==auxiliar[aux2+1]){
			     	iguais++;
				 }*/
		     }
		  }
		  printf("iguais : %d\n",iguais);
		 // printf(" auxiliar : %s\n",auxiliar);
		  //printf("string : %s\n",string);
	return 0;
}
