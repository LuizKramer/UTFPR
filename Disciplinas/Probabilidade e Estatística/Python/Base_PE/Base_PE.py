import numpy as np


def mediaAritimetica(v):
    return np.mean(v)


def mediaPonderada(v, pesos):
    eqXPesos = []
    for i in range(0, len(v)):
        eqXPesos.append(v[i] * pesos[i])
    mediaP = sum(eqXPesos) / sum(pesos)
    return mediaP


def desvioPadrao(v):
    media = mediaAritimetica(v)
    eqDP = []
    for i in range(0, len(v)):
        eqDP.append(pow((v[i] - media), 2))
    n = len(v) - 1
    return np.sqrt(sum(eqDP)/ n)


if __name__ == '__main__':
    dados = [7, 8, 6, 10, 5, 9, 4, 12, 7, 8]
    print(mediaAritimetica(dados))
    print(desvioPadrao(dados))
