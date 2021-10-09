rfp = 1
while True:
    ignoraLinhas,qtdEmpresas = input().split(" ")
    ignoraLinhas = int(ignoraLinhas)
    qtdEmpresas = int(qtdEmpresas)
    if(ignoraLinhas == 0 and qtdEmpresas == 0):
        break
    
    if(rfp != 1):
        print()

    for i in range(ignoraLinhas):
        linha = input()

    empresaEscolhida = ' '
    valorEscolhida = -1
    matchEscolhida = -1
    for i in range(qtdEmpresas):
        empresa = input()
        valor,match = input().split(" ")
        match = int(match)

        for i in range(match):
            linha = input()

        if(match > matchEscolhida):
            empresaEscolhida = empresa
            valorEscolhida = valor
            matchEscolhida = match

        elif(match == matchEscolhida):
            if(valor < valorEscolhida):
                empresaEscolhida = empresa
                valorEscolhida = valor
                matchEscolhida = match

    print("RFP #" + str(rfp))
    print(empresaEscolhida)
    rfp += 1
