#include <stdio.h>
//objetivo: formar envelopes com os rotulos
//entrada: total de totulos, tipos de rotulos
//saida: quantos rotulos Aldo pode formar
int main(){
	int total,tipos,aux,bala,aux2,minimo;
	scanf("%d%d",&total,&tipos);
	
	int rotulos[1000]={};
		for(aux=1;aux<=total;aux++){
			scanf("%d",&bala);
			rotulos[bala]++;
		}
		minimo=rotulos[1];
		for(aux2=1;aux2<=tipos;aux2++){
		//	printf("%d\n",rotulos[aux2]);
			if(rotulos[aux2]<minimo){
				minimo=rotulos[aux2];
				
			}
			/*else if(rotulos[aux2]>minimo){
				minimo=rotulos[aux2];
			}*/
		}
		 printf("%d\n",minimo);
	return 0;
}




