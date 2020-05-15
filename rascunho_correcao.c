#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
struct infoAluno{
	long int CNIC;
	char nome[10];
};
void tiraEnter(char *string);
void validaNome(char *pNome);
void arrumaNome(char *pNome);
void imprime();
void alteraNome(struct infoAluno aluno);
int main(){
	int aux,opcao;
	struct infoAluno aluno; 
	FILE *pArq;
	printf("digite 1 para cadastrar, 2 para alterar e 3 para imprimir\n");
	scanf("%d",&opcao);
	if(opcao==1){
		printf("Digite o cnic\n");
		scanf("%ld",&aluno.CNIC);
		printf("Digite o seu nome:\n");
		fflush(stdin);
		fgets(aluno.nome,10,stdin);
		fflush(stdin);
		validaNome(aluno.nome);
		arrumaNome(aluno.nome);
		pArq=fopen("teste.bin","ab");
		fwrite(&aluno, sizeof(aluno), 1, pArq);
		fclose(pArq);
	}
	else if(opcao==2){
		alteraNome(aluno);
	}
	else if(opcao==3){
		imprime();
	}
	
	return 0;
}
void imprime(){
	struct infoAluno *auxiliar, tmp;
	int aux=0,i,tamanhoArq,a;
	FILE *pArq;
	pArq=fopen("teste.bin","rb");
	fseek(pArq,0,SEEK_END);
	tamanhoArq=ftell(pArq);
	a=tamanhoArq/sizeof(auxiliar);
	auxiliar=(struct infoAluno*)calloc(a,sizeof(auxiliar));
	rewind(pArq);
	while(fread(&tmp,sizeof(tmp),1,pArq)){
		auxiliar[aux].CNIC=tmp.CNIC;
		strcpy(auxiliar[aux].nome, tmp.nome);
		aux++;	
	}
	fclose(pArq);
	for(i=0;i<aux;i++){
		printf("cnic %ld\n",auxiliar[i].CNIC);
		printf("nome %s\n",auxiliar[i].nome);
	}
	
}
void validaNome(char *pNome){
	tiraEnter(pNome);
	  while(strlen(pNome)<1){
	  	printf("Tamanho invalido\n");
	  	fgets(pNome,10,stdin);
		fflush(stdin);
		tiraEnter(pNome);
	  }
}
void tiraEnter(char* string){
	int tam;
	tam=strlen(string);
	if(string[tam-1]=='\n'){
		string[strlen(string)-1]='\0';
	}
}
void arrumaNome(char *pNome){
	int aux;
	for(aux=0;aux<strlen(pNome);aux++){
		pNome[aux]=tolower(pNome[aux]);
	}
  pNome[0]=toupper(pNome[0]);
}
void alteraNome(struct infoAluno aluno){
	struct infoAluno auxArquivo,auxiliar;
	long int cnicUsuario;
	int tamanhoArq,tamanhoBytes,aux=0,achou=0,size;
	char nome[MAX];
	FILE *pArq;
	printf("Digite o cnic do aluno que vc quer encontrar\n");
	scanf("%ld",&cnicUsuario);
	pArq=fopen("teste.bin","rb+");
		if(pArq==NULL){
			printf("Nao abriu corretamente\n");
		}
		else{
	fseek(pArq,0,SEEK_END);
	size=ftell(pArq);
	rewind(pArq);
	//printf("posicao do cursor: %d\n",ftell(pArq));
	while(fread(&auxArquivo,sizeof(auxArquivo),1,pArq) && achou==0){
			if(auxArquivo.CNIC==cnicUsuario){
				achou++;
				//fseek(pArq,-sizeof(auxArquivo),SEEK_CUR);
				auxiliar=auxArquivo;
			}
			else if(fread(&auxArquivo,sizeof(auxArquivo),1,pArq)==size){//arrumar
				printf("Esse CNIC nao foi encontrado\n");
			}
			aux++;
			tamanhoBytes=aux*sizeof(auxiliar);
			//printf("posicao do cursor no while: %d\n",ftell(pArq));
	}
	//fclose(pArq);
		printf("digite o novo nome\n");
		fflush(stdin);
		fgets(nome,MAX,stdin);
		validaNome(nome);
		arrumaNome(nome);
		strcpy(auxiliar.nome,nome);
		//pArq=fopen("teste.bin","rb+");
		//printf("posicao do cursor: %d\n",ftell(pArq));
		printf("tamanho bytes: %d\n",tamanhoBytes);
		printf("tamanho da struct: %d\n",sizeof(auxiliar));
		printf("posicao do cursor antes do fseek: %d\n",ftell(pArq));
		fseek(pArq,2*(-sizeof(struct infoAluno)),SEEK_CUR);
		printf("posicao do cursor antes do fwrite: %d\n",ftell(pArq));
		auxiliar.CNIC=cnicUsuario;
		if(fwrite(&auxiliar,sizeof(auxiliar),1,pArq)==1){
			printf("foi escrito com sucesso\n");
			
		}
		else
			printf("nao foi escrito com sucesso\n");
		fclose(pArq);
	}
}
