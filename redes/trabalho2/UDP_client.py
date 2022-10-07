# Andre Oliveira Cunha - Trabalho 2 de Redes

from socket import *
from statistics import stdev
import time
 
msg = "andre_cunha"
# host = '168.227.188.22'
host = '127.0.0.1'
port = 30000

pacotes_enviados = 0
pacotes_recebidos = 0
tempo_todas_rtt = []
tempo_total = 0
 
# Criando um socket UDP do cliente
clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(2)


def valida_mensagem(mensagem_enviada, mensagem_recebida):
  rm1 = mensagem_recebida[0:5]
  rm2 = mensagem_recebida[5:6]
  rm3 = mensagem_recebida[6:10]
  rm4 = mensagem_recebida[10:40]

  sm1 = mensagem_enviada[0:5]
  sm2 = mensagem_enviada[5:6]
  sm3 = mensagem_enviada[6:10]
  sm4 = mensagem_enviada[10:40]
  
  if len(mensagem_recebida) != 40:
    return False
  elif rm2 != '1':
    return False
  elif sm1 != rm1:
    return False
  elif sm4 != rm4:
    return False
  elif sm3 != rm3:
    return False
  return True


for i in range(0, 10):  
  rtt = time.time_ns()
  if i == 0:
    tempo_total = time.time_ns()
  
  number = str(i).rjust(5,'0')
  timestamp = str(int(rtt / 1000000) % 10000).rjust(4,'0')
  full_msg = str(msg).ljust(30,'\0')
  payload = number + '0' + timestamp + full_msg

  # enviando um pacote
  clientSocket.sendto(payload.encode(), (host, port))

  pacotes_enviados += 1

  try:
    data, server = clientSocket.recvfrom(1024)

    mensagem_recebida = data.decode()
    rm1 = mensagem_recebida[0:5]
    sm1 = payload[0:5]

    # Se entrar no while, é porque recebeu um pacote atrasado
    while int(rm1) < int(sm1): 
      data, server = clientSocket.recvfrom(1024)
      mensagem_recebida = data.decode()
      rm1 = mensagem_recebida[0:5]
    
    rtt = time.time_ns() - rtt
    rtt = rtt / 1000000

    if(valida_mensagem(payload, mensagem_recebida) is False):
      print('Pacote inválido')
      continue

    tempo_todas_rtt.append(rtt)
    print(mensagem_recebida)
    pacotes_recebidos += 1

  except:
    print('Pacote perdido [tempo limite excedido]')

tempo_total = time.time_ns() - tempo_total
tempo_total = tempo_total / 1000000

if pacotes_recebidos == 0:
  print('Nenhum pacote recebido')

else:
  result = f"{pacotes_enviados} packets transmitted, {pacotes_recebidos} received, {100 - pacotes_recebidos/pacotes_enviados*100}% packet loss, time {tempo_total:.2f}ms rtt min/avg/max/mdev = {min(tempo_todas_rtt):.4f}/{sum(tempo_todas_rtt)/len(tempo_todas_rtt):.4f}/{max(tempo_todas_rtt):.4f}/{stdev(tempo_todas_rtt):.4f} ms"

  print(result)