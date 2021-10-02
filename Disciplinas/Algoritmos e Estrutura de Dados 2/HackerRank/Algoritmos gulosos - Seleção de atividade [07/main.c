#include <stdio.h>
#include <stdlib.h>


void bubblesort(int *horaInicio, int *horaFim, int n){
    int aux,i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n-1-i; j++){
            if(horaFim[j]>horaFim[j+1]){
                    aux = horaFim[j];
                    horaFim[j] = horaFim[j+1];
                    horaFim[j+1] = aux;
                    aux = horaInicio[j];
                    horaInicio[j] = horaInicio[j+1];
                    horaInicio[j+1] = aux;
            }
        }
    }
}

void metodoGuloso(int *horaInicio, int *horaFim, int n){
    int aulasAlocadas[n], a,b;
    int duracaoAula[n];
    int i = 0;
    for(a=0; a<n; a++){
        duracaoAula[a] = horaFim[a] - horaInicio[a];
    }
    b = duracaoAula[0];
    for(a=0; a<n; a++){
        if(duracaoAula[a+1] < b){
            aulasAlocadas[i] = a;
            b = duracaoAula[a];
            i++;
        }
    }
    for(a=0; a<i; a++){
        printf("%d ", aulasAlocadas[a]);
    }
}
int main()
{
   int n;
   scanf("%d", &n);
   int horaInicio[n], horaFim[n];
   for(int i=0; i<n; i++){
        scanf("%d %d", &horaInicio[i], &horaFim[i]);
   }
   bubblesort(horaInicio, horaFim, n);
  metodoGuloso(horaInicio,horaFim,n);
}
