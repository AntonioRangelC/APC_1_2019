#include <stdio.h>
//objetivo: somar todos os elementos de uma matriz e imprimi-la. Mas na posiçao (1,1), terá a soma
//entrada: numeros maiores que 1900, e menores que o ano atual
//saída: matriz com os valores digitados, a soma na posição (1,1), e a média de todos os valores
void validaAnos(int *anos);
int main(void) {
 int anos[3][3],linhas,colunas,opcao;
 float soma=0.0;
 do{
   for(linhas=0;linhas<3;linhas++){
     for(colunas=0;colunas<3;colunas++){
        if(linhas==1 && colunas==1){
          continue;
        }
        else{
        printf("Digite o valor linha: %d coluna %d  ",linhas+1,colunas+1);
        scanf("%d",&anos[linhas][colunas]);
        validaAnos(&anos[linhas][colunas]);
        soma+=anos[linhas][colunas];
        }
     }
    }
    for(linhas=0;linhas<3;linhas++){
     for(colunas=0;colunas<3;colunas++){
        if(linhas==1 && colunas==1){
          printf("%.0f ",soma);
        }
        else{
        printf("%d ",anos[linhas][colunas]);
        }
     }
     printf("\n");
    }
    printf("Media :%.2f\n",soma/8.0);
    printf("Para sair, digite 0, para continuar digite outro numero\n");
    scanf("%d",&opcao);
 }while(opcao!=0);
  return 0;
}
//objetivos: validar o valor digitado
//parâmetro: valor digitado
//retorno: nenhum
void validaAnos(int *anos){
	while(*anos<1900 || *anos>2019){
		printf("Valor deve ser maior que 1900, digite novamente\n");
		scanf("%d",anos);
	}
}
