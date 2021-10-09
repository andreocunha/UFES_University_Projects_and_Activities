t = int(input())

for i in range(t):
    valores = input().split(" ")
    qtdCriaturas = int(valores[0])

    maior = int(valores[1])
    for j in range(qtdCriaturas):
        velocidade = int(valores[j+1])
        if velocidade > maior:
            maior = velocidade

    print("Case " + str(i + 1) + ": " + str(maior))