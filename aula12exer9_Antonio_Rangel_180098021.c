 #include <stdio.h>
#include <stdlib.h>
//prototipo validaQtdFunc
int validaQtdFunc(int qtdFunc);
//prototipo validaCodigos
void validaCodigos(int *codigosFunc);
//prototipo validaSalario
float validaSalario(float salarios);
//prototipo mostraResultados
void mostraResultados(float salarios[], int qtdFunc);
//objetivo : cadastrar funcionários e mostrar o maior e menor salário, média salarial.
//entrada : código do funcionario e o salario
//saida: maior, menor salário e média salarial 
int main(){
	int codigosFunc[100],aux,contador,qtdFunc,auxVetor;
	float salarios[100];
		printf("Digite a quantidade de funcionarios para serem cadastrados\n");
		scanf("%d",&qtdFunc);
		qtdFunc = validaQtdFunc(qtdFunc);
		  for(aux=0;aux<qtdFunc;aux++){
		  	printf("Digite o codigo do funcionario %d\n",aux+1);
		  	scanf("%d",&codigosFunc[aux]);
		    validaCodigos(&codigosFunc[aux]);
	 			  for(auxVetor=aux-1;auxVetor>=0;auxVetor--){
	  				  if(codigosFunc[auxVetor]== codigosFunc[aux]){
	  				    	printf("Codigo ja existe, digite novamente\n");
	 					    scanf("%d",&codigosFunc[aux]);
	 				      	validaCodigos(&codigosFunc[aux]);
		  			  }	
		  		}
		  	printf("Digite o salario do funcionario %d\n",aux+1);
		  	scanf("%f",&salarios[aux]);
		  	salarios[aux]=validaSalario(salarios[aux]);
		  }
		mostraResultados(salarios,qtdFunc);
	return 0;
}
//objetivo: validar a quantidade de funcionarios
//parametros: quantidade de funcionarios
//retorno : quantidade validada
int validaQtdFunc(int qtdFunc){
	while(qtdFunc<=0){
		printf("Quantidade invalida, digite novamente\n");
		scanf("%d",&qtdFunc);
	}
	return qtdFunc;
}
//objetivo: validar salario dos funcionarios
//parametros: salario do funcionario
//retorno: salario validado
float validaSalario(float salarios){
	while(salarios<=0){
		printf("Salario invalido, digite novamente\n");
	 	scanf("%f",&salarios);
	}
	return salarios;
}
//objetivo: mostrar todos os salarios, o menor, maior e a media 
//parametros: salarios dos funcionarios, quantidade de funcionarios
//retorno: nenhum
void mostraResultados(float salarios[], int qtdFunc){
	float maior=0,menor=salarios[0],soma=0,media;
	int aux,contador;
		for(aux=0;aux<qtdFunc;aux++){
			if(salarios[aux]>maior){
				maior = salarios[aux];
			}
			else if(salarios[aux]<menor){
				menor = salarios[aux];
			}
			soma+=salarios[aux];
		}
		media = soma/qtdFunc;
		printf("Funcionario\t\tSalario\n");
		for(contador=0;contador<qtdFunc;contador++){
			printf("  %d\t\t\t %.2f R$\n",contador+1,salarios[contador]);
		}
		printf("Maior salario: %.2f R$\n",maior);
		printf("Menor salario: %.2f R$\n",menor);
		printf("Media salarial: %.2f R$\n",media);
		
}
//objetivo: validar o numero do codigo do funcionario
//parametros: codigo do funcionario, aux
//retorno: codigo validado
void validaCodigos (int *codigosFunc){
	while(*codigosFunc<=0){
	 	printf("Codigo invalido, digite novamente\n");
	 	scanf("%d",codigosFunc);
	}
	
}
