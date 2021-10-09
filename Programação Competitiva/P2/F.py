def contaConsultas(stringLine, x, y):
    characterAtual = stringLine[x-1] # -> .
    result = 0
    
    for i in range(y - x): # 3
        if characterAtual == stringLine[x+i]:
            result += 1
        else:
            characterAtual = stringLine[x+i]

    return result


stringLine = input()
stringLine = list(stringLine)

m = int(input())

for i in range(m):
    soma = 0
    x,y = input().split()
    x = int(x) 
    y = int(y)
    print(contaConsultas(stringLine, x, y))





