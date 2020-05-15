#include <stdio.h>
void fazBorda();
int main(){
	int linhas,colunas;
	/*for(linhas=0;linhas<150;linhas++){
		printf("%c",177);
	}*/
	printf("\n");
	printf("\t\tSeja bem vindo\n");
	printf("\n");
	/*for(linhas=0;linhas<150;linhas++){
		
		printf("%c",177);
	}*/
	fazBorda();
	return 0;
}
void fazBorda(){
	int linhas,colunas,i;
	
	for(linhas=0;linhas<20;linhas++){
			printf("%c%c",177,177);
			if(linhas==0 || linhas==19){
				for(i=0;i<20;i++){
					printf("%c",177);
				}
			}
			else{
				for(i=0;i<20;i++){
					printf(" ");
				}
			}
		for(colunas=0;colunas<20;colunas++){
			if(colunas==19){
				printf("%c%c",177,177);
			}
		}
		printf("\n");
	}
}
