#include <stdio.h>
#include <string.h>
int main()
{
char marca[10],nome[10];
	printf("Escolha uma uma marca escrevendo seu nome\n");
	printf("FIAT \t CHEVROLET \t FORD\n");
	scanf("%s",marca);
	  while(strcmp(marca,"FIAT")!=0 && strcmp(marca,"CHEVROLET")!=0 && strcmp(marca,"FORD")!=0){
	  	printf("Opçao invalida\n");
	  	getchar();
	  	scanf("%s",marca);
	  }
			if(strcmp(marca,"FIAT")==0){
				printf("Carros da FIAT:\n");
				printf("Uno\n");
				printf("Tempra\n");
				scanf("%s",nome);
				  switch (nome){
				  	case "Uno":
				  		system("cls");
				  		aux++;
				  		printf("\t\t\tObrigado por escolher o(a) %s",nome);
				  		break;
				  	case "Tempra":
				  		system("cls");
				  		aux++;
				  		printf("\t\t\tObrigado por escolher o(a) %s",nome);
				  		break;
				  	default:
				  		printf("Opçao inválida, digite novamente\n");
				  		break;
			  	
				  
			default:
				printf("Opçao inválida, digite novamente\n");	
				break;
		
   }while(aux != 1);
	return 0;
}

