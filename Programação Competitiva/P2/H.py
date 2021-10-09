def stock_max(prices, number, day, tam):
    if day >= tam:
        return 0
    #buy / none / sell
    return max(
        stock_max(prices, number+1, day+1, tam) - prices[day],
        stock_max(prices, number, day+1, tam),
        stock_max(prices, 0, day+1, tam)+(prices[day]*number)
    )

t = int(input())

prices = []
for i in range(t):
    n = int(input())
    prices = input().split()
    for j in range(n):
        prices[j] = int(prices[j])

    print(stock_max(prices, 0, 0, n))