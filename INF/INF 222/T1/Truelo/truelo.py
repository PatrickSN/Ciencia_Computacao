import random
import os


def mata(precisao, miraatirador):

    if miraatirador >= precisao:
        return True
    else:
        return False


def verificaMaior(lista, excecao):
    maior = 0
    indice = 0
    for i in range(len(lista)):
        if i != excecao:
            if lista[i] >= maior:
                maior = lista[i]
                indice = i
    return indice


def criaPlanilha(caminho, texto):
    with open(caminho, 'a') as vivo:
        vivo.writelines(f'{texto}, \n')


def duelo(atiradores, precisoes, turno):
    if turno == 1:
        turno = 2

    elif turno == 2:
        turno = 2

    elif turno == 3:
        turno = 1


    while True:
        if turno % 2 != 0:  # verifica se eh a vez do A
            precisao = random.random()
            if mata(precisao, precisoes[0]):
                del atiradores[1], precisoes[1]
                break
        else:  # verifica se a vez do B
            precisao = random.random()
            if mata(precisao, precisoes[1]):
                del atiradores[0], precisoes[0]
                break
        turno += 1

#configurações do truelo
repete = int(input("Número de repetições da simulação: "))
cAtira = 'S' #configura se C atira durante o truelo
cont = 0

atiradores = ['A', 'B', 'C']

atiradorA = 4/6
atiradorB = 5/6
atiradorC = 4/6

precisoes = [atiradorA, atiradorB, atiradorC]
tiros = [0, 0, 0]

vivoA = 0
vivoB = 0
vivoC = 0
# simula o um numero de simulaçoes pre-definidos nas configuraçoes iniciais
while cont < repete:
    cont += 1
    turno = 1
    i = 0
    while True:
        if turno == 1:
            precisao = random.random()
            tiros[0] += 1
            if mata(precisao, atiradorA):
                melhor = verificaMaior(precisoes, i)
                #print(f'A mata {atiradores[melhor]}')
                del atiradores[melhor], precisoes[melhor]
                break

        elif turno == 2:
            precisao = random.random()
            tiros[1] += 1
            if mata(precisao, atiradorB):
                melhor = verificaMaior(precisoes, i)
                #print(f'B mata {atiradores[melhor]}')
                del atiradores[melhor], precisoes[melhor]
                break

        elif turno == 3:
            if cAtira == 'S':
                precisao = random.random()
                tiros[2] += 1
                if mata(precisao, atiradorC):
                    melhor = verificaMaior(precisoes, i)
                    #print(f'C mata {atiradores[melhor]}')
                    del atiradores[melhor], precisoes[melhor]
                    break
            else:
                pass

        else:
            turno = 0

        if i < 3:
            i += 1
        else:
            i = 0

        turno += 1

    duelo(atiradores, precisoes, turno)

    #print('Sobrevive »» ', atiradores)

    if atiradores[0] == 'A':
        criaPlanilha(f'A vive na simulação de {repete} (Truelo) {cAtira}.csv', tiros[0])
        vivoA += 1
    elif atiradores[0] == 'B':
        criaPlanilha(f'B vive na simulação de {repete} (Truelo) {cAtira}.csv', tiros[1])
        vivoB += 1
    else:
        criaPlanilha(f'C vive na simulação de {repete} (Truelo) {cAtira}.csv', tiros[2])
        vivoC += 1

    atiradores = ['A', 'B', 'C']
    precisoes = [atiradorA, atiradorB, atiradorC]
    tiros = [0, 0, 0]


criaPlanilha('Simulações.txt', f"A sobrevive {vivoA} vezes, B sobrevive {vivoB} vezes, C sobrevive {vivoC} vezes (Simulação de {repete} repetições » C atira: {cAtira})")
