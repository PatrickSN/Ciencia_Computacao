import sympy as sp
import verificacoes as V


"""
O método de Newton funciona da seguinte maneira:

1. Escolha uma estimativa inicial para a raiz da função.

2. Calcule a derivada da função no ponto correspondente à estimativa inicial.

3. Use a equação da reta tangente ao gráfico da função na estimativa inicial para encontrar uma nova estimativa da raiz.

4. Repita os passos 2 e 3 até que a diferença entre as estimativas sucessivas seja menor que uma tolerância pré-definida.

5. A última estimativa encontrada é a aproximação da raiz da função.

Em resumo, o método de Newton utiliza a ideia de aproximar a função por uma reta tangente em cada iteração, o que permite 
uma convergência rápida para a raiz desejada. A utilização da derivada da função é fundamental para esse processo. No entanto, 
o método pode falhar se a função não tiver derivada em algum ponto ou se a estimativa inicial estiver muito longe da raiz.
"""


def funcao(x):
    f = sp.cos(x) + sp.exp(5*x)
    return f


def buscar_raiz():
    a, b, epslon, erro = V.entradas()
    x = sp.Symbol('x')
    if V.continua(funcao(x), a, b):
        f1 = sp.diff(funcao(x), x)

        x0 = float(
            input(f'\nDigite o valor x0 Ɛ [{a}, {b}]: '))

        while True:
            if x0 > b or x0 < a:
                x0 = float(
                    input(f'\nDigite o valor x0 contido no intervalo [{a}, {b}]: '))

            elif f1.evalf(subs={x: x0}) == 0:
                print(
                    'A derivada do ponto dado é igual a 0, por favor ' +
                    'forneça valor para o x0')
                x0 = float(input(f'\n X0 = '))

            else:
                break

        cont = 0
        print(f1)
        while True:
            cont += 1
            x1 = x0 - (funcao(x0)/f1.evalf(subs={x: x0}))
            print(f'x{cont} = {x1}')
            if V.Epslon(x0, x1, erro) < epslon:
                break
            else:
                x0 = x1
        print('x̅ ~ ', x1)

    else:
        print('Não é continua no intervalo dado!!!')


buscar_raiz()
