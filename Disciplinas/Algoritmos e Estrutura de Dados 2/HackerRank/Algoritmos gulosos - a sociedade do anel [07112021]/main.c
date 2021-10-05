#include <stdio.h>
#include <stdlib.h>


int metodoGuloso(int l, int c, int M[l][c])
{
    int i =0;
    int j =0;
    int a = 0;
    int aux=100;
    int iProx =0;
    int jProx =0;
    int iPrev =0;
    int jPrev =0;
    i=0;
    j=0;
    int    b = 0;
    while(b <10){
        aux = 100;

        for(a=0; a<5; a++){
            //mapeamento da posição
            if(a == 0){i--;}
            if(a == 1){i++;j--;}
            if(a == 2){j+=2;}
            if(a == 3){i++;j--;}
            if(a == 4){
                i--;
                iPrev = i;
                jPrev = j;
                printf("\niPrev: %d  jPrev:%d\n", iPrev, jPrev);
            };

            if(i>=0 && i<=5 && j>=0 && j<=5 && a!=4){
                if(!(i == iPrev && j==jPrev)){
                    printf("%d%d: [%d] <= %d\n",i, j, M[i][j], aux);
                    if(M[i][j] <= aux){
                        aux = M[i][j];
                        iProx = i;
                        jProx = j;
                    }
                }
            }
        }
        i = iProx;
        j = jProx;
        printf("\nPROX %d%d\n", iProx, jProx);

        b++;
    }
    return aux;
}

int main()
{
    int l, c, i, j;
    scanf("%d %d", &l, &c);
    int M[l][c];
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            scanf("%d", &M[i][j]);
        }
    }
    printf("\n%d", metodoGuloso(l,c,M));
}
