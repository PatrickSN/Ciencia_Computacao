


alfabeto = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
            'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'y', 'z']

numeros = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']

simbolos = ['!', '@', '#', '$', '%', '&', '*', '_', '+', '-', ' ']


def posicao(x):
    caracter = str.lower(x)
    posicao = 0
    complemento = "A"
    if caracter in alfabeto:
        for i in range(0, len(alfabeto)):
            if caracter == alfabeto[i]:
                posicao = i
                break
    elif caracter in numeros:
        for i in range(0, len(numeros)):
            if caracter == numeros[i]:
                posicao = i
                complemento = "N"
                break
    elif caracter in simbolos:
        for i in range(0, len(simbolos)):
            if caracter == simbolos[i]:
                posicao = i
                complemento = "S"
                break
    else:
        print("!!!Caractere não pode ser criptografado!!!")
    return posicao, complemento


def cripto_compl(chave, lista_cripto):
    if chave == "A":
        for i in range(0, len(alfabeto)):
            if len(lista_cripto) > 24:
                break
            if alfabeto[i] not in lista_cripto:
                lista_cripto += alfabeto[i]

    elif chave == "N":
        for i in range(0, len(numeros)):
            if len(lista_cripto) > 24:
                break
            if numeros[i] not in lista_cripto:
                lista_cripto += numeros[i]
        for i in range(0, len(simbolos)):
            if len(lista_cripto) > 24:
                break
            if simbolos[i] not in lista_cripto:
                lista_cripto += simbolos[i]
        for i in range(0, len(alfabeto)):
            if len(lista_cripto) > 24:
                break
            if alfabeto[i] not in lista_cripto:
                lista_cripto += alfabeto[i]

    elif chave == 'S':
        for i in range(0, len(simbolos)):
            if len(lista_cripto) > 24:
                break
            if simbolos[i] not in lista_cripto:
                lista_cripto += simbolos[i]
        for i in range(0, len(numeros)):
            if len(lista_cripto) > 24:
                break
            if numeros[i] not in lista_cripto:
                lista_cripto += numeros[i]
        for i in range(0, len(alfabeto)):
            if len(lista_cripto) > 24:
                break
            if alfabeto[i] not in lista_cripto:
                lista_cripto += alfabeto[i]

    return lista_cripto


chave = input("Digite a chave de criptografia: ")
chave_complementar = str.upper(input("Insira o complemento da chave(A,N,S): "))

ordem = posicao(chave)

sequencia_cripto = []

if ordem[1] == "A":
    print('Criptografando o alfabeto')
    for i in range(ordem[0], len(alfabeto)):
        sequencia_cripto += alfabeto[i]
    sequencia_cripto = cripto_compl(chave_complementar, sequencia_cripto)

elif ordem[1] == "N":
    print('Criptografando os numeros')
    for i in range(ordem[0], len(numeros)):
        sequencia_cripto += numeros[i]
    sequencia_cripto = cripto_compl(chave_complementar, sequencia_cripto)

elif ordem[1] == "S":
    print('Criptografando os simbolos')
    for i in range(ordem[0], len(simbolos)):
        sequencia_cripto += simbolos[i]
    sequencia_cripto = cripto_compl(chave_complementar, sequencia_cripto)

print(sequencia_cripto)

senha = str.lower(input("Digite sua senha: "))
senha_cripto = ""
lim = 0
for letra in senha:
    posi_letra = posicao(letra)
    if posi_letra[0] % 2 == 0 and lim != 1:
        senha_cripto += str.upper(sequencia_cripto[posi_letra[0]])
        lim = 1
    else:
        senha_cripto += sequencia_cripto[posi_letra[0]]
        lim = 0

print(senha_cripto)
