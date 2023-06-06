

def soma_simples(X, n, i, *restricoes):
    soma = 0
    i -= 1
    while i < n:
        if i+1 not in restricoes[0]:
            soma += X[i]

        i += 1

    return soma


def soma_dos_quadrados(X, n, i, *restricoes):
    soma = 0
    i -= 1
    while i < n:
        if i+1 not in restricoes[0]:
            soma += X[i]**2

        i += 1

    return soma


def quadrado_da_soma(X, n, i, *restricoes):
    return soma_simples(X, n, i, restricoes)**2


Li = int(input("Digite o valor de i do somatório: "))  # limite inferior
Ls = int(input("Digite o valor de n do somatório: "))  # limite suoerior

x = []
for j in range(Ls):
    # lista com os valores do elemento
    x.append(float(input(f"Digite o valor de X{j+1}: ")))

# quantidade de restrições
qtd_r = int(input("Digite o número de restrições: "))
r = []
for i in range(qtd_r):
    r.append(int(input(f"Digite a {i} restrição: ")))

print(soma_simples(x, Ls, Li, r))
print(soma_dos_quadrados(x, Ls, Li, r))
print(quadrado_da_soma(x, Ls, Li, r))
