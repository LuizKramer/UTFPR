#include <stdio.h>
#include <stdlib.h>

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
   metodoGuloso(horaInicio,horaFim,n);
}
