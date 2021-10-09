import heapq

def insereValor(li, valor):
    global operacoes
    string = 'insert ' + valor
    operacoes.append(string)
    heapq.heappush(li, int(valor))

def removeMin(li):
    global operacoes
    valorRemovido = heapq.heappop(li)
    operacoes.append('removeMin')
    while True:
        menorValorAtual = heapq.nsmallest(1, li)
        if len(menorValorAtual) == 0:
            break
        if menorValorAtual[0] == valorRemovido:
            valorRemovido = heapq.heappop(li)
            operacoes.append('removeMin')
        else:
            break

def getMin(li, value):
    global operacoes
    menorValorAtual = heapq.nsmallest(1, li)
    if len(menorValorAtual) > 0:
        while (menorValorAtual[0] < int(value)):
            removeMin(li)
            menorValorAtual = heapq.nsmallest(1, li)
            if len(menorValorAtual) == 0:
                break
    if len(menorValorAtual) > 0:
        if menorValorAtual[0] != int(value):
            operacoes.append('insert ' + value)
        operacoes.append('getMin ' + value)
    else:
        operacoes.append('insert ' + value)
        operacoes.append('getMin ' + value)

li = []
operacoes = []
qtdComandos = int(input())

heapq.heapify(li)
for i in range(qtdComandos):
    comandos = input().split(' ')
    if comandos[0] == 'insert':
        insereValor(li, comandos[1])
    elif comandos[0] == 'removeMin':
        heapq.heappop(li)
        operacoes.append('removeMin')
    elif comandos[0] == 'getMin':
        getMin(li, comandos[1])

print(len(operacoes))
for operacao in operacoes:
    print(operacao)