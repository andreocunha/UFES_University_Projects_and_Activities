def removeCaixasNaoVisiveis(caixas):
    ultimoValor = -1
    while True:
        index = 0
        flag = False
        for caixa in caixas:
            if caixas[0] > caixa:
                if ultimoValor == -1 or ultimoValor != caixa:
                    ultimoValor = caixa
                    caixas.pop(index)
                    flag = True
                    break
            index += 1
        if not flag:  
            return


qtd = int(input())
caixas = input().split(' ')

for i in range(qtd):
    caixas[i] = int(caixas[i])

caixas.sort(reverse=True)

removeCaixasNaoVisiveis(caixas)
print(len(caixas))
