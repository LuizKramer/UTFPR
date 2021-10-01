## Algoritmos gulosos - Seleção de atividade [07/11/2021]

## Problema Proposto:

Dona Lurdes é responsável pelo gerenciamento de uma sala de aula, onde ela deve alocar a maior quantidade de aulas possíveis durante o expediente. No entanto, fazer essa tarefa de forma otimizada e manualmente pode ser uma tarefa muito difícil, pois muitas disciplinas podem ter horários que sobrepõem entre elas.

Implemente uma função, por meio da estratégia gulosa, para que a maior quantidade possíveis de aula possam ser alocadas na sala.

**Input Format**

A primeira linha deve ser um número inteiro n referente à quantidade de atividades. Para cada uma das próximas n linhas devem ser lidos os horários de início e de fim para cada atividade.

**Constraints**

As aulas devem ser ordenadas crescentemente pelo horário de término.

**Output Format**

A primeira linha apresenta a mensagem “Aulas alocadas:” seguida das aulas (posição no vetor) que foram alocadas na respectiva sala.

**Sample Input 0**

```
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
```

**Sample Output 0**

```
Aulas alocadas: 0 3 7 10
```



## Solução:

Primeiramente os dados são ordenados em ordem crescente utilizando o algoritmo BubbleSort em que o a versão implementada está disponível em: [BubbleSort](https://github.com/LuizKramer/UTFPR/tree/main/Disciplinas/Algoritmos%20e%20Estrutura%20de%20Dados%201/BubbleSort).
