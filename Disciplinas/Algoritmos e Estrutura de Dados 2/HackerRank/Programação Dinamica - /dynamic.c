#include <stdio.h>
#include <stdin.h>
#include <limits.h>

int corte_hastes(int * preco, int * tamanho, int N){
    
}


int main(){
    int N, tam;
    scanf("%d", &tam);
    scanf("%d", &N);

    int preco[N], tamanho[N];

    for(int i = 0; i<N ; i++){
        scanf("%d %d", &tamanho[i], &preco[i]);
    }

    corte_hastes(preco, tamanho, N);

}