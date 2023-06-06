"""import numpy as np


n = int(input('Valor n da matriz (n x n): '))
mat = np.zeros((n,1),dtype=int)

def prod_matriz(A, B):
    for i in range(n):
            for z in range(n):
                mat[i][0] += A[i][z]*B[z][0]
    

A = [[10,2,1],
     [1,5,1],
     [2,3,10]]

X = np.ones((n,1),dtype=float)

B = [[14],[11],[8]]
print(X,'\n\n', A, '\n\n', B)

prod_matriz(A, B)
print(30*"-")
print(mat)"""
import sympy as sp
import numpy as np

x = sp.symbols('x')
b = [x , x, x]
c = [expr.subs(x, 5).evalf() for expr in b]
a = np.array(c)

print(a)