#include <stdio.h>

int retornaDiasMes(int *ehBissexto, int *mes){
    switch(*mes){
        case 1:
            return 31;
        case 2:
            if((*ehBissexto) == 1){
                return 29;   
            }
            else{
                return 28;
            }
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        break;
        case 12:
            return 31;
        default:
            return 0;
    }
}

void calculaDiaMes(int *ehBissexto, int *diaMes, int *mes, int *dia){
    int diasTotais = 0;
    *mes = 1;
    
    while(diasTotais < (*diaMes)){
        diasTotais += retornaDiasMes(ehBissexto, mes);
        (*mes)++;
    }
    (*mes)--;
    *dia = retornaDiasMes(ehBissexto, mes) - (diasTotais - (*diaMes));
    
}

int verificaSeEhBissexto(int *ano){
    if((*ano) % 400 == 0){
        return 1;
    }
    else{
        if(((*ano) % 4 == 0) && ((*ano) % 100 != 0) ){
            return 1;
        }
    }
    return 0;
}

int validaDiaAno(int *ehBissexto, int *diaMes){
    if(((*ehBissexto) == 1 && (*diaMes) <= 366) || ((*ehBissexto) == 0 && (*diaMes) <= 365)){
        return 1;
    }
    return 0;
}

int main() {
    int ano, diaMes;
    int mes, dia;
    int ehBissexto;
    
    // Entrada solicitada
    scanf("%d %d", &diaMes, &ano);
    
    ehBissexto = verificaSeEhBissexto(&ano);
    if(validaDiaAno(&ehBissexto, &diaMes) == 0){
        printf("Entradas invalidas!\n");
    }
    else{
        calculaDiaMes(&ehBissexto, &diaMes, &mes, &dia);
        
        // Saida final
        printf("%02d/%02d/%04d\n", dia, mes, ano);
    }
    
    return 0;
}
