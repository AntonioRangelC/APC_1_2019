#include <stdio.h>
#define MAX 100
struct infoAluno{
	int matricula;
};
int validaMatricula(int matricula);
int main(){
	int aux;
	struct infoAluno aluno[MAX];
	do{
		aux++;
		printf("Digite a matricula\n");
		scanf("%d",&aluno[aux].matricula);
		aluno[aux].matricula=validaMatricula(aluno[aux].matricula);
		printf("A matricula e: %d\n",aluno[aux].matricula);
	}while(aux<MAX && aluno[aux].matricula!=0);
		
	return 0;
}
int validaMatricula(int matricula){
	while(matricula<=0){
		printf("matricula invalida\n");
		scanf("%d",&matricula);
	}
	return matricula;
}
