import Base_PE
import Base_PE as Base
import pandas as pd

data = pd.read_csv('Dados PE - Página1.csv')

df = pd.DataFrame(data[['Dispositivo', 'Horas']])
dfM = df.groupby('Dispositivo', as_index=False).mean()

print('Mediana: ' + str(Base.mediana(data['Horas'])) + '\n' + str(df.groupby('Dispositivo', as_index=False).median()))
print('\nMedia: ' + str(Base.mediaS(data['Horas'])) + '\n' + str(df.groupby('Dispositivo', as_index=False).mean()))
print('\nModa: ' + str(Base.moda(data['Horas'])))
print('Variancia: ' + '{:.2f}'.format(round(pow(Base.desvioPadrao(data['Horas']), 2), 2)))
print('Desvio Padrão: ' + '{:.2f}'.format(round(Base.desvioPadrao(data['Horas']), 2)))

horas = dfM['Horas']
label = dfM['Dispositivo']
titulo = 'Tempo desprendido em cada dispositivo'

dados = list(data['Horas'])


x = Base_PE.tabelaFrequencia(dados)
x.to_csv(r"F:\UTFPR\Disciplinas\Probabilidade e Estatística\Python\Base_PE\tabelaFreq.csv", ',', index = False, header = True)
print('\n'+ str(x))

Base.pizzaChart(label, horas, titulo)
Base.histograma(data['Horas'], 10)


