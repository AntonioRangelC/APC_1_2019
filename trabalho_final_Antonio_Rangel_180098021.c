#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MAXSIGLA 10
//Síntese
//objetivo: registrar cursos profissionalizantes, alterar dados de um curso já cadastrado, listar os cursos cadastrados, remover o arquivo de cadastro
//entrada: para fazer um cadastro, a entrada vai ser: "1",código numérico de identificação do curso, 
//			modalidade do curso, nome completo do curso, sigla da escola.
//			"2" para alterar dados do curso, "3" para listar os cursos, "4" para consultar os cursos cadastrados
//			"5" para remover o arquivo, "0" para encerrar o programa.
//saída: a saída deve ser um novo curso cadastrado, ou os dados de um curso devem ser alterados
//		 ou uma lista dos cursos será mostrada, ou os dados de um curso específico devem ser mostrados,
//		 ou um arquivo deve ser removido

//prototipos
int validaOpcao();
char validaNomeCurso();
char validaModalidade();
int validaCNIC();
char validaSigla();
int validaMenu();
//####### PRINCIPAL ###### 
int main() {
	//declarações
	int opcao,menu=1,CNIC;
	char nomeCurso[25],modalidade,sigla[MAXSIGLA];
	//implementação
	do{
		printf("\t\t\t\t\t\t\t\t\ CURSOS PROFISSIONALIZANTES\n");
		printf("\t\t\t\tSeja Bem-vindo(a), digite uma das opcoes abaixo\n");
		printf("\t\t1. Novo Curso\n");
		printf("\t\t2. Altera dados do Curso\n");
		printf("\t\t3. Lista todos os Cursos cadastrados\n");
		printf("\t\t4. Consulta os Cursos cadastrados de uma unica modalidade especifica\n");
		printf("\t\t5. Remove arquivo com os cadastros de todos os cursos\n");
		printf("\t\t0. Encerra o programa\n");
		scanf("%d",&opcao);
		validaOpcao();
			while(opcao==1 && menu==1){
				system("cls");
				printf("Voce escolheu a opcao 1, vamos cadastrar um novo curso\n");
				printf("Digite o nome completo do curso\n");
				fgets(nomeCurso,25,stdin);
				validaNomeCurso();
				system("cls");
				printf("Digite P para cadastrar um curso presencial, e D para cadastrar um curso a distancia\n");
				scanf("%c",&modalidade);
				validaModalidade();
				system("cls");
				printf("Digite o código Numerico de Identificacao do Curso (CNIC). O valor deve er maior que 100\n");
				scanf("%d",&CNIC);
				validaCNIC();
				system("cls");
				printf("Digite a Sigla da Escola, com o maximo de 10 caracteres\n");
				fgets(sigla,MAXSIGLA,stdin);
				validaSigla();
				system("cls");
				printf("Cadastro concluido! para cadastrar mais um curso, digite 1, e para voltar ao menu, digite 0\n");
				scanf("%d",menu)
				validaMenu();
			}
	}while(opcao!=0);
	return 0;
}
