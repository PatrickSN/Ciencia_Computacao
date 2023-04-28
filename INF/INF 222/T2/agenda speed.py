from datetime import datetime
import speed


horarios = [
    '02 00 00', '04 10 00', '06 00 00', '08 00 00', 
    '12 00 00', '14 00 00', '18 00 00', '20 00 00',
    '22 00 00', '00 00 00'
]

while True:
    data_e_hora_atuais = datetime.now()
    hora = data_e_hora_atuais.strftime('%H %M %S')
    if hora in horarios:
        speed.start(10, 1)