from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
from datetime import datetime
from random import choice

textos = []
for i in range(5):
    textos[i] = input("Digite as possiveis mensagens a serem enviadas: ")
numeroPessoas = int(input("Digite o número de pessoas que irão receber a mensagem: "))
lista_pessoas = []
for i in range(numeroPessoas):
    lista_pessoas[i] = input("Digite o nome da pessoa igual esta em seu wpp:")

class WppBot:
    def __init__(self):
        self.pessoas = lista_pessoas
        self.driver = webdriver.Firefox(executable_path=r'geckodriver.exe')


    def acesso(self):
        driver = self.driver
        driver.get("https://web.whatsapp.com/")


    def pesquisa(self, nome):
        campo_pesquisa = self.driver.find_element_by_xpath(
            '//*[@id="side"]/div[1]/div/label/div/div[2]')
        campo_pesquisa.click()
        campo_pesquisa.clear
        campo_pesquisa.send_keys(nome)
        campo_pesquisa.send_keys(Keys.RETURN)


    def comenta(self, texto):
        campo_comentario = self.driver.find_element_by_xpath(
            '//*[@id="main"]/footer/div[1]/div/span[2]/div/div[2]/div[1]/div/div[2]')
        campo_comentario.clear
        time.sleep(5)
        campo_comentario.click()
        campo_comentario.send_keys(texto)
        campo_comentario.send_keys(Keys.RETURN)


    def iniciar(self):
        print('---Iniciando---')
        while True:
            for pessoa in self.pessoas:
                self.pesquisa(pessoa)
                '''contato = self.driver.find_element_by_xpath(
                    f"//span[@title='{pessoa}']")
                contato.click()'''
                time.sleep(10)
                try:
                    online = self.driver.find_elements_by_xpath(
                        '//div[@class="zzgSd _3e6xi"]')
                    # class="zzgSd _3e6xi"//_2Gdma _2amHe
                    time.sleep(10)
                    if online != []:
                        self.comenta(choice(textos))
                        time.sleep(3)
                        self.pessoas.remove(pessoa)

                except Exception as e:
                    print(e)
            if self.pessoas == []:
                print('---Todos receberam as mensagens---')
                break
            time.sleep(10)
        self.driver.close()


OnlineBot = WppBot()
OnlineBot.acesso()

inicio = input("Hora de inicio:(HH:MM:SS) ")

hora = datetime.now()
data_hora = hora.strftime('%H:%M:%S')

while inicio != data_hora:
    hora = datetime.now()
    data_hora = hora.strftime('%H:%M:%S')
OnlineBot.iniciar()
