import numpy as np
import statistics as sts
import pandas as pd
from matplotlib import pyplot as plt



def moda(v):
    return sts.mode(v)


def mediaS(v):
    return np.mean(v)


def mediana(v):
    return np.median(v)


def mediaPonderada(v, pesos):
    eqXPesos = []
    for i in range(0, len(v)):
        eqXPesos.append(v[i] * pesos[i])
    mediaP = sum(eqXPesos) / sum(pesos)
    return mediaP


def desvioPadrao(v):
    media = mediaS(v)
    eqDP = []
    for i in range(0, len(v)):
        eqDP.append(pow((v[i] - media), 2))
    n = len(v) - 1
    return np.sqrt(sum(eqDP) / n)


def amplitude(v):
    return max(v) - min(v)


def pizzaChart(rotulos, valores, titulo):
    plt.pie(x=valores, labels=rotulos, autopct='%1.1f%%', startangle=90)
    plt.title(titulo)
    plt.show()


def histograma(dados, bins, titulo):
    plt.hist(dados, bins, edgecolor='black')
    plt.title(titulo)
    plt.ylabel('Frequência')
    plt.xlabel('Horas')
    plt.show()


def tabelaFrequencia(dados):

    dados = sorted(dados)
    c1 = list(set(dados))
    c2 = []
    c3 = []
    c4 = []
    c5 = []
    total = 0
    for i in c1:
       if(dados.count(i)>1):
            c2.append(dados.count(i))

    for i in range(0, len(c1)):
        total = total + c2[i]

    c3.append(c2[0])
    for i in range(1, len(c1)):
        c3.append(c2[i]+c3[i-1])

    for i in range(0, len(c1)):
        c4.append((c2[i]/total)*100)


    c5.append(c4[0])
    for i in range(1, len(c1)):
        c5.append(c4[i]+c5[i-1])

    data = {
        'Horas': c1,
        'fi': c2,
        'Fi': c3,
        'fr': c4,
        'Fri': c5
    }
    x = pd.DataFrame(data)
    return x



if __name__ == '__main__':

    dados = [13,12,9,7,7,2]
    print(mediaS(dados))
    print(mediana(dados))
    print(moda(dados))
    print(desvioPadrao(dados))
    print(pow(desvioPadrao(dados),2))


