#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//prototipo funcao validaNota
float validaNota(float* notas, int contador);
//objetivo: validar a nota
//parametros: nota 
//retorno: nota validada
float validaNota(float notas){
	while(notas<0 || notas >10){
		    printf("Nota invalida, digite novamente\n");
		    scanf("%f",&notas);
	}
	return notas;
}
//prototipo funcao calculaMedia
float calculaMedia(float* notas);
//objetivo: calcular a media
//parametros: vetor notas
//retorno: media
  float calculaMedia(float notas){
  	float soma=0.0,media=0.0;
  	int aux;
  	  for(aux=0;aux<3;aux++){
  	  	soma= soma + notas[aux];
		}
		media = soma / 3.0;
		return media;
  }
  //objetivo: calcular a media
//parametros: vetor notas
//retorno: media
  int validaNome(char nome[]){
  	if(strlen(nome)<=0 || strlen(nome)>100)
		return 0;
    else
    	return 1;
    
  return nome;
}
//objetivo: calcular e mostrar a media de um ou mais alunos
//entrada: tres notas para cada aluno
//saida: media das notas


int main() {
	float media,notas[3]={};
	int qtdAlunos,aux,MAX=100,contador;
	char nome1[100]={};
	char nome[100]={},recebeString[100]={};
	printf("Digite a quantidade de alunos da turma\n");
	scanf("%d",&qtdAlunos);
		for(aux=0;aux<qtdAlunos;aux++){
		    getchar();
			printf("Digite o nome do aluno %d\n",aux+1);
			scanf("%s",nome);
			while(1){
				if(validaNome==0){
					printf("Digite um nmr valido:\n")
					getchar();
					scanf("%[^\n]",nome);
				}
				if(validaNome==1){
					break;
				}
			}
			  for(contador=0;contador<3;contador++){
		       	printf("Digite a nota %d\n",contador+1);
		    	scanf("%f",&notas[contador]);
				  notas[contador]=validaNota(notas[contador]);
		       }
		     	media = calculaMedia(notas);
			printf("A media do aluno %s e: %.2f\n",nome,media);
			strcpy(nome,no);
		}
	return 0;
}

/* void validaNome(char *p){
	while(!strlen(p)){
	printf("invalido");
	fgets(nome,50,stdin);
	}
}

