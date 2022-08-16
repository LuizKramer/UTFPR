#include <stdio.h>
#include <stdlib.h>
//Retirei do meu GIT
void bubblesort(int *vet, int N){
    int aux,i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N-1-i; j++){
            if(vet[j]>vet[j+1]){
                    aux = vet[j];
                    vet[j] = vet[j+1];
                    vet[j+1] = aux;
            }
        }
    }
}

void shift(int *v, int N){
    int aux;
    for(int i=0; i<N; i++){
        aux = v[i];
        v[i] = v[N-1];
        v[N-1] = aux;
    }
}

int main()
{
    int valorTroco, qtdModedas, i;
    scanf("%d %d", &valorTroco, &qtdModedas);
    int moedas[qtdModedas];

    for(i = 0; i < qtdModedas; i++){
        scanf("%d", &moedas[i]);
    }

    bubblesort(moedas, qtdModedas);

    for(i = 0; i < qtdModedas; i++){
        printf("[%d] ", moedas[i]);
    }
    while(1){
        if(moedas[qtdModedas-1] <= valorTroco){
            printf("%d\n", moedas[qtdModedas-1]);
            valorTroco -= moedas[qtdModedas-1];
        }
        else{
            shift(moedas, qtdModedas);
        }
        if(valorTroco == 0){
            break;
        }
    }
}
