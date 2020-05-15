#include <stdio.h>
int main (){
	int linhas,colunas,Pmovimentos,A,B,aux;
	scanf("%d%d",&linhas,&colunas);
	int matrizCP[linhas][colunas],i=1,j=1,k=linhas,l=colunas;
	scanf("%d",&Pmovimentos);
		for(aux=0;aux<Pmovimentos;aux++){
			scanf("%d%d",&A,&B);
			  while(i<=linhas && i>0){   //primeiro professor
			  	if(A==3){
			  		i++;
				}
				else if(A==4){
					i--;
				}
			  	  while(j<=colunas && j>0){
			  		if(A==1){
			  			j++;
					}
					else if(A==2){
						j--;
					}
					
				  }
			  }
			  while(k>0 && k<linhas+1){		//segundo professor
			  	if(B==3){
			  		k++;
				  }
			    else if(B==4){
			    	k--;
				}
				  while(l>0 && l<colunas+1){
				  	if(B==1){
				  		l++;
					}
					else if(B==2){
						l--;
					}
				  }
			  }
		if(i==k && j==l){
			printf("Encontraram-se na posicao (%d,%d) no passo %d\n",i,j,aux+1);
		}
		else if(i>linhas || j>colunas){
			printf("PA saiu na posicao (%d,%d) no passo %d\n",i,j,aux+1);
		}
		else if(k>linhas || l>colunas){
			printf("PB saiu na posicao (%d,%d) no passo %d\n",k,l,aux+1);
		}
		else if(i>linhas || j>colunas && k>linhas || l>colunas){
			printf("PA saiu na posicao (%d,%d) no passo %d\n",i,j,aux+1);
		}
		else
			printf("Nao se encontraram\n");
	}
	return 0;
}
