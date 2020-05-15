//Sintese
//  Objetivo: identificar uma data a partir de seu valor sequencial no ano
//  Entradas: numero de dias e ano
//  Saidas: dia, mes e ano

#include <stdio.h>
int validaAno(int *ano);
int validaDias(int *dias, int *bissexto);
int verificaBissexto(int *ano);
void calculaDiaMes(int *bissexto, int *dias, int *ano);
int contaDias(int *bissexto, int *mes);

int main() {
    int ano, dias, bissexto;
	
	// Entrada exigida no enunciado
    scanf("%d %d", &dias, &ano);
    
    if(!validaAno(&ano)){
      printf("Entradas invalidas!");
      return 0;
	}
    else {
    	bissexto = verificaBissexto(&ano);
		if(!validaDias(&dias, &bissexto)){
			printf("Entradas invalidas!");
			return 0;
		}
		else 
			calculaDiaMes(&bissexto, &dias, &ano);
	}
    return 0;
}


// ================ SUBPROGRAMAS ==============

// Objetivo: validar ano informado
// Parâmetros: ano
// Retorno: ano valido
int validaAno(int *pAno)
{
    if((*pAno < 0) || (*pAno > 9999))
       return 0;
    else
	   return 1;
}

// Objetivo: validar sequencial que corresponde aos dias
// Parâmetros: sequelcial de dias e bissexto
// Retorno: situacao dos dias validos
int validaDias(int *dias, int *bissexto)
{
	int maxDias;
	if (*bissexto)
	  maxDias = 366;
	else
	  maxDias = 365;
    if((*dias <= 0 ) || (*dias > maxDias))
       return 0;
    else
	   return 1;
}

// Objetivo: validar sequencial que corresponde aos dias
// Parâmetros: sequelcial de dias
// Retorno: sequencial valido
int verificaBissexto(int *ano)
{
    if(((*ano % 400) == 0) || (((*ano % 4) == 0) && ((*ano % 100) != 0)))
       return 1;
    else
	   return 0;
}

// Objetivo: calcula dia e mes
// Parâmetros: bissexto, sequelcial de dias e ano
// Retorno: sem retorno
void calculaDiaMes(int *bissexto, int *dias, int *ano){
    int dia, totalDias = 0;
    int mes = 1;
    
    while(totalDias < (*dias)){
        totalDias += contaDias(bissexto, &mes);
        mes++;
    }
    mes--;
    dia = contaDias(bissexto, &mes) - (totalDias - *dias);
    
    // Saida exigida no enunciado
    printf("%02d/%02d/%04d\n", dia, mes, *ano);
    
}

// Objetivo: calcula quantidad de dias
// Parâmetros: bissexto e mes
// Retorno: quantidade de dias por mes
int contaDias(int *bissexto, int *mes){
    switch(*mes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            if((*bissexto) == 1)
                return 29;   
            else
                return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
    }
}

