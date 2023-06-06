import numpy as np


def verificaCxL(coluna, linha):
    if coluna == linha:
        return True
    else:
        return False


def criaMatriz(linha, coluna, nome):
    matriz = np.zeros((linha, coluna))
    for i in range(0, linha):
        for j in range(0, coluna):
            matriz[i][j] = float(input(
                f"Digite o elemento {str.lower(nome)}{i+1}{j+1} da matriz {str.upper(nome)}: "))
    return matriz


def multiplica(linhaA, colunaB, n, matrizA, matrizB):
    matriz = np.zeros((linhaA, colunaB))
    for i in range(0, linhaA):
        for j in range(0, colunaB):
            for z in range(0, n):
                matriz[i][j] += matrizA[i][z] * matrizB[z][j]
    return matriz


def imprime(matriz, linha, coluna, nome):
    print(f"O resultado de {nome} é igual a: ")
    for i in range(0, linha):
        print(46*" ", end="")
        for j in range(0, coluna):
            print(matriz[i][j], end=" ")
        print()
        


print("Este é um programa que multiplica duas matrizes")
while True:
    linhaA = int(input("\nDigite o número de linhas da matriz A: "))
    colunaA = int(input("Digite o número de colunas da matriz A: "))

    linhaB = int(input("\nDigite o número de linhas da matriz B: "))
    colunaB = int(input("Digite o número de colunas da matriz B: "))

    ordem = str.lower(input("\nQual a ordem da multiplicação? (AB/BA): "))

    while ordem not in "abba":
        print('Opção Invalida')
        ordem = input("Qual a ordem da multiplicação? (AB/BA): ")

    print(ordem)
    if ordem == "ab" and verificaCxL(colunaA, linhaB):
        print("Multiplicação Permitida")
        print("Iniciando...")

        MatrizA = criaMatriz(linhaA, colunaA, "A")
        print()
        MatrizB = criaMatriz(linhaB, colunaB, "B")

        MatrizC = multiplica(linhaA, colunaB, colunaA, MatrizA, MatrizB)
        imprime(MatrizC, linhaA, colunaB, "A x B")

    elif ordem == "ba" and verificaCxL(colunaB, linhaA):
        print("Multiplicação Permitida")
        print("Iniciando...")

        MatrizB = criaMatriz(linhaB, colunaB, "B")
        print()
        MatrizA = criaMatriz(linhaA, colunaA, "A")

        MatrizC = multiplica(linhaB, colunaA, colunaB, MatrizB, MatrizA)
        imprime(MatrizC, linhaB, colunaA, "B x A")

    else:
        print(
            f"Multiplicação não Permitida, número de colunas de {str.upper(ordem[0])} diferente do número de colunas de {str.upper(ordem[1])}!")

    parada = input("Deseja testar novamente(S/N)? ")
    if parada in "Nn":
        break