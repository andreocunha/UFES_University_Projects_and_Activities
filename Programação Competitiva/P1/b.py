leitura = input().split('+')

leitura.sort()
tam = len(leitura)
contador = 1
for i in leitura:
    print(i,end="")
    if contador != tam:
        print("+", end="")
    contador +=1