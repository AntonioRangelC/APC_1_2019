#include <stdio.h>
#define MAX 100

struct infoAluno
{
    int cnic;
};

int validaCnic(int cnic, struct infoAluno vetor[],int aux);

int main()
{
    struct infoAluno aluno[10];
    int aux, qtd;

    printf("Digite a quantidade: ");
    scanf("%d", &qtd);

    for(aux = 0; aux < qtd; aux++)
    {
        scanf("%d", &aluno[aux].cnic);
        aluno[aux].cnic = validaCnic(aluno[aux].cnic, aluno, aux);

        printf("O aluno %d tem cnic %d\n", aux, aluno[aux].cnic);
    }
    return 0;
}

int validaCnic(int cnic, struct infoAluno vetor[], int aux)
{
    int auxVetor;
    while(cnic <= 0)
    {
        printf("cnic invalido. Tente novamente: ");
        scanf("%d", &cnic);
    }
    for(auxVetor = aux-1; auxVetor >= 0; auxVetor--)
    {
        if(vetor[auxVetor].cnic == cnic)
        {
            printf("Esse numero ja existe, digite outro: ");
            scanf("%d", &cnic);
            return validaCnic(cnic, vetor, aux);
        }
    }
    return cnic;
}
