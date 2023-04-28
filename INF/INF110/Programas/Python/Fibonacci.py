print('Iniciando o cálculo da Sequência de Fibonacci…')
print('Sequência calculada com sucesso.')
print('')
n = int(input('Entre com o termo que deseja saber o valor: '))
while n >= 0 and n <= 50:
    ultimo = 1
    penultimo = 1
    if n == 0 or n == 1:
        print('O Fibinacci de %d é %d' % (n, n))
    else:
        cont = 3
        while cont <= n:
            termo = ultimo+penultimo
            penultimo = ultimo
            ultimo = termo
            cont += 1
        print('O Fibonacci de %d ' % n, end='')
        print('é %d' % ultimo)
    n = int(input('Entre com o termo que deseja saber o valor: '))
