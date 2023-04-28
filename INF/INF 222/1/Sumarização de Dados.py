'''
Nome: Lucas Patrick Saturnino Nicácio
Matricula: 99763
'''
import pandas as pd


def menor(listaNum):
    '''retorna o menor numero de uma lista'''
    menor = listaNum[0]
    for i in range(1, len(listaNum)):
        if listaNum[i] <= menor:
            menor = listaNum[i]
    return menor


def ordena(listaNum):
    '''ordena uma lista em ordem crescente'''
    novaLista = listaNum
    listaTemp = []
    while novaLista != []:
        listaTemp.append(menor(novaLista))
        novaLista.remove(menor(novaLista))
    return listaTemp


def somatorio(listaNum):
    '''retorna a soma dos numeros de uma lista'''
    soma = 0
    for i in range(len(listaNum)):
        soma += listaNum[i]
    return soma


def media(listaNum):
    '''retorna o valor medio dos numeros de uma lista '''
    return somatorio(listaNum)/(int(len(listaNum)))


def mediana(listaNum):
    '''retorna a mediana de uma lista numerica'''
    if len(listaNum) % 2 == 0:
        return (listaNum[int(len(listaNum)/2)-1] + listaNum[int((len(listaNum)/2))])/2
    else:
        return listaNum[len(listaNum)//2]


def moda(listaNum, indice=0, rep=0):
    '''imprime os numeros q apareceram mais vezes em ordem crescente de apariçao'''
    j = indice + 1
    repete = 1
    while listaNum[indice] == listaNum[j]:
        repete += 1
        j += 1
    if repete >= rep:
        rep = repete
        print(f'\nO número: {listaNum[indice]}; Repete: {repete} vezes.')
    if j != len(listaNum) - 1:
        moda(listaNum, j, rep)


def pontoMedio(listaNum):
    'retorna o ponto medio, que é a media entre o maior e o menor valor de uma lista'
    return (listaNum[0] + listaNum[int(len(listaNum))-1])/2


def amplitude(listaNum):
    '''retorna a diferenca entre o maior e o menor valor de uma lista'''
    return listaNum[int(len(listaNum))-1] - listaNum[0]


def variancia(listaNum, media):
    '''retorna a media quadratica entre os desvios'''
    desvio = []
    for i in range(0, len(listaNum)):
        variacao = (listaNum[i] - media) ** 2
        desvio.append(variacao)
    return somatorio(desvio)/(len(listaNum)-1)


def desvioPadrao(variancia):
    return variancia ** 0.5


def frequencia(listaNum, min, max):
    '''retorna a frequencia acumulada dos numeros'''
    for i in range(min, len(listaNum)):
        if listaNum[i] > max:
            break
    return (i)

caminho = input('Digite o caminho da planilha com os dados: ')
dados = pd.read_excel(caminho)
entradas = dados.loc[:,'Numeros'].values.astype(int)
print(entradas)
entradas = ordena(entradas)
media = media(entradas)
desviopadrao = desvioPadrao(variancia(entradas, media))
coeficienteVar = desviopadrao/media

print('n = ',len(entradas))
print(f'\nOrdenado: {entradas} \n\nMedia: {media} \n\nMediana: {mediana(entradas)} \n\nPonto Médio: {pontoMedio(entradas)}'
      f'\n\nAmplitude: {amplitude(entradas)} \n\nDesvio Padrão: {desviopadrao} \n\nVariância: {variancia(entradas, media)} \n\nCoef. de Variação: {coeficienteVar*100} %'
      )
moda(entradas)

print(20*'-')
menor30 = frequencia(entradas, 0, 30)
menor40 = frequencia(entradas, menor30, 40)
menor50 = frequencia(entradas, menor40, 50)
menor60 = frequencia(entradas, menor50, 60)
menor70 = frequencia(entradas, menor60, 70)
maior70 = frequencia(entradas, menor70, 1000)
