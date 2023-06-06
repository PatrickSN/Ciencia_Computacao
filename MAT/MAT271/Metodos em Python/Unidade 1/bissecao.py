import sympy as sp
import verificacoes as V


def funcao(x):
    f = x*sp.exp(x)-9
    return f


def sinal(a, b):
    if funcao(a)*funcao(b) < 0:
        return True
    else:
        return False


def buscar_raiz():
    a, b, epslon, erro = V.entradas()
    e = 1
    n = 0

    x = sp.Symbol('x')
    if V.continua(funcao(x), a, b):
        while e > epslon:
            n += 1
            x = (a + b)/2
            if sinal(a, x):
                e = V.Epslon(x, b, erro)
                b = x

            else:
                e = V.Epslon(x, a, erro)
                a = x

            print("f{}( {:.7} ) = {:.5}, Erro {} = {:.5}".format(
                n, x, funcao(x), erro, e))

        print("Valor aproximado x = {:.7}".format(x))

    else:
        print("A função não é continua no intervalo dado!!!")


buscar_raiz()
