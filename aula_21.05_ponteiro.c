#include <stdio.h>
//prototipo trocaNumeros
void trocaNumeros(int *,int *);

//objetivo: trocar números
//entrada: dois valores de números
//saida: 
int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	printf("a : %d   b:%d\n",a,b);
	trocaNumeros(&a,&b);
	printf("Depois da troca:\n");
	printf("a : %d   b : %d\n",a,b);
	return 0;
}
//objetivo: fazer a troca dos valores
//parametros: dois inteiros
//retorno: nenhum
void trocaNumeros(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
	
}
