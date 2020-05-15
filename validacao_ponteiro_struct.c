#include <stdio.h>
struct info_aluno{
	
	int matricula;
	
};
void validaMatricula(struct info_aluno *pMatricula);
int main(){
	struct info_aluno aluno;
	printf("Digite a matricula\n");
	scanf("%d",&aluno.matricula);
	validaMatricula(&aluno);
	printf("A matricula e: %d\n",aluno.matricula);
		
		
	return 0;
}
void validaMatricula(struct info_aluno *pMatricula){
	while(pMatricula->matricula<=0){
		printf("matricula invalida\n");
		scanf("%d",&pMatricula->matricula);
	}
}
