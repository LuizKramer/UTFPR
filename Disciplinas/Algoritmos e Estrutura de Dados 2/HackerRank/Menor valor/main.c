#include <stdio.h>
#define min(a, b) a < b ? a : b

int maxDQ(int v[], int ini, int fim){
    int m, a, b;

    if ((fim - ini) <= 1){
        return min(v[ini], v[fim]);
    }
    else{
        m = (ini + fim) / 2;
        printf("ini:[%d] fim:[%d] m:[%d] a:[%d] b:[%d]\n",ini, fim, m ,a ,b);
        a = maxDQ(v, ini, m);
        b = maxDQ(v, m + 1, fim);
    }
    return min(a,b);
}

int main(){
    int n;
    scanf("%d", &n);
    int v[n];
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    for(int i=0; i<n; i++){
        if(maxDQ(v, 0, n-1) == v[i]){
            printf("%d", i);
            i = n;
        }
    }
}

