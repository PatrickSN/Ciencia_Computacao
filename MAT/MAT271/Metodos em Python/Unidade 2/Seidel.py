import numpy as np
from numpy import linalg as al


def men_princ(A, tamanho):
    det = True
    for n in range(1, tamanho+1):
        mat = np.zeros((n, n))
        for i in range(n):
            for j in range(n):
                mat[i][j] = A[i][j]
        if al.det(mat) == 0:
            det = False
    return det


def somatorio(A, B, Ls, i, j):
    soma = 0
    while j < Ls:
        soma += A[i][j]*B[j]
        j += 1

    return soma


def epslon(x0, x1, erro):
    n = len(x0)
    d = np.zeros(n)
    for i in range(n):
        d[i] = x1[i]-x0[i]

    if max(abs(x1)) == 0:
        erro = "absoluto"

    if erro == "absoluto":
        return max(abs(d))

    else:
        return max(abs(d))/max(abs(x1))


# Forneça as matrizes A, X, B, epslon abaixo
# Matriz A dos coeficientes
A = [
    [10, 2,  1],
    [1,  5,  1],
    [2, 3,  10]
]

# Matriz X das incognitas
X0 = [0, 0, 0]

# Matriz B dos resultados
B = [14, 11, 8]

# Epslon
E = 0.001
tipo = "absoluto"

n = len(X0)

x1 = np.zeros(n)
cont = 0
while True and men_princ(A, n):

    print(f'X{cont} - (', end="")
    for i in range(n):
        print('%5.5f' % (X0[i]), end=', ')
    print(')', end='\n')
    v = np.zeros(n)
    for i in range(n):
        v[i] = X0[i]
    for i in range(n):
        x1[i] = (B[i]-somatorio(A, X0, i, i, 0) -
                 somatorio(A, X0, n, i, i+1))/A[i][i]
        X0[i] = x1[i]

    if epslon(X0, v, tipo) > E:
        pass

    else:
        break
    cont += 1

if not men_princ(A, n):
    print('Não foi possível garantir a convergência do sistema')