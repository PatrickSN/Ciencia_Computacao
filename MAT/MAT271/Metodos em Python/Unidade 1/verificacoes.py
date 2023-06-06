import sympy


def Epslon(x1, x2, erro):
    if x2 == 0:
        erro = "absoluto"

    if erro == "absoluto":
        return abs(x2-x1)

    else:
        return abs((x2-x1)/x2)


def continua(f, a, b):
    '''
    Esta função verifica se f eh continua em um intervalo de [a,b]
    '''
    x = sympy.Symbol('x')

    # Verifica se f(x) é contínua no intervalo [a, b]
    if sympy.limit(f, x, a) == f.subs(x, a) and sympy.limit(f, x, b) == f.subs(x, b):
        return True
    else:
        return False


def entradas():
    '''
    Retorna o intervalo (a, b), o Ԑ e o tipo de erro
    '''
    while True:
        intervalo = input("Digite o intervalo (a, b): ")
        try:
            a, b = map(float, intervalo.split(','))
            break
        except ValueError:
            print("Intervalo inválido, tente novamente.")

    while True:
        epslon, erro = input(
            "Digite o Ԑ e o tipo de erro (absoluto ou relativo): ").split(" ")
        try:
            epslon = float(epslon)
            if erro not in ['absoluto', 'relativo']:
                raise ValueError
            break
        except ValueError:
            print("Entrada inválida, tente novamente.")

    return a, b, epslon, erro
