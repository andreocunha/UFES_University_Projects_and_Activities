while True:
    dados = input().split(" ")
    duracaoMeses = int(dados[0])
    if(duracaoMeses < 0):
        break

    emprestimo = float(dados[1])
    valorCarro = float(dados[2]) + emprestimo
    numDepreciacao = int(dados[3])

    valorPagoPorMes = float(dados[2]) / duracaoMeses

    valorDeve = float(dados[2])

    porcentagensMeses = []
    for i in range(numDepreciacao):
        valores = input().split(" ")
        porcentagensMeses.append(valores)
    

    mesFinal = 0
    porcentagemAtual = float(porcentagensMeses[0][1])
    valorCarro -= valorCarro*porcentagemAtual
    pos = 1
    k = 0

    for j in range(duracaoMeses):
        k = j + 1

        if(valorDeve < valorCarro):
            break
        
        if pos < numDepreciacao:
            if(k == int(porcentagensMeses[pos][0])):
                porcentagemAtual = float(porcentagensMeses[pos][1])
                pos += 1
        
        valorCarro -= valorCarro*porcentagemAtual
        valorDeve -= valorPagoPorMes
        mesFinal += 1

        # print("valorCarro: " + str(valorCarro) + " - valorDeve: " + str(valorDeve))
    
    if(valorDeve < valorCarro):
        if(mesFinal == 1):
            print(str(mesFinal) + " month")
        else:
            print(str(mesFinal) + " months")