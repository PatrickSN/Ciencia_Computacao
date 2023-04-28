

def fatorial(numero):
    if numero != 0 and numero != 1:
        return numero*fatorial(numero-1)

    else:
        return 1


def arranjo(n, k):
    return fatorial(n)/(fatorial((n-k)))


def combinacao(n, k):
    return fatorial(n)/(fatorial((n-k))*fatorial(k))

