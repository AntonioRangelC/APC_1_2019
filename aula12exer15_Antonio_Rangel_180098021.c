#include <stdio.h>

int main(void) {
 int anos[3][3],linhas,colunas;
 do{
   for(linhas=0;linhas<3;linhas++){
     for(colunas=0;colunas<3,colunas++){
        if(linhas==2 && colunas==2){
          colunas++;
        }
        else{
        printf("Digite o valor linha:%d coluna%d",linha+1,coluna+1);
        scanf("%d",anos[linhas][colunas]);
        }
     }
    }
 }while(opcao!=0);
  return 0;
}
