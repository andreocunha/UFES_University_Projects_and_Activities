import math

def kthNonDivisible(N, K):
    return K + math.floor((K - 1) / (N - 1))

numLinhas = int(input())
for i in range(numLinhas):
    num1, num2 = input().split()
    num1 = int(num1)
    num2 = int(num2)
    
    print(kthNonDivisible(num1, num2))
