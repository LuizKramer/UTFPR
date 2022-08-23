#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int id; 
    int horaInicio; //inicial
    int horaFim; //final
}aulas;

void bubblesort(aulas * aula, int n){
    int i,j;
    aulas aux;
    for(i=0; i<n; i++){
        for(j=0; j<n-1-i; j++){
            if(aula[j].horaFim > aula[j+1].horaFim){
                    aux = aula[j];
                    aula[j] = aula[j+1];
                    aula[j+1] = aux;            
            }
        }
    }
}
// Refatorei o código feito em 2021-2 
// Feito durante a aula 23/08/2022
void metodoGuloso(aulas * aulas, int n){
    int aulasAlocadas[n], i, a, b;
    b = aulas[0].horaFim;
    a=1;
    aulasAlocadas[0] = 0;
    for(i=1; i<n ;i++){
        if (aulas[i].horaInicio > b){
            aulasAlocadas[a] = i;
            b = aulas[i].horaFim;
            a++;
        }
    }
    printf("Aulas alocadas: ");
    for(i=0; i<a; i++)
        printf("%d ", aulas[aulasAlocadas[i]].id);
}

int main()
{
   int n, i;
 
    
   scanf("%d", &n);
   aulas aulas[n];
   for(i=0; i<n; i++){
        scanf("%d %d %d", &aulas[i].id, &aulas[i].horaInicio, &aulas[i].horaFim);
   }
   bubblesort(aulas, n);
   metodoGuloso(aulas, n);
}
