#include <stdio.h>
//objetivo: validar o peso fornecido
//parametro: peso
//retorno: 0 ou 1
int validaPeso (double pesoKg){
	if(pesoKg<0){
		return 0;
	}	
	return 1;
}
//objetivo: apresentar o peso em gramas
//parametro: peso
//retorno: nehum
 void fazGrama (double pesoKg){
	printf("%.4lf\n",pesoKg*1000);
}
//objetivo: apresentar o peso em toneladas
//parametro: peso
//retorno: nehum
void fazTonelada (double pesoKg){
	printf("%.4lf\n",pesoKg/1000);
}


