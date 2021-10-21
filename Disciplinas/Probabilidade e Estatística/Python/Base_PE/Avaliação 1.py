import Base_PE
import Base_PE as Base
import pandas as pd
url = 'https://raw.githubusercontent.com/LuizKramer/UTFPR/main/Disciplinas/Probabilidade%20e%20Estat%C3%ADstica/Python/Base_PE/Dados%20PE%20-%20P%C3%A1gina1.csv'
data = pd.read_csv(url, index_col=0)
print(data)

df = pd.DataFrame(data[['Dispositivo', 'Horas']])
dfM = df.groupby('Dispositivo', as_index=False).mean()

print('Mediana: ' + str(Base.mediana(data['Horas'])) + '\n' + str(df.groupby('Dispositivo', as_index=False).median()))
print('\nMedia: ' + str(Base.mediaS(data['Horas'])) + '\n' + str(df.groupby('Dispositivo', as_index=False).mean()))
print('\nModa: ' + str(Base.moda(data['Horas'])))
print('Variancia: ' + '{:.2f}'.format(round(pow(Base.desvioPadrao(data['Horas']), 2), 2)))
print('Desvio Padrão: ' + '{:.2f}'.format(round(Base.desvioPadrao(data['Horas']), 2)))

horas = dfM['Horas']
label = dfM['Dispositivo']
titulo = 'Tempo despendido em cada dispositivo'

dados = list(data['Horas'])


x = Base_PE.tabelaFrequencia(dados)
x.to_csv(r"F:\UTFPR\Disciplinas\Probabilidade e Estatística\Python\Base_PE\tabelaFreq.csv", ',', index = False, header = True)
print('\n'+ str(x))

Base.pizzaChart(label, horas, titulo)
Base.histograma(data['Horas'], 10, 'Tempo de Exposição')


