import numpy as np
import statistics as sts
import pandas as pd
from matplotlib import pyplot as plt
import seaborn as sns


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


def pizzaChart(rotulos, valores):
    plt.pie(x=valores, labels=rotulos, autopct='%1.1f%%', startangle=90)
    plt.show()



if __name__ == '__main__':
    rotulos = ['Moradia', 'Mobilidade', 'Alimentos', 'Estudos']
    dados = [30, 30, 30, 10]
    print(mediaS(dados))
    print(desvioPadrao(dados))
    pizzaChart(rotulos, dados)
