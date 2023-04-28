import sympy as sp
import verificacoes as V

x = sp.Symbol('x')
def funcao(x):
    return x**3 + sp.cos(x)

# Define o intervalo [a, b]
a = -1
b = 0

V.continua(funcao(x), a, b)