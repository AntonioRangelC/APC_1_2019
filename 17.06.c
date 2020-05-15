 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct dados {
  char nome[MAX];
  int ddd; 
  
};
void mostraResultado();
void meu_fflush();

//Sintese:
// Objetivo: cadastrar cidades e seus respectivos DDD
// Entrada: nomes das cidades e seus números de DDD
// Saida: nenhum
int main () {
  struct dados cidade;
  int i = 0,qtd;
  FILE *p_arq;
  printf("Quantas cidades voce quer cadastrar?\n");
  scanf("%d",&qtd);
  if ((p_arq=fopen("Local.bin","ab"))==NULL)
  { 
    puts("Arquivo nao pode ser aberto.");
    getchar();
    exit(1); 
  }
  else
  { 
    puts("Informe o DDD da cidade: ");
    scanf("%d",&cidade.ddd);
    
    while ((cidade.ddd>0)&&(i<qtd))
    { 
      //fflush(stdin);  Windows
      meu_fflush();
      do {
        puts("Informe o nome da cidade: ");
        fgets(cidade.nome,MAX,stdin);
        
        if(cidade.nome[strlen(cidade.nome)-1] == '\n')
            cidade.nome[strlen(cidade.nome)-1] = '\0';
      }while(strlen(cidade.nome)==0);
      
      fwrite(&cidade,sizeof(cidade),1, p_arq);
      i++;

      puts("Informe o DDD da cidade: ");
      scanf("%d",&cidade.ddd);
    } // fim do while

  fclose(p_arq);
  } // fim do else
  mostraResultado();
  return 0;
} // fim do programa

// ============= SUBPROGRAMA ===========

//Objetivo: executar a 'limpeza' do buffer manualmente
//Parametros: nenhum
//Retorno: nenhum
void meu_fflush(){
  char letra;
  
  do{
    letra = getchar();
  }while(letra != '\0' && letra != '\n');
}
//Objetivo: executar a 'limpeza' do buffer manualmente
//Parametros: nenhum
//Retorno: nenhum
void mostraResultado(){
  struct dados cidade;
  int aux;
  FILE *p_arq=fopen("Local.bin","rb");
  if(!p_arq){
    printf("Erro ao ler arquivo\n");
    exit(1);
  }
    while(fread(&cidade,sizeof(cidade),1,p_arq)){
      printf("Cidade: %s\n",cidade.nome);
      printf("DDD: %d\n",cidade.ddd);
    }
    fclose(p_arq);
}
