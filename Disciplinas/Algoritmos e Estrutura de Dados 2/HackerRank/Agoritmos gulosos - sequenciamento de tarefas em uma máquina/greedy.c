#include <stdio.h>
#define INT_MIN  (-2147483648)


typedef struct{
    int id; // identificador da tarefa, que será a i-ésima tarefa lida
    int e; // tempo de execução
    int d; // deadline
}tarefas;

//Implementei durante aula 22/08/2022 
int maiorValor(int * V, int N){
    int i, j, aux, indice=0;
    aux = V[0];
    for(i=0; i<N; i++){
            if(aux < V[i]){
                aux = V[i];
                indice = i;
            }
    }
    return indice;
}


void greedy(tarefas * a, int N){
    int v[N], pos[N], b=0, i; 
    pos[0]=0;
    for(int i=0; i<N; i++){
        v[i] = a[i].d - a[i].e;
    }
    for(i=0; i<N; i++){
        pos[i] = maiorValor(v, N); 
        v[pos[i]] = INT_MIN;
    }

    for(int i = 0; i<N; i++){
        printf("%d ", pos[i]); 
    }
}


int main(){
    int N, i;
    scanf("%d", &N);
    tarefas tarefa[N];
    for(i=0; i < N; i++){
        tarefa[i].id = i;
        scanf("%d", &tarefa[i].e);
        scanf("%d", &tarefa[i].d);
    }

    greedy(tarefa, N);    
}