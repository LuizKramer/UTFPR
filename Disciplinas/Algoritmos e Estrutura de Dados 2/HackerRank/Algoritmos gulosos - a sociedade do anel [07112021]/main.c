#include <stdio.h>
#include <stdlib.h>

int verificaPrev(int *iPrev, int *jPrev, int i, int j, int d, int e){
    int a,b;
    for(a=0; a<=d ;a++){
        for(b=0; b<=e; b++){
            printf("\niPrev: %d jPrev: %d \ni: %d j: %d \neq1:%d == eq2:%d\nd: %d e: %d\n",iPrev[a], jPrev[b],(iPrev[a]+1)*(jPrev[b]+2),(i+1)*(j+2), i,j, d,e);
            if((iPrev[a]+1)*(jPrev[b]+2) == (i+1)*(j+2)){
                printf("Return 0\n");
                return 0;
            }
            else{
                printf("Return 1\n");
            }
        }
    }
}

int metodoGuloso(int l, int c, int M[l][c])
{
    int i,j, a, aux, iProx, jProx, d, e, b;
    j=0 , a, aux, iProx =0;
    i = 0;
    jProx, d=0;
    e=0, b = 0;
    aux=100;
    int iPrev[l], jPrev[c];
    iPrev[0]= 0;
    jPrev[0]= 0;
    printf("\n %d %d \n", d, e);
    while(b <6){
        aux = 100;
        for(a=0; a<5; a++){
            //mapeamento da posição
            if(a == 0){i--;}
            if(a == 1){i++;j--;}
            if(a == 2){j+=2;}
            if(a == 3){i++;j--;}
            if(a == 4){
                i--;
                iPrev[d] = i;
                printf("\nIprev mG:%d\n", iPrev[d]);
                jPrev[e] = j;
            };
            if(i>=0 && i<=5 && j>=0 && j<=5 && a!=4){
                if(verificaPrev(&iPrev[0], &jPrev[0], i, j, d, e)==1){
                    printf("%d%d: [%d] <= %d\n",i, j, M[i][j], aux);
                    if(M[i][j] <= aux){
                        aux = M[i][j];
                        iProx = i;
                        jProx = j;
                    }
                }
            }
        }

        d++;
        e++;
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
