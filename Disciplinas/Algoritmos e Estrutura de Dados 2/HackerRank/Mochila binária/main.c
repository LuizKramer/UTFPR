#include <stdio.h>
#include <stdlib.h>
# define max(a,b) a > b ? a : b

int progD(int qtd, int *v, int *p, int cap)
{
    int i, j, a, b;

    int m[qtd + 1][cap + 1];

    for (i = 0; i <= qtd; i++)
    {
        for (j = 0; j <= cap; j++)
        {
            if (i == 0 || j == 0)
                m[i][j] = 0;
            else if (p[i - 1] <= j){
                a = v[i - 1] + m[i - 1][j - p[i - 1]];
                b = m[i - 1][j];
                m[i][j] = max(a, b);
            }
            else
                m[i][j] = m[i - 1][j];
        }
    }

    return m[qtd][cap];
}

int main()
{
    int capacidade, qtdObj, i, j;
    scanf("%d %d", &capacidade, &qtdObj);

    int peso[qtdObj], valor[qtdObj];

    for(i = 0; i<qtdObj; i++){
        scanf("%d %d", &peso[i], &valor[i]);
    }


    printf("%d", progD(qtdObj, valor, peso, capacidade));

}
