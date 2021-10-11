# Algoritmos gulosos - a sociedade do anel [07/11/2021]

## Problema Proposto:

Bilbo teve uma uma missão de levar um anel mágico para ser destruído em um vulcão. Nessa jornada, Bilbo deve percorrer um campo cheio de obstáculos. Esse campo pode ser representado por uma matriz de números inteiros (M), onde cada elemento representa um custo para ser acessado a partir dos elementos na vizinhança. Por exemplo, se M[3][3] = 5, então o custo para o deslocamento de M[2][3], M[3][4], M[4][3], ou M[3][2] para M[3][3] é 5. O Bilbo mora na posição M[0][0], que tem custo zero, pois é de sua casa que ele iniciará a aventura. O vulcão fica em um lugar distante da casa de Bilbo e pelo que se sabe, está localizado na posição M[l - 1][c - 1], onde l é o número de linhas e c é o número de colunas da matriz. Bilbo é um cara preguiçoso e a partir do lugar que ele se enconcontra, vai para o lugar menos custoso, mas ele é persistente e não reconsidera a sua decisão. Implemente uma função gulosa que calcule o custo do caminho do Bilbo até o vulcão.

**Input Format**

A primeira linha contém a quantidade de linhas (l) e de colunas (c) da matriz. A partir da próxima linha, deve ser lida uma matriz l x c de números inteiros.

**Constraints**

Na matriz não deve ser permitido delocamento pela diagonal. Por exemplo, se Bilbo estiver na posição M[3][3], ele não pode ir para M[2][2], M[2][4], M[4][4] ou M[4][2] a partir de M[3][3]. Em outras palavras, apenas é possível deslocar para cima, baixo, esquerda ou direita.

**Output Format**

O custo total do deslocamento de M[0][0] até M[l - 1][c - 1] utilizando solução gulosa. Caso M[l - 1][c - 1] não seja alcançado, imprimir "sem solucao".

**Sample Input 0**

```
6 6
0 1 2 3 4 5
2 1 3 2 1 4
1 3 4 5 2 1
1 2 2 6 7 5
3 4 1 3 5 6
1 4 2 1 2 3
```

**Sample Output 0**

```
19
```

**Explanation 0**

**0 1** 2 3 4 5

**2 1** 3 2 1 4

**1** 3 4 5 2 1

**1 2 2** 6 7 5

3 4 **1** 3 5 6

1 4 **2 1 2 3**

1 + 1 + 2 + 1 + 1 + 2 + 2 + 1 + 2 + 1 + 2 + 3 = **19**

## Solução

Inicialmente foi montado um algoritmo para mapear as posições em volta da posição atual, não sendo possível Bilbo se mover na diagonal é somente necessário verificar as 4 posições em sua volta, assim, via [teste de mesa](https://github.com/LuizKramer/UTFPR/blob/main/Disciplinas/Algoritmos%20e%20Estrutura%20de%20Dados%202/HackerRank/Algoritmos%20gulosos%20-%20a%20sociedade%20do%20anel%20%5B07112021%5D/Teste_de_mesa.txt) foi determinado o valor dos índices que deveriam ser colocados na matriz para que esta retornasse o valor contido nestas posições.  Também foi implementada uma restrição em os dados não poderiam ser manipulados caso fossem resultar em um escopo fora da matriz, ou seja, quando o valor tanto das linhas(l) quanto das colunas(c) está fora do domínio (x>0 e x<N), com N sendo a ordem da matriz e x sendo o valor permitido para l e c.

Sendo l - linhas, c = colunas e v = valor contido na posição da matriz:

Caso primeira posição:    
  l  c   v
M\[0][0] = 0; // FIXO
M\[0][1] = 1; l   c+1    
M\[1][0] = 2; l+1 c

Caso posição entre 3 valores;
      l  c       v  l  c
M\[1][2] = 3; - --- Posição atual
M\[0][2] = 2; -1 +0  
M\[1][1] = 1; +0 -1 -- Escolha
M\[1][3] = 1; +0 +1 
M\[2][2] = 4; +1 +0

Em seguida foi adicionado um vetor que recebia as posições em que Bilbo já passou, mas para isso foi necessário mapear a matriz a partir dos índices de suas linhas e colunas, que aqui vamos atribuir o nome de i e j respectivamente. Assim utilizando a formula: ((i+1) * l +1)+(( j-c )) é gerado um valor distinto para cada posição dentro da matriz. Por fim só resta comparar os valores no vetor com a posição atual em cada verificação.



