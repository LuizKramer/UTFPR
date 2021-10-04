#include <stdio.h>
#include <stdlib.h>
void bubblesort(int *horaInicio, int *horaFim, int n);
void metodoGuloso(int *horaInicio, int *horaFim, int n);

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
    int aulasAlocadas[n], i,a,b;
    b = horaFim[0];
    a=1;
    aulasAlocadas[0] = 0;
    for(i=1; i<n ;i++){
        if (horaInicio[i] > b){
            aulasAlocadas[a] = i;
            b = horaFim[i];
            a++;
        }
    }
    printf("Aulas alocadas: ");
    for(i=0; i<a; i++)
        printf("%d ", aulasAlocadas[i]);
}

int main()
{
   int n, i;
   scanf("%d", &n);
   int horaInicio[n], horaFim[n];
   for(i=0; i<n; i++){
        scanf("%d %d", &horaInicio[i], &horaFim[i]);
   }
   bubblesort(horaInicio,horaFim,n);
   metodoGuloso(horaInicio,horaFim,n);
}
