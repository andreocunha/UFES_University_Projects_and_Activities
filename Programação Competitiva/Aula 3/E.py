t = int(input())

for i in range(t):
    valores = input().split(" ")
    valores.sort()
    print("Case " + str(i+1) + ": " + valores[1])