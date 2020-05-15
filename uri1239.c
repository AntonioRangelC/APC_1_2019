#include <stdio.h>
#include <string.h>
int main ()
{
	char texto[1000];
	int aux,fraseAberta=0,fraseNegrito=0;
	  while(fgets(texto,1000,stdin)!=EOF){
	  	for(aux=0;aux<strlen(texto);aux++){
	  			if(texto[aux]=='_' && fraseAberta==0){
	  				printf("<i>");
	  				fraseAberta=1;
			   }
				else if(texto[aux]=='_' && fraseAberta==1){
					printf("</i>");
					fraseAberta=0;
				}
				else if(texto[aux]=='*' && fraseNegrito==0){
	  				printf("<b>");
	  				fraseNegrito=1;
			   }
				else if(texto[aux]=='*' && fraseNegrito==1){
					printf("</b>");
					fraseNegrito=0;
				}
				else{
					printf("%c",texto[aux]);
				}
				
		  
		   }
		  
		  printf("\n");
         }
	return 0;
}
