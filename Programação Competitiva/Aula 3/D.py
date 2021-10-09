while True:
    qtd = int(input())
    if qtd == 0:
        break

    N, M = input().split(" ")
    N = int(N)
    M = int(M)

    for i in range(qtd):
        X, Y = input().split(" ")
        X = int(X)
        Y = int(Y)
        
        if X == N or Y == M: #quer dizer que está na divisa
            print('divisa')

        elif X > N: # está no leste
            if Y > M: #está no norte
                print('NE')
            else:
                print('SE')

        else:
            if Y > M: #está no norte
                print('NO')
            else:
                print('SO')