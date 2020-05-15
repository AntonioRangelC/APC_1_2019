#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//prototipo funcao validaNota
float validaNota(float* notas, int contador);
//objetivo: validar a nota
//parametros: nota e contador
//retorno: nota validada
float validaNota(float* notas, int contador){
	 while(notas[contador]<0 || notas[contador]>10){
		    printf("Nota invalida, digite novamente\n");
		    scanf("%f",&notas[contador]);
				  }
			return notas[contador];
}
//prototipo funcao calculaMedia
float calculaMedia(float* notas);
//objetivo: calcular a media
//parametros: vetor notas
//retorno: media
  float calculaMedia(float* notas){
  	float soma=0.0,media=0.0;
  	int aux;
  	  for(aux=0;aux<3;aux++){
  	  	soma= soma + notas[aux];
		}
		media = soma / 3.0;
		return media;
  }
//objetivo: calcular e mostrar a media de um ou mais alunos
//entrada: tres notas para cada aluno
//saida: media das notas

int main() {
	float media,notas[3]={};
	int qtdAlunos,aux,MAX=100,contador;
	char nome[100]={},recebeString[100]={};
	printf("Digite a quantidade de alunos da turma\n");
	scanf("%d",&qtdAlunos);
		for(aux=0;aux<qtdAlunos;aux++){
		    getchar();
			printf("Digite o nome do aluno %d\n",aux+1);
			scanf("%[^\n]",nome);
			getchar();
			printf("Tamanho da string : %d\n",strlen(nome));	
			 while(strlen(nome)<=0 || strlen(nome)>MAX){ 
			  	printf("Nome invalido, digite novamente\n"); 
			  	scanf("%[^\n]",nome);
				getchar();
			  }//Não consegui colocar essa validação em funçao
			  for(contador=0;contador<3;contador++){
		       	printf("Digite a nota %d\n",contador+1);
		    	scanf("%f",&notas[contador]);
				  notas[contador]=validaNota(notas,contador);
		       }
		     	media = calculaMedia(notas);
			printf("A media do aluno %s e: %.2f\n",nome,media);
			
		}
	return 0;
}
