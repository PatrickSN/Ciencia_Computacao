import os

def escreve_na_lista(estado,nome=""):
        with open(f'teste_{nome}.txt', 'a') as teste:
            teste.writelines(f'{estado}\n')

escreve_na_lista('     a5 a4 a3 a2 a1 a0 | b5 b4 b3 b2 b1 b0')
cont = 0
ab5 = 0
aabb = 0

for a in range(2):
    for b in range(2):
        for c in range(2):
            for d in range(2):
                for e in range(2):
                    for f in range(2):
                        for g in range(2):
                            escreve_na_lista(f'{cont}/{ab5}: {a}  x  x  x  x  x |  {g}  x  x  x  x  x', 'A5-B5')
                            ab5 += 1
                            for h in range(2):
                                escreve_na_lista(f'{cont}/{aabb}: {a}  {b}  x  x  x  x |  {g}  {h}  x  x  x  x', 'A5A4-B5B4')
                                aabb += 1
                                for i in range(2):
                                    for j in range(2):
                                        for k in range(2):
                                            for l in range(2):
                                                escreve_na_lista(f'{cont}: {a}  {b}  {c}  {d}  {e}  {f} |  {g}  {h}  {i}  {j}  {k}  {l}')
                                                cont += 1