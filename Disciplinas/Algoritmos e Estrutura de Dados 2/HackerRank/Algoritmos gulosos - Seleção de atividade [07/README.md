# Algoritmos gulosos - Seleção de atividade [07/11/2021]

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



## Solução

Como os dados fornecidos estão ordenados pela hora final das aulas e representados na Figura 1, percebe-se que a primeira aula, por ter o tempo de termino menor, também se tem o primeiro horário de inicio, ou seja, ao ter os dados ordenados a primeira aula sempre entrará para a solução; em seguida é comparado o horário de inicio da aula em sequência com o horário final da última aula alocada na solução, evitando assim conflitos de horário entre as aulas e selecionando as aulas seguintes que irão compor a solução do problema.  

<p align="left">
<img src="https://github.com/LuizKramer/UTFPR/blob/2877ba7753bda7a9a01910d26aec0140760c4f79/Disciplinas/Algoritmos%20e%20Estrutura%20de%20Dados%202/HackerRank/Algoritmos%20gulosos%20-%20Sele%C3%A7%C3%A3o%20de%20atividade%20%5B07/Desenho%20do%20Problema.png" alt="" data-canonical-src="Disciplinas/Algoritmos e Estrutura de Dados 2/HackerRank/Algoritmos gulosos - Seleção de atividade [07/Desenho do Problema.png" width="450" height="300" />
   
</p>
-------------------------------Figura 1-------------------------------
