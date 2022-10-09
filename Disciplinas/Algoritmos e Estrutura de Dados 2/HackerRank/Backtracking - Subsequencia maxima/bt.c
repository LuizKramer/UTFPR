#include <stdio.h>
#define max(a, b) a > b? a : b

int submax(int *v, int n){
    int aux = v[0]; 
    int a = 0;
    for(int i = 1; i < n; i++){
        a = 0;
        for(int j = i; j>0; j--){
            a += v[j];
            aux = max(aux, a);
        }
    }
    return aux;
}

int main(){
    int n;
    scanf("%d", &n);
    int v[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    printf("%d", submax(v,n));
}
