#include <stdio.h>
//prototipo validaLetra
char validaLetra(char letra);
//objetivo: validar a letra
//parametro: letra
//retorno: letra validada
char validaLetra(char letra){
	while(letra<65 || letra>90 && letra<97 || letra>122){
	    getchar();
	  	printf("Caracter invalido, digite novamente\n");
	  	scanf("%c",&letra);
	  }
	  return letra;
}
//prototipo mostraLetras
void mostraLetras(letra);
//objetivo: mostrar as letras ate o 'z' ou 'Z'
//parametro: letra
//retorno: nenhum
void mostraLetras(letra){
	int auxMaiusculo,auxMinusculo;
	if(letra>=65 && letra<=90){
	  	for(auxMaiusculo=letra;auxMaiusculo<=90;auxMaiusculo++){
	  		printf("%c ",auxMaiusculo);
		  }
	  }
	  else if(letra>=97 && letra<=122){
	  	 for(auxMinusculo=letra;auxMinusculo<=122;auxMinusculo++){
	  	 	printf("%c ",auxMinusculo);
		   }
	  }
	  return 0;
}
//objetivo: mostrar todas as letras do alfabeto minusculo ou maiusculo entre uma letra fornecida e 'Z' ou 'z'
//entrada: letra
//saída: alfabeto entre a letra e 'z' ou 'Z'
int main ()
{
	char letra;
	printf("Digite uma letra\n");
	scanf("%c",&letra);
	letra = validaLetra(letra);
	mostraLetras(letra);
	return 0;
}
