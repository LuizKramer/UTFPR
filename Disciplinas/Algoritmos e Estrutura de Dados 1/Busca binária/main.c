#include <stdio.h>
#include <stdlib.h>

int buscabin(int *vet, int N, int chave){
    int inicio = 0;
    int mid = (inicio + N)/2;
    while(inicio <= N){

        if(chave == vet[mid]){
            return mid;
        }
        else{
            if(chave < vet[mid]){
                N = (mid - 1);
            }
            else{
                inicio = (mid +1);
            }
        }
    mid = (inicio + N)/2;

    }
    return -1;

}

int main()
{
   int a, N,n,chave;
   scanf("%d", &N);
   int vet[N];
   for(a=0; a<N; a++){
        scanf("%d", &vet[a]);
   }

   scanf("%d", &n);
    for(a=0;a<n;a++){
        scanf("%d", &chave);
        fflush(stdin);
        printf("%d\n", buscabin(vet, N, chave));
    }
}
