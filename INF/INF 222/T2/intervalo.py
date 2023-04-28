from scipy.stats import norm, t
import pandas as pd
from datetime import datetime

# https://docs.scipy.org/doc/scipy/index.html


def somatorio(listaNum):
    '''retorna a soma dos numeros de uma lista'''
    soma = 0
    for i in range(len(listaNum)):
        soma += listaNum[i]
    return soma


def variancia(listaNum, media):
    '''retorna a media quadratica entre os desvios'''
    desvio = []
    for i in range(0, len(listaNum)):
        variacao = (listaNum[i] - media) ** 2
        desvio.append(variacao)
    return somatorio(desvio)/(len(listaNum)-1)


def desvioPadrao(variancia):
    return variancia ** 0.5

def le(caminho):
    # lê os dados da planilha
    dados = pd.read_excel(caminho, sheet_name='base')
    downloads = dados.loc[:, 'TaxaDownload (Mbps)'].values.astype(int)
    uploads = dados.loc[:, 'TaxaUpload (Mbps)'].values.astype(int)
    return downloads, uploads


if __name__ == '__main__':
    #salva todos os dados das planilhas em um dicionario
    dados = {
        'quarto' : le('DADOS\dados quarto.xlsx'),
        'quarto24' : le('DADOS\dados quarto 2.4.xlsx'),
        'sala' : le('DADOS\dados sala.xlsx'),
        'ana' : le('DADOS\dados dolores.xlsx'),
        'uso' : le('DADOS\dados uso.xlsx') 
    }

    teste = str(input('Qual planilha deseja testar:(quarto, quarto24, sala, ana, uso)'))
    while teste not in dados.keys():
        print('Entrada Invalida')
        teste = str(input('Qual planilha deseja testar:(quarto, quarto24, sala, ana, uso)'))
    download = dados.get(teste)[0]
    upload = dados.get(teste)[1]

    tam_D = len(download)
    tam_U = len(upload)

    # calcula a media de download e upload
    media_D = somatorio(download)/tam_D
    media_U = somatorio(upload)/tam_U

    # calcula o desvio de download e upload
    desvio_D = desvioPadrao(variancia(download, media_D))
    desvio_U = desvioPadrao(variancia(upload, media_U))

    # realiza os testes normal e t-student
    confianca = 1 - 0.95
    prob_Z = norm.ppf(confianca)
    prob_T = t.ppf(confianca, tam_D-1)

    # calcula o intervalo de confiança seguindo a dist. normal e t-student
    intervalo_D = media_D-((prob_Z*desvio_D)/(tam_D**0.5))
    intervalo_tD = media_D-((prob_T*desvio_D)/(tam_D**0.5))

    intervalo_U = media_U-((prob_Z*desvio_U)/(tam_U**0.5))
    intervalo_tU = media_U-((prob_T*desvio_U)/(tam_U**0.5))

    #imprime o resultado do intervalo de confiança 
    print('Download » Média:%.2f Desvio:%.2f' %(media_D, desvio_D))
    print('Download » Média:%.2f Desvio:%.2f' %(media_U, desvio_U))
    print(68*'-')
    print(teste, datetime.now())
    print(11*'-', 'Intervalo de confiança (Distribuição Normal)', 11*'-')
    print('Download: %8.2f <= µ' % intervalo_D)
    print('Upload: %10.2f <= µ' % intervalo_U)
    print(10*'-', 'Intervalo de confiança(Distribuição T-Student)', 10*'-')
    print('Download: %8.2f <= µ' % intervalo_tD)
    print('Upload: %10.2f <= µ' % intervalo_tU)
    print(68*'-')
