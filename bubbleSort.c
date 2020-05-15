#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAMANHO_COR 40
#define MIN_CODIGO 10
#define TAMANHO_SIGLA 3
struct infoRoupa{
	int codigo;
	char cor[TAMANHO_COR],tamanho[TAMANHO_SIGLA];
};
void novoCadastro(char *opcao);
void lista();
void encerra();
void validaTamCodigo(int *codigo);
void validaCodigo(int *codigo);
void validaTamanho(char *tamanho);
void validaCor(char *cor);
void tiraEnter(char *string);
int main(){
	char opcao;
	struct infoRoupa roupa;
	do{
		printf("Digite:\n");
		printf("N - Para fazer um novo cadastro\n");
		printf("L - Para listar os cadastros\n");
		printf("E - Para encerrar\n");
		scanf("%c",&opcao);
			switch(opcao){
				case 'n':
				case 'N':
					novoCadastro(&opcao);
				break;
				case 'L':
				case 'l':
					lista();
				break;
				case 'e':
				case 'E':
					encerra();
				break;
				default:
					printf("Opcao invalida, digite novamente\n");
				break;
			}
	}while(opcao != 'e' && opcao != 'E');
	return 0;
}
//objetivo:
//parametros:
//retorno:
void novoCadastro(char *opcao){
	struct infoRoupa roupa;
	FILE *pArq;
	printf("Digite o codigo da roupa\n");
	fflush(stdin);
	scanf("%d",&roupa.codigo);
	validaTamCodigo(&roupa.codigo);
	validaCodigo(&roupa.codigo);
	printf("Digite o tamanho da roupa\n");
	printf("P - pequena\n");
	printf("M - media\n");
	printf("G - grande\n");
	printf("XG - extra grande\n");
	fflush(stdin);
	fgets(roupa.tamanho,TAMANHO_SIGLA,stdin);
	validaTamanho(roupa.tamanho);
	printf("Digite a cor da roupa\n");
	fflush(stdin);
	fgets(roupa.cor,TAMANHO_COR,stdin);
	validaCor(roupa.cor);
	pArq=fopen("roupas.bin","ab");
	fwrite(&roupa,sizeof(roupa),1,pArq);
	fclose(pArq);
	printf("Digite 'M' para voltar para o menu, ou 'E' para encerrar\n");
	fflush(stdin);
	scanf("%c",opcao);
}
//objetivo:
//parametros:
//retorno:
void lista(){
	
}
//objetivo:
//parametros:
//retorno:
void encerra(){
	int contadorP=0,contadorM=0,contadorG=0,contadorXG=0;
	FILE *pArq;
	struct infoRoupa auxArquivo;
	pArq=fopen("roupas.bin","rb");
	if(pArq==NULL){
		pArq=fopen("roupas.bin","wb");
	}
	while(fread(&auxArquivo,sizeof(auxArquivo),1,pArq)){
		if(strcmp(auxArquivo.tamanho,"P")==0){
			contadorP++;
		}
		else if(strcmp(auxArquivo,"M")==0){
			contadorM++;
		}
		else if(strcmp(auxArquivo,"G")==0){
			contadorG++;
		}
		else if(strcmp(auxArquivo,"XG")==0){
			contadorXG++;
		}
	}
	fclose(pArq);
	printf("TAMANHO  QUANTIDADE\n");
	printf("P-Pequena  %d",contadorP);
	printf("M-Media  %d",contadorM);
	printf("G-Grande  %d",contadorG);
	printf("XG-Exra-Grande  %d",contadorXG);
}
//objetivo:
//parametros:
//retorno:
void validaTamCodigo(int *codigo){
	while(*codigo < MIN_CODIGO){
		printf("O tamanho do codigo deve ser maior que %d\n",MIN_CODIGO);
		fflush(stdin);
		scanf("%c",codigo);
	}
}
//objetivo:
//parametros:
//retorno:
void validaCodigo(int *codigo){
	struct infoRoupa auxArquivo;
	FILE *pArq;
	pArq=fopen("roupas.bin","rb");
	if(pArq==NULL){
		pArq=fopen("roupas.bin","wb");
	}
	while(fread(&auxArquivo,sizeof(auxArquivo),1,pArq)){
		if(auxArquivo.codigo == *codigo){
			printf("Esse codigo ja existe, digite novamente\n");
			fflush(stdin);
			scanf("%d",codigo);
			validaTamCodigo(codigo);
			validaCodigo(codigo);
		}
	}
}
//objetivo:
//parametros:
//retorno:
void validaTamanho(char *tamanho){
	int aux;
	tiraEnter(tamanho);
	for(aux=0;aux<strlen(tamanho);aux++){
		tamanho[aux]=toupper(tamanho[aux]);
	}
	while(strlen(tamanho)<1){
		printf("Tamanho invalido, digite novamente\n");
		fflush(stdin);
		fgets(tamanho,TAMANHO_SIGLA,stdin);
		tiraEnter(tamanho);
	}
	while(strcmp(tamanho,"P") != 0 && strcmp(tamanho,"M") != 0 && strcmp(tamanho,"G") != 0 && strcmp(tamanho,"XG") != 0){
		printf("Tamanho invalido\n");
		printf("Digite o tamanho da roupa\n");
		printf("P - pequena\n");
		printf("M - media\n");
		printf("G - grande\n");
		printf("XG - extra grande\n");
		fflush(stdin);
		fgets(tamanho,TAMANHO_SIGLA,stdin);
		tiraEnter(tamanho);
	}
}
//objetivo:
//parametros:
//retorno:
void validaCor(char *cor){
	int aux;
	tiraEnter(cor);
	for(aux=0;aux<strlen(cor);aux++){
		cor[aux]=tolower(cor[aux]);
	}
	while(strlen(cor)<1){
		printf("Cor invalida, digite novamente\n");
		fflush(stdin);
		fgets(cor,TAMANHO_COR,stdin);
		tiraEnter(cor);
	}
}
//objetivo:
//parametros:
//retorno:
void tiraEnter(char *string){
	int tam=strlen(string);
	if(string[tam-1]=='\n'){
		string[tam-1]='\0';
	}
}
