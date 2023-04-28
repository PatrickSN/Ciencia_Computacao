import random
import os 

def mata(precisao, miraatirador):
    #verifica se a precisao sorteada eh maior ou menor que a precisao do atirador 
    if miraatirador >= precisao:
        return True
    else:
        return False

def criaPlanilha(caminho, turno):
    with open(caminho, 'a') as vivo:
            vivo.writelines(f'{turno}, \n')

repete = int(input("Número de repetições da simulação: "))
cont = 0

atiradorA = 5/6
atiradorB = 5/6

vivoA = 0
vivoB = 0


while cont < repete:
    cont += 1
    turno = 1
    while True:
        
        if turno % 2 != 0:  # verifica se eh a vez do A
            precisao = random.random()
            if mata(precisao, atiradorA):
                criaPlanilha(f'A vive na simulação de {repete}.csv', turno)
                vivoA += 1
                break
        else:  # verifica se a vez do B
            precisao = random.random()
            if mata(precisao, atiradorB):
                criaPlanilha(f'B vive na simulação de {repete}.csv', turno)
                vivoB += 1
                break
        turno += 1

print(f"A sobrevive {vivoA} vezes, B sobrevive {vivoB} vezes")
