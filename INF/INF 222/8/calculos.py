from scipy.stats import wilcoxon, ranksums
import pandas as pd
from random import sample, seed
import matplotlib.pyplot as plt


def paisesAleatorios(Paises, taxas, qtde, id=True):
    if id:
        seed(0)
    indices = sample(range(0, (len(Paises)-1)), qtde)
    rand_paises = []
    rand_taxas = []
    for i in indices:
        rand_paises.append(Paises[i])
        rand_taxas.append(taxas[i])
    print('\n', rand_paises)
    return rand_taxas


caminho = '8\Ex-08-dados.xlsx'
mediana = 2

dadosAS = pd.read_excel(caminho, sheet_name='America do Sul')
paisesAS = dadosAS.loc[:, 'País'].values.astype(str)
taxasAS = dadosAS.loc[:, 2018].values.astype(float)

rand_taxasAS = paisesAleatorios(paisesAS, taxasAS, 10)

dif_taxasAS = [taxa - 2 for taxa in rand_taxasAS]
probAS = wilcoxon(dif_taxasAS, alternative='greater')

dadosEU = pd.read_excel(caminho, sheet_name='Europa')
paisesEU = dadosEU.loc[:, 'País'].values.astype(str)
taxasEU = dadosEU.loc[:, 2018].values.astype(float)

rand_taxasEU = paisesAleatorios(paisesEU, taxasEU, 10)

dif_taxasEU = [taxa - 2 for taxa in rand_taxasEU]
probEU = wilcoxon(dif_taxasEU, alternative='greater')

dadosAF = pd.read_excel(caminho, sheet_name='Africa')
paisesAF = dadosAF.loc[:, 'País'].values.astype(str)
taxasAF = dadosAF.loc[:, 2018].values.astype(float)

rand_taxasAF = paisesAleatorios(paisesAF, taxasAF, 10)

dif_taxasAF = [taxa - 2 for taxa in rand_taxasAF]
probAF = wilcoxon(dif_taxasAF, alternative='greater')

print('\nValor-p(América do Sul): ', probAS[1])
print('\nValor-p(Europa): ', probEU[1])
print('\nValop-p(Africa): ', probAF[1])

print('\nValor-p AS > EU(Wilcoxon)', wilcoxon(rand_taxasAS,
      rand_taxasEU, alternative='greater').pvalue)
print('\nValor-p AS > EU(Ranksums)', ranksums(rand_taxasAS,
      rand_taxasEU, alternative='greater').pvalue)
print('\nValor-p AS > AF(Ranksums)', ranksums(rand_taxasAS,
      rand_taxasAF, alternative='greater').pvalue)

dadosPA = pd.read_excel(caminho, sheet_name='Paises')
paisesPA = dadosPA.loc[:, 'País'].values.astype(str)
taxasPA18 = dadosPA.loc[:, 2018].values.astype(float)
taxasPA10 = dadosPA.loc[:, 2010].values.astype(float)

print('\nPareado')
rand_taxasPA18 = paisesAleatorios(paisesPA, taxasPA18, 100)
print()
rand_taxasPA10 = paisesAleatorios(paisesPA, taxasPA10, 100)
print('\nNao pareado ')
taxasPA18_NPareado = paisesAleatorios(paisesPA, taxasPA18,120, False)
print()
taxasPA10_NPareado = paisesAleatorios(paisesPA, taxasPA10, 80, False)

probPA_pareado = ranksums(rand_taxasPA18, rand_taxasPA10, alternative='less')
print('Teste pareado: ', probPA_pareado[1])

probPA_NPareado = ranksums(taxasPA18_NPareado, taxasPA10_NPareado, alternative='less')
print('Teste não Pareado: ', probPA_NPareado[1])


plt.boxplot([rand_taxasAS, rand_taxasAF])
plt.title("America do Sul x Africa")
plt.show()

plt.boxplot([rand_taxasPA10, rand_taxasPA18])
plt.title("Mortalidade 2010 x 2018")
plt.show()