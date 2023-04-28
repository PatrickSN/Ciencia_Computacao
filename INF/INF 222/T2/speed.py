import speedtest
from datetime import datetime
import pandas as pd
from time import sleep

#https://github.com/sivel/speedtest-cli

def teste_internet(caminho):
    # lê a base de dados de testes anteriores
    dados = pd.read_excel(caminho, sheet_name='base')
    # Instanciando a função de test do Speedtest
    s = speedtest.Speedtest(secure=True)
    s.get_servers()
    s.get_best_server()
    # Testa as velocidades de internet
    velocidade_download = round(s.download(threads=None)*(10**-6))
    velocidade_upload = round(s.upload(threads=None)*(10**-6))
    # Salva a data e a hora do teste
    data_atual = datetime.now().strftime('%d/%m/%Y')
    hora_atual = datetime.now().strftime('%H:%M')
    # Atualiza a base de dados
    dados.loc[len(dados)] = [data_atual, hora_atual,
                             velocidade_download, velocidade_upload]
    dados.to_excel(caminho, sheet_name='base', index=False)
    return data_atual, hora_atual, velocidade_download, velocidade_upload


def start(qtde, tempo):
    # Definição de variáveis para teste
    caminho = 'DADOS\dados cabo.xlsx'
    segundos = 60
    # Loop de execução dos testes
    for i in range(qtde):
        data_atual, hora_atual, vel_dowl, vel_upl = teste_internet(caminho)
        print(
            f'Teste {i+1}/{qtde} Data: {data_atual} Hora: {hora_atual} Download: {vel_dowl} Upload: {vel_upl}')
        if (i+1) < qtde:
            sleep(tempo*segundos)


if __name__ == '__main__':
    start(15, 1)