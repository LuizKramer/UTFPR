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

        for(a=0; a<5; a++){
            //mapeamento da posição


            if(a == 1){i--;}
            if(a == 2){i++;j--;}
            if(a == 3){j+=2;}
            if(a == 4){i++;j--;}

            if(i>=0 && i<=5 && j>=0 && j<=5){
                printf("%d = %d\n",(i+1)*(j+2),(iPrev+1)*(jPrev+2));
                if((i+1)*(j+2) != (iPrev+1)*(jPrev+2)){
                    printf("%d%d: [%d]\n",i, j, M[i][j]);
                    if(M[i][j] <= aux){
                        aux = M[i][j];
                        iProx = i;
                        jProx = j;
                    }
                }
            }
            if(a == 0){
                iPrev = i;
                jPrev = j;
                printf("\nPREV %d%d\n", i, j);
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
