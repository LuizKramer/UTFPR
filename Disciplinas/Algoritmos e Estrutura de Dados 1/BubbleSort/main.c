#include <stdio.h>
#include <stdlib.h>

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
    for(i=0; i<N; i++){
        printf("%d ", vet[i]);
    }

}

int main()
{
   int a, N;
   scanf("%d", &N);
   int vet[N];
   for(a=0; a<N; a++){
        scanf("%d", &vet[a]);
   }
    bubblesort(vet, N);

}
