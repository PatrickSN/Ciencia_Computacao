import numpy as np
print('Informe o tamanho da matriz ampliada')
l = int(input('N° de linhas:'))
c = int(input('N° de colunas:'))
mat = np.empty((l, c))
for i in range(0, l):
    for j in range(0, c):
        mat[i][j] = float(input('Informe o elemento A[%d][%d]: ' % (i, j)))
for i in range(0, l+1):
    for j in range(0, c+1):
        if i == j:
            a = i
            if mat[i][j] != 1:
                for j in range(0, c+1):
                    mat[i][j] = mat[i][j]/mat[i][i]
            for i in range(0, l+1):
                for j in range(0, c+1):
                    if a != i:
                        mat[i][j] = mat[i][j]-mat[i][a]*mat[a][j]
                        print(mat[i][j], mat[i][a], mat[a][j])
