#include <stdio.h>
//prototipos
int validaAno(int *pAno);
int validaDias(int *pDias,int *ehBissexto);
int verificaBissexto(int *pAno);
void calculaDiaMes(int *pDiasMes,int *pDias,int *pMes, int *ehBissexto);
//objetivo: mostrar a data a partir da quantidade de dias fornecidos
//entrada: quantidade de dias já passados, ano
//saída: data atual
int main (){
	int dias,ano,ehBissexto,mes,aux;
	scanf("%d%d",&dias,&ano);
	ehBissexto=verificaBissexto(&ano);
	if(!validaAno(&ano)){
		printf("Entradas invalidas!\n");
	}
	else if(!validaDias(&dias,&ehBissexto)){
		printf("Entradas invalidas!\n");
	}
	else{
	
	calculaDiaMes(&dias,&aux,&mes,&ehBissexto);
	printf("%02d/%02d/%04d\n",aux,mes,ano);
	//printf("bissexto: %d\n",ehBissexto);
	}
	
	return 0;
}
//objetivo: validar o ano
//parametros: ano
//retorno: 0 se for invalido, 1 se for valido
int validaAno(int *pAno){
	if(*pAno<0 || *pAno>9999){
		return 0;
	}
	else
	return 1;
	
}
//objetivo: validar os dias
//parametros: dias, conteudo do endereço da variavel ehBissexto
//retorno: 0 se for invalido, 1 se for valido
int validaDias(int *pDias, int *ehBissexto){
	if(*pDias<1 || (*pDias > 366 && *ehBissexto==1)){
		return 0;
	}
	else if(*pDias<1 || (*pDias > 365 && *ehBissexto==0)){
		return 0;
	}
	else
	return 1;
}
//objetivo: verificar se o ano é bissexto
//parametros: ano
//retorno: 0 se nao for bissexto, 1 se for bissexto
int verificaBissexto(int *pAno){
	if(*pAno % 400 == 0 || (*pAno % 4 == 0 && *pAno % 100 != 0)){
		return 1;
	}
	else
	return 0;
}
//objetivo: calcular o dia e o mes
//parametros: dias, enderaço das variaveis
//retorno:	nenhum
void calculaDiaMes(int *pDiasMes,int *pDias,int *pMes,int *ehBissexto){
	if(*ehBissexto==0){
		if(*pDiasMes>=1 && *pDiasMes<=31){
				*pMes=1;
				*pDias= *pDiasMes;
		}
		else if(*pDiasMes>31 && *pDiasMes<=59){
				*pMes=2;
				*pDias= (*pDiasMes - 31);
		}
		else if(*pDiasMes>59 && *pDiasMes<=90){
				*pMes=3;
				*pDias= (*pDiasMes - 59);
		}
		else if(*pDiasMes>90 && *pDiasMes<=120){
				*pMes=4;
				*pDias= (*pDiasMes - 90);
		}
		else if(*pDiasMes>120 && *pDiasMes<=151){
				*pMes=5;
				*pDias= (*pDiasMes - 120);
		}
		else if(*pDiasMes>151 && *pDiasMes<=181){
				*pMes=6;
				*pDias= (*pDiasMes - 151);
		}
		else if(*pDiasMes>181 && *pDiasMes<=212){
				*pMes=7;
				*pDias= (*pDiasMes - 181);
		}
		else if(*pDiasMes>212 && *pDiasMes<=243){
				*pMes=8;
				*pDias= (*pDiasMes - 212);
		}
		else if(*pDiasMes>243 && *pDiasMes<=273){
				*pMes=9;
				*pDias= (*pDiasMes - 243);
		}
		else if(*pDiasMes>273 && *pDiasMes<=304){
				*pMes=10;
				*pDias= (*pDiasMes - 273);
		}
		else if(*pDiasMes>304 && *pDiasMes<=334){
				*pMes=11;
				*pDias= (*pDiasMes - 304);
		}
		else if(*pDiasMes>334 && *pDiasMes<=365){
				*pMes=12;
				*pDias= (*pDiasMes - 334);
		}
	}
	else if(*ehBissexto==1){
		if(*pDiasMes>=1 && *pDiasMes<=31){
				*pMes=1;
				*pDias= *pDiasMes;
		}
		else if(*pDiasMes>31 && *pDiasMes<=60){
				*pMes=2;
				*pDias= (*pDiasMes - 31);
		}
		else if(*pDiasMes>60 && *pDiasMes<=91){
				*pMes=3;
				*pDias= (*pDiasMes - 60);
		}
		else if(*pDiasMes>91 && *pDiasMes<=121){
				*pMes=4;
				*pDias= (*pDiasMes - 91);
		}
		else if(*pDiasMes>121 && *pDiasMes<=152){
				*pMes=5;
				*pDias= (*pDiasMes - 121);
		}
		else if(*pDiasMes>152 && *pDiasMes<=182){
				*pMes=6;
				*pDias= (*pDiasMes - 152);
		}
		else if(*pDiasMes>182 && *pDiasMes<=213){
				*pMes=7;
				*pDias= (*pDiasMes - 182);
		}
		else if(*pDiasMes>213 && *pDiasMes<=244){
				*pMes=8;
				*pDias= (*pDiasMes - 213);
		}
		else if(*pDiasMes>244 && *pDiasMes<=274){
				*pMes=9;
				*pDias= (*pDiasMes - 244);
		}
		else if(*pDiasMes>274 && *pDiasMes<=305){
				*pMes=10;
				*pDias= (*pDiasMes - 274);
		}
		else if(*pDiasMes>305 && *pDiasMes<=335){
				*pMes=11;
				*pDias= (*pDiasMes - 305);
		}
		else if(*pDiasMes>335 && *pDiasMes<=366){
				*pMes=12;
				*pDias= (*pDiasMes - 335);
		}
	}
}
