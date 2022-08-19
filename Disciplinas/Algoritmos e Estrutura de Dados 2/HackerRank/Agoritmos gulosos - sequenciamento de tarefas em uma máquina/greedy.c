#include <stdio.h>

typedef struct{
    int id; // identificador da tarefa, que será a i-ésima tarefa lida
    int e; // tempo de execução
    int d; // deadline
}tarefas;


void greedy(tarefas * a, int N){
    int v[N], pos[N];
    for(int i=0; i<N; i++){
        v[i] = a[i].d - a[i].e;
    }

    for(int i=0; i<N; i++){
       
         for(int j=0; j<N; j++){
            if(v[i] < v[j+1]){
                pos[i] = j;
                printf("%d ", j);
            }
        }

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