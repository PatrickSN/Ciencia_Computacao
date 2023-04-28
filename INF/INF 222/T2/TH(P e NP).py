from scipy.stats import wilcoxon, ranksums, shapiro, kruskal
import pandas as pd
import matplotlib.pyplot as plt
from intervalo import *


def le(caminho):
    # lê os dados da planilha
    dados = pd.read_excel(caminho, sheet_name='base')
    downloads = dados.loc[:, 'TaxaDownload (Mbps)'].values.astype(int)
    uploads = dados.loc[:, 'TaxaUpload (Mbps)'].values.astype(int)
    return downloads, uploads


def valorP(valorp):
    # verifica se rejeita ou nao H0 com base no valor-p
    if valorp >= 0.05:
        return True
    else:
        return False


def raiz(d1, d2, n1, n2):
    return (((d1**2)/n1)+((d2**2)/n2))


# salva todos os dados das planilhas em um dicionario
dados = {
    'quarto': le('DADOS\dados quarto.xlsx'),
    'quarto24': le('DADOS\dados quarto 2.4.xlsx'),
    'sala': le('DADOS\dados sala.xlsx'),
    'ana': le('DADOS\dados dolores.xlsx'),
    'uso': le('DADOS\dados uso.xlsx')
}

# atribui os dados das conexoes as variaveis
teste = str(
    input('Qual planilha deseja testar:(quarto, quarto24, sala, ana, uso) '))
H0 = int(input('Digite o valor de H0:(<0) '))
while teste not in dados.keys() or H0 < 0:
    print('Entrada Invalida')
    teste = str(
        input('Qual planilha deseja testar:(quarto, quarto24, sala, ana, uso)'))

    H0 = int(input('Digite o valor de H0:(<0) '))

downloads = dados.get(teste)[0]
uploads = dados.get(teste)[1]

# verifica a normalidade das variaveis
testeNormD = shapiro(downloads)
testeNormU = shapiro(uploads)
print()
if valorP(testeNormD[1]):
    print('Download segue uma Distribuição Normal')
else:
    print('Download NÃO segue uma Distribuição Normal')

if valorP(testeNormU[1]):
    print('Upload segue uma Distribuição Normal')
else:
    print('Upload NÃO segue uma Distribuição Normal')

# realiza o teste de wilcoxon
mediana = H0
dif_download = [d - mediana for d in downloads]
dif_upload = [u - mediana for u in uploads]

prob_down = wilcoxon(dif_download, alternative='less')
prob_up = wilcoxon(dif_upload, alternative='less')

print('\nTamanho amostra: ', len(downloads))
print(
    f'Pvalue (Downloads) = {prob_down[1]}	        Pvalue (Uploads) = {prob_up[1]}')

# realiza o teste da soma dos postos
compara = []
for i in range(2):
    entrada = str(
        input('\nQual planilha deseja comparar:(quarto, quarto24, sala, ana, uso) '))
    while entrada not in dados.keys() or entrada in compara or entrada == 's':
        if entrada.lower() == 's':
            break
        print('Entrada Invalida ou igual ao anterior')
        print('Digite "S" para sair')
        entrada = str(
            input('Qual planilha deseja comparar:(quarto, quarto24, sala, ana, uso)'))

    compara.append(entrada)

# Downlod e upload Var1
dx = dados.get(compara[0])[0]
ux = dados.get(compara[0])[1]

# Downlod e upload Var2
dy = dados.get(compara[1])[0]
uy = dados.get(compara[1])[1]

prob_Down = ranksums(dx, dy, alternative='less')
prob_Up = ranksums(ux, uy, alternative='less')

print()
print(50*'-','---Teste da soma dos postos---', 50*'-')
print(51*'-',f'Teste ----- {compara[0]} < {compara[1]} ----', 50*'-')
print(
    f'Pvalue (Downloads) = {prob_Down[1]}	        Pvalue (Uploads) = {prob_Up[1]}')

# comparaçao entre as medias
confianca = 0.05

# testa se as amostras seguem distribuiçao normal
testeNorm = [shapiro(dx), shapiro(dy), shapiro(ux), shapiro(uy)]
i = 0
for t in testeNorm:
    if valorP(t[1]):
        i += 1

if i > 2:
    # definiçao das variaveis para a formula
    z = norm.ppf(confianca)

    mediaD = [somatorio(dx)/len(dx), somatorio(dy)/len(dy)]
    mediaU = [somatorio(ux)/len(ux), somatorio(uy)/len(uy)]

    desvioD = [desvioPadrao(variancia(dx, mediaD[0])),
            desvioPadrao(variancia(dy, mediaD[1]))]
    desvioU = [desvioPadrao(variancia(ux, mediaU[0])),
            desvioPadrao(variancia(uy, mediaU[1]))]

    raizDesviod = raiz(desvioD[0], desvioD[1], len(dx), len(dy))
    raizDesviou = raiz(desvioU[0], desvioU[1], len(uy), len(uy))

    direitaD = mediaD[0] - mediaD[1] - z * raizDesviod
    esquerdaD = mediaD[0] - mediaD[1] + z * raizDesviod

    direitaU = mediaU[0] - mediaU[1] - z * raizDesviou
    esquerdaU = mediaU[0] - mediaU[1] + z * raizDesviou

    print()
    print(50*'-','Teste de comparação das médias', 50*'-')
    print( 30*'-', 'Download', 26*'-',  26*'-', 'Upload', 31*'-')
    print(20*'|',f'{esquerdaD:.5} <= µ1 - µ2 <= {direitaD:.5}',33*'|',f'{esquerdaU:.5} <= µ1 - µ2 <= {direitaU:.5}',20*'|')


plt.boxplot([dx, ux, dy, uy])
plt.title(f"{compara[0]} x {compara[1]}")
plt.show()

