#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAMANHO_COR 40
#define MIN_CODIGO 10
#define TAM_SIGLA 2
//objetivo: cadastrar roupas, listar e mostrar a quantidade de cadastros feitos.
//entrada: codigo da roupa, tamanho e cor
//saída: na opção listar, a saída é uma tabela com os cadastros, e na encerra, a saída é uma tabela com a quantidade
struct infoRoupa{
	int codigo;
	char tamanho[TAM_SIGLA],cor[TAMANHO_COR];
};
void novoCadastro(char *opcao);
void listaCadastros(char *opcao);
void encerra();
void validaTamCodigo(int *codigo);
void validaCodigo(int *codigo);
void validaTamanho(char *tamanho);
void validaCor(char *cor);
void tiraEnter(char *string);
void arrumaCor(char *cor);
void bubbleSort(struct infoRoupa *roupa,int *auxVetor);
int main(){
	char opcao;
	struct infoRoupa roupa;
	do{
		printf("\t\tRoupas de Frio\n");
		printf("Digite uma das opcoes:\n");
		printf("\tN-Para cadastrar novo produto\n");
		printf("\tL-Para listar todos os cadastros\n");
		printf("\tE-Para encerrar o programa\n");
		fflush(stdin);
		scanf("%c",&opcao);
			switch(opcao){
				case 'n':
				case 'N':
					do{
						novoCadastro(&opcao);
					}while(opcao=='n' || opcao=='N');
				break;
				case 'l':
				case 'L':
					listaCadastros(&opcao);	
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
//objetivo: cadastrar um novo produto
//parametros:
//retorno: nenhum
void novoCadastro(char *opcao){
	struct infoRoupa roupa;
	FILE *pArq;
	system("cls");
	printf("Digite o codigo unico da jaqueta\n");
	scanf("%d",&roupa.codigo);
	validaTamCodigo(&roupa.codigo);
	validaCodigo(&roupa.codigo);
	printf("Digite o tamanho da peca\n");
	fflush(stdin);
	fgets(roupa.tamanho,TAM_SIGLA,stdin);
	validaTamanho(roupa.tamanho);
	printf("Digite a cor da peca\n");
	fflush(stdin);
	fgets(roupa.cor,TAMANHO_COR,stdin);
	validaCor(roupa.cor);
	arrumaCor(roupa.cor);
	pArq=fopen("roupas.bin","ab");
	fwrite(&roupa,sizeof(roupa),1,pArq);
	fclose(pArq);
	printf("Digite 'M' para voltar ao menu, e 'N' para cadastrar outra roupa\n");
	fflush(stdin);
	scanf("%c",opcao);
}
//objetivo: listar os produtos cadastrados
//parametros:
//retorno: nenhum
void listaCadastros(char *opcao){
	int bytes,tamanhoArq,auxVetor=0,aux;
	FILE *pArq;
	struct infoRoupa *roupa,auxArquivo;
	pArq=fopen("roupas.bin","rb");
	if(fopen==NULL){
		printf("Nao abriu corretamente\n");
	}
	else{
		fseek(pArq,0,SEEK_END);
		tamanhoArq=ftell(pArq);
		bytes=tamanhoArq/sizeof(roupa);
		roupa=(struct infoRoupa*)calloc(bytes,sizeof(roupa));
		rewind(pArq);
		printf("chegou aqui\n");
			while(fread(&auxArquivo,sizeof(auxArquivo),1,pArq)){
				roupa[auxVetor].codigo=auxArquivo.codigo;
				strcpy(roupa[auxVetor].cor,auxArquivo.cor);
				strcpy(roupa[auxVetor].tamanho,auxArquivo.tamanho);
				auxVetor++;
			}
	}
	if(fclose(pArq)!=0){
		printf("Nao fechou corretamente\n");
	}
	else{
		bubbleSort(roupa,&auxVetor);
		printf(" CODIGO\t TAMANHO COR\n");
		for(aux=0;aux<auxVetor;aux++){
			printf("%d- %d\t %s\t %s\n",aux+1,roupa[aux].codigo,roupa[aux].tamanho,roupa[aux].cor);
		}
		printf("Digite 'M' para voltar ao menu, ou 'E' para encerrar\n");
		fflush(stdin);
		scanf("%c",opcao);
	}
		
}
//objetivo: mostrar a quantidade de roupas de cada tamanho estao disponiveis,
// 			e grava em um arquivo de backup.
//parametros:
//retorno: nenhum
void encerra(){
	FILE *pBackup,*pArq;
	int contadorP=0,contadorM=0,contadorG=0,contadorXG=0;
	struct infoRoupa auxArquivo;
	system("cls");
	while(fread(&auxArquivo,sizeof(auxArquivo),1,pArq)){
		if(strcmp(auxArquivo.tamanho,"P")==0){
			contadorP++;
		}
		else if(strcmp(auxArquivo.tamanho,"M")==0){
			contadorM++;
		}
		else if(strcmp(auxArquivo.tamanho,"G")==0){
			contadorG++;
		}
		else if(strcmp(auxArquivo.tamanho,"XG")==0){
			contadorXG++;
		}
	}
	printf("  TAMANHO\t\tQUANTIDADE\n");
	printf("P-Pequena\t\t%d\n",contadorP);
	printf("M-Media\t\t%d\n",contadorM);
	printf("G-Grande\t\t%d\n",contadorG);
	printf("E-Extra Grande\t\t%d\n",contadorXG);
	pArq=fopen("roupas.bin","rb");
	while(fread(&auxArquivo,sizeof(auxArquivo),1,pArq)){
		pBackup=fopen("backup.bin","ab");
		fwrite(&auxArquivo,sizeof(auxArquivo),1,pBackup);
		fclose(pBackup);
	}
	fclose(pArq);
}
//objetivo: validar o tamanho do código
//parametros: codigo 
//retorno: nenhum
void validaTamCodigo(int *codigo){
	while(*codigo<= MIN_CODIGO){
		printf("O codigo deve ser maior que %d, digite novamente\n",MIN_CODIGO);
		fflush(stdin);
		scanf("%d",codigo);
	}
}
//objetivo: validar se código ja existe
//parametros: codigo 
//retorno: nenhum
void validaCodigo(int *codigo){
	FILE *pArq;
	struct infoRoupa auxArquivo;
	pArq=fopen("roupas.bin","rb+");
	if(pArq==NULL){
		pArq=fopen("roupas.bin","wb");
	}
		while(fread(&auxArquivo,sizeof(auxArquivo),1,pArq)){
			while(auxArquivo.codigo == *codigo){
				printf("Esse codigo ja existe, digite novamente\n");
				fflush(stdin);
				scanf("%d",codigo);
				validaTamCodigo(codigo);
				validaCodigo(codigo);
			}
		}
	fclose(pArq);
}
//objetivo: validar se código ja existe
//parametros: codigo 
//retorno: nenhum
void validaTamanho(char *tamanho){
	int aux;
	tiraEnter(tamanho);
	for(aux=0;aux<strlen(tamanho);aux++){
		tamanho[aux]=toupper(tamanho[aux]);
	}
	while(strcmp(tamanho,"P")!=0 && strcmp(tamanho,"M")!=0 && strcmp(tamanho,"G")!=0 && strcmp(tamanho,"XG")!=0){
		printf("Tamanho invalido, digite:\n");
		printf("P- Pequeno\n");
		printf("M- Medio\n");
		printf("G- Grande\n");
		printf("XG- Extra-Grande\n");
		fflush(stdin);
		fgets(tamanho,TAM_SIGLA,stdin);
		validaTamanho(tamanho);
	}
	while(strlen(tamanho)<1){
		printf("Tamanho invalido\n");
		fflush(stdin);
		fgets(tamanho,TAM_SIGLA,stdin);
	}
}
//objetivo: tirar o enter
//parametros: frase ou sigla 
//retorno: nenhum
void tiraEnter(char *string){
	int tam=strlen(string);
		if(string[tam-1]=='\n'){
			string[tam-1]='\0';
		}
	
}
//objetivo: tirar o enter
//parametros: frase ou sigla 
//retorno: nenhum
void validaCor(char *cor){
	tiraEnter(cor);
	while(strlen(cor)<1 || strlen(cor)>TAMANHO_COR){
		printf("Tamanho invalido\n");
		fflush(stdin);
		fgets(cor,TAMANHO_COR,stdin);
	}
}
//objetivo: tirar o enter
//parametros: frase ou sigla 
//retorno: nenhum
void arrumaCor(char *cor){
	int aux;
	for(aux=0;aux<strlen(cor);aux++){
		cor[aux]=tolower(cor[aux]);
	}
}
//objetivo: ordenar os registros de acordo com as siglas
//parametros: registros 
//retorno: nenhum
void bubbleSort(struct infoRoupa *roupa,int *auxVetor){
	int linhas,colunas;
	struct infoRoupa auxiliar;
	for(linhas=0;linhas<*auxVetor;linhas++){
			for(colunas=0;colunas<*auxVetor-1;colunas++){
				if(strcmp(roupa[colunas].tamanho,roupa[colunas+1].tamanho)>0){
					auxiliar=roupa[colunas];
					roupa[colunas]=roupa[colunas+1];
					roupa[colunas+1]=auxiliar;
				}
			}
		}
}
