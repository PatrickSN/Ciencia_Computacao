from random import choice
import os


def criaPlanilha(caminho, texto, pulaLinha=False):
    with open(caminho, 'a') as dinheiro:
        dinheiro.writelines(f'{texto}, ')
        if pulaLinha:
            dinheiro.writelines('\n')


# configuraçoes iniciais
repete = int(input("Número de repetições da simulação: "))
dinheiroA = 10
dinheiroB = 20

dinA = dinheiroA
dinB = dinheiroB

moeda = ['cara', 'coroa']
cont = 1

# contabiliza quantas vezes cada moeda foi lançada antes de alguem ganhar
Aganha = 0
Bganha = 0

# simula o um numero de jogos pre-definidos nas configuraçoes iniciais
while cont <= repete:
    rodadas = 0
    
    dinA = dinheiroA
    dinB = dinheiroB
    # simula infinitos lançamentos até que A ou B ganhe o jogo
    while True:
        rodadas += 1
        criaPlanilha(f'Dinheiro A simulação {repete} (A={dinheiroA}, B={dinheiroB}).csv', dinA)
        criaPlanilha(f'Dinheiro B simulação {repete} (A={dinheiroA}, B={dinheiroB}).csv', dinB)
        lancaMoeda = choice(moeda)
        if 'cara' == lancaMoeda:  # cara pra A ganhar
            dinA += 1
            dinB -= 1

        else:  # coroa pra B ganhar
            dinB += 1
            dinA -= 1

        # adiciona a uma lista o numero de vezes que a moeda foi lançada
        if dinA <= 0:
            criaPlanilha(f'Dinheiro A simulação {repete} (A={dinheiroA}, B={dinheiroB}).csv', dinA, True)
            criaPlanilha(f'Dinheiro B simulação {repete} (A={dinheiroA}, B={dinheiroB}).csv', dinB, True)
            criaPlanilha(f'Nº de rodadas simulação {repete} (A={dinheiroA}, B={dinheiroB}).csv',
                         f'Simulação {cont} A começa com: {dinheiroA} e B: {dinheiroB}), , {rodadas}', True)
            Bganha += 1
            break

        elif dinB <= 0:
            criaPlanilha(f'Dinheiro A simulação {repete} (A={dinheiroA}, B={dinheiroB}).csv', dinA, True)
            criaPlanilha(f'Dinheiro B simulação {repete} (A={dinheiroA}, B={dinheiroB}).csv', dinB, True)
            criaPlanilha(f'Nº de rodadas simulação {repete} (A={dinheiroA}, B={dinheiroB}).csv',
                         f'Simulação {cont} A começa com: {dinheiroA} e B: {dinheiroB}), {rodadas}, ', True)
            Aganha += 1
            break

        
    cont += 1


criaPlanilha('Simulações.txt',
             f"A vence {Aganha} vezes, B vence {Bganha} vezes (Simulação de {repete} repetições, A começa com: {dinheiroA} e B: {dinheiroB})", True)
