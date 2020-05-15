#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 60
struct infoFuncionario{
	char nome[MAX],setor[MAX];
	float salario,tempo;
};
//Prototipo
void validaNome(char *nome);
void validaSalario(float *salario);
void validaTempo(float *tempo);
void validaSetor(char *setor);
void resposta(char *nome,float *salario,float *tempo,char *setor,int *bonificacao);
void tiraEnter(char*);
//Sintese
//objetivo: armazenar e mostrar o nome do funcionário, nome do departamento, seu salário e o tempo de serviço dele na empresa
//entrada: nome, salário, nome do departamento,tempo de serviço
//saída: nome, salário, nome do departamento,tempo de serviço, quantidade de cadastros.
int main(){
	
	char continuar;
	int qtdCadastros=0,bonificacao=0;
	struct infoFuncionario funcionario;
	do{
		qtdCadastros++;
		printf("Digite o nome do funcionario %d\n",qtdCadastros);
		fflush(stdin);
		fgets(funcionario.nome,MAX,stdin);
		tiraEnter(funcionario.nome);
		validaNome(funcionario.nome);
		printf("Digite o salario de %s:\n",funcionario.nome);
		scanf("%f",&funcionario.salario);
		validaSalario(&funcionario.salario);
		printf("Digite o setor de trabalho de %s\n",funcionario.nome);
		fflush(stdin);
		fgets(funcionario.setor,MAX,stdin);
		tiraEnter(funcionario.setor);
		validaSetor(funcionario.setor);
		printf("Digite o tempo de %s na empresa (em anos):\n",funcionario.nome);
		scanf("%f",&funcionario.tempo);
		validaTempo(&funcionario.tempo);
		if(funcionario.tempo>MAX){
			bonificacao=1;
			funcionario.salario= funcionario.salario * 1.1;
		}
		system("CLS");
		resposta(funcionario.nome,&funcionario.salario,&funcionario.tempo,funcionario.setor,&bonificacao);
		printf("Digite S caso queira cadastrar mais funcionarios ou outra tecla para encerrar:\n");
		fflush(stdin);
		scanf("%c",&continuar);
		continuar=toupper(continuar);
	}while(continuar=='S');
	printf("Voce realizou %d cadastros!\n",qtdCadastros);
	return 0;
}
//Sintese
//Objetivo: validar nome
//Parametros: nome
//Retorno: nenhum
void validaNome(char *nome){
	while(strlen(nome)<1){
		printf("Digite um nome valido:\n");
		fflush(stdin);
		fgets(nome,10,stdin);
		tiraEnter(nome);
	}
}
//Sintese
//Objetivo: validar o salario
//Parametros: salario
//Retorno:nenhum
void validaSalario(float *salario){
	while(*salario<=0){
		printf("Digite um salario valido:\n");
		scanf("%f",salario);
	}
}
//Sintese
//Objetivo: validar o tempo de empresa
//Parametros: tempo de empresa
//Retorno: nenhum
void validaTempo(float *tempo){
	while(*tempo<=0){
		printf("Digite um tempo (em anos) valido:\n");
		scanf("%f",tempo);
	}
}
//Sintese
//Objetivo: validar o setor
//Parametros: setor
//Retorno: nenhum
void validaSetor(char *setor){
	while(strlen(setor)<1){
		printf("Digite um setor valido:\n");
		fflush(stdin);
		fgets(setor,10,stdin);
		tiraEnter(setor);
	}
}
//Sintese
//Objetivo: mostrar a ficha cadastral
//Parametros: nome, salario, tempo de empresa, setor, bonificacao
//Retorno: nenhum
void resposta(char *nome,float *salario,float *tempo,char *setor,int *bonificacao){
	printf("Nome\t\tSalario\t\tTempo\t\tSetor\n");
	printf("%4s\t\t%4.2f R$\t%5.1f\t\t%s\n",nome,*salario,*tempo,setor);
	if(*bonificacao=1){
		printf("Voce obteve uma bonificacao de 10%% no seu salario!\n");
	}
}
//Sintese
//Objetivo: tirar o enter de dentro da string lida
//Parametros: string
//Retorno: nenhum
void tiraEnter(char* string){
	int tam;
	tam=strlen(string);
	if(string[tam-1]=='\n'){
		string[strlen(string)-1]='\0';
	}
}
