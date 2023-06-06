import numpy as np
from numpy import linalg as al


def men_princ(A,tamanho):
    det = True
    for n in range(1,tamanho+1):
        mat = np.zeros((n,n))
        for i in range(n):
            for j in range(n):
                mat[i][j] = A[i][j]
        if al.det(mat) == 0:
            det = False
    return det
        
def produto(linhaA, colunaB, n, matrizA, matrizB):
    matriz = np.zeros((linhaA, colunaB))
    for i in range(0, linhaA):
        for j in range(0, colunaB):
            for z in range(0, n):
                matriz[i][j] += matrizA[i][z] * matrizB[z][j]
    return matriz

A = np.array([[2, 0, 1],
              [0, 2, 1],
              [1, 1, 3]])
n = len(A)

if men_princ(A, n):
    print('Admite uma decomposição LU \n')
    L = np.ones((n,n))
    U = np.zeros((n,n))

    for i in range(n):
        for j in range(n):
            if j > i:
                L[i][j] = 0
            else:
                L[i][j] *= -1
        L[i][i] = 1
    
    for i in range(n):
        for j in range(n):
            if j < i:
                U[i][j] = 0
            else:
                U[i][j] *= -1
        U[0][i] = A[0][i]
    C = produto(n, n, n, L, U)
    print('\n', C)

    #print(L, '\n\n', U)

else:
    print('Determinante de A é igual a 0')