#include <stdio.h>
#include <stdlib.h>
#define max(a, b) a > b ? a : b

int divisaoEConquista(int *v, int ini, int fim){
    int m, a=0, b=0;
    if ((fim - ini) <= 1)
        if(ini == fim){
            if(v[ini]>0)
                return v[ini];
            }
        else{
            m = 0;
            if(v[ini]>0)
                m += v[ini];
            if(v[fim]>0)
                m += v[fim];
            return m;
        }
    else{
        m = (ini + fim) / 2;
        a += divisaoEConquista(v, ini, m);
        b += divisaoEConquista(v, m + 1, fim);
    }
    return a+b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int v[n];
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    printf ("%d", divisaoEConquista(v, 0, n-1));
}
