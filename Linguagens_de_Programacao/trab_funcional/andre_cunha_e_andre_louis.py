# Andre Oliveira Cunha e Andre Louis Souza Ribeiro

# funcoes auxiliares
def addPosicaoInicial(pontos):
  return [(0, 0)] + pontos

def retornaPontosDoRobo(robo, entrada):
  return addPosicaoInicial([x[2] for x in entrada if x[0] == robo])

def removeDuplicados(entrada):
  return [ x for i, x in enumerate(entrada) if x not in entrada[:i] ]
  
def distanciaPonto(ponto1, ponto2):
  return ((ponto1[0] - ponto2[0])**2 + (ponto1[1] - ponto2[1])**2)**0.5

def retornaUltimoTempoRobo(robo, entrada):
  return max(entrada, key=lambda x: x[1] if x[0] == robo else 0)[1]

# a)
def distPercorridaRobo(robo, entrada):
  return sum(distanciaPonto(ponto1, ponto2) for ponto1, ponto2 in zip(retornaPontosDoRobo(robo, entrada), retornaPontosDoRobo(robo, entrada)[1:]))


# b)
def roboMaiorDistFinalOrigem(entrada):
  return max(entrada, key=lambda x: distanciaPonto(x[2], (0, 0)))[0]


# c)
def caminhosRobos(entrada):
  # usar a funcao retornaPontosDoRobo para calcular a distancia percorrida por um determinado robo
  return removeDuplicados(sorted([(x[0], distPercorridaRobo(x[0], entrada), retornaPontosDoRobo(x[0], entrada)) for x in entrada], key=lambda x: x[1]))


# d)
def roboIdentifcaMaisVitimas(entrada):
  return max(entrada, key=lambda x: x[3])[0]


# Aplicando o código no exemplo de entrada 1:
entrada = [
  ('robo1', 1, (5, 8), 4), 
  ('robo2', 2, (5, 4), 4), 
  ('robo3', 3, (2, 2), 1), 
  ('robo1', 4, (4, 9), 4), 
  ('robo3', 5, (1, 3), 3), 
  ('robo4', 6, (7, 5), 3), 
  ('robo5', 7, (8, 6), 1), 
  ('robo1', 8, (3, 2), 4), 
  ('robo2', 9, (1, 8), 4)
]

print('LETRA A)\ndistPercorridaRobo(\'robo1\', reg1())\n', distPercorridaRobo('robo1', entrada))

print('\n\nLETRA B)\nroboMaiorDistFinalOrigem(reg1())\n', 
'(', '\'',
roboMaiorDistFinalOrigem(entrada),'\'',',', 
retornaPontosDoRobo(roboMaiorDistFinalOrigem(entrada), entrada), 
retornaUltimoTempoRobo(roboMaiorDistFinalOrigem(entrada), entrada),
')'
)

print('\n\nLETRA C)\ncaminhosRobos(reg1())\n', caminhosRobos(entrada))

print('\n\nLETRA D)\nroboIdentifcaMaisVitimas(reg1())\n', '\'', roboIdentifcaMaisVitimas(entrada), '\'')