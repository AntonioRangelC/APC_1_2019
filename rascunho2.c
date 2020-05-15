#include <stdio.h>
#include <string.h>
struct infoAluno{
	long int CNIC;
	char nome[10];
};
int validaOpcao(int opcao);
int main(){
	char opcao;
	scanf("%c",&opcao);
		switch(opcao){
			case 'c':
				printf("opcao C: %c\n",opcao);
			break;
			case 'd':
				printf("opcao d: %c\n",opcao);
			break;
			default:
				printf("invalido\n");
			break;
		}
	return 0;
}
int validaOpcao(int opcao){
	while(opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5){
		printf("Opcao invalida, digite novamente");
		scanf("%d",opcao);
	}
	return opcao;
}
