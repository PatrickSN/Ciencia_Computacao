import sympy as sp
from numpy import linspace
import verificacoes as V


'''
    METODO DAS APROXIMAÇOES SUCESSIVAS
Seja a equaçao f(x) = 0, com soluçao unica x̅ num intervalo I onde f é continua.
Obtemos a equaçao x = φ(x) equivalente a equacao f(x) = 0, com φ continua em I.
O termo x0 é um ponto qualquer do intervalo I.
Os demais termos sao daodos por: xn+1 = φ(xn)

* Se a funçao φ for derivavel em I tal que |φ`(x)| < 1, para todo o x Ɛ I, entao 
podemos garantir que a sequencia converge para a soluçao.
'''


def funcao(x):
    return (sp.exp(-x))**0.5


def buscar_raiz():
    a, b, epslon, erro = V.entradas()
    x = sp.Symbol('x')

    if V.continua(funcao(x), a, b):
        f1 = sp.diff(funcao(x), x)
        for xn in linspace(a, b, 100):
            if f1.evalf(subs={x: xn}) >= 1:
                # *
                print('\nf`(x) >= 1 para x =', xn)
                break
        else:
            print('\nf`(x) < 1 para todo x em [{}, {}]'.format(a, b))

    x0 = float(input('\nDigite o valor x0 contido no intervalo [a,b]: '))
    cont = 1
    while True:
        x1 = funcao(x0)
        if V.Epslon(x0, x1, erro) > epslon:
            x0 = x1

        else:
            break
        cont += 1

    print('\nx̅ ~ x{} ~ {:.5} com erro {} menor que Ԑ = {}'.format(
        cont, x1, erro, epslon))


buscar_raiz()
