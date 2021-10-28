#include <stdio.h>
#include <stdlib.h>
# define max(a,b) a > b ? a : b

int progD(int qtd, int *v, int *p, int cap){
    int usa, naoUsa;
    if(m[qtd][cap]==-1){
        if(p[qtd]>cap){
            m[qtd][cap] = progD(qtd-1, v, p, cap ,m);
        }
        else{
            usa = v[qtd] + progD(qtd-1, v, p, cap-p[qtd] ,m);
            naoUsa = progD(qtd-1, v, p,cap, m);
            m[qtd][cap] = max(usa, naoUsa);
        }

    }
    return m[qtd][cap];


}


int main()
{
    int capacidade, qtdObj, i, j;
    scanf("%d %d", &capacidade, &qtdObj);
    int peso[qtdObj], valor[qtdObj], m[qtdObj][capacidade];
    for(i = 0; i<qtdObj; i++){
        scanf("%d %d", &peso[i], &valor[i]);
    }


    printf("%d", progD(qtdObj, valor, peso, capacidade));

}
