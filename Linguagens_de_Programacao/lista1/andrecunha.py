# Feito por Andre Oliveira Cunha
# Lista de exercicios 1

from functools import reduce

# Questao 1
# a)
lista = lambda x: list(range(1, x+1))
print(lista(5)) #isto retorna [1, 2, 3, 4, 5]

# b)
lista_invertida = lambda x: list(range(x, 0, -1))
print(lista_invertida(5)) #isto retorna [5, 4, 3, 2, 1]

# c)
lista_dobro_dos_numeros = lambda x: [i*2 for i in range(1, x+1)]
print(lista_dobro_dos_numeros(5)) #isto retorna [2, 4, 6, 8, 10]

# d)
lista_dobro_de_numeros = lambda x: list(range(1, 2*x+1))
print(lista_dobro_de_numeros(5)) #isto retorna [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# e)
lista_divisiveis_por_3 = lambda x: [i for i in range(1, x+1) if i%3==0]
print(lista_divisiveis_por_3(12)) #isto retorna [3, 6, 9, 12]

# f)
lista_dobro_pares_quadrado_impares = lambda x: [i*2 for i in range(1, x+1) if i%2==0] + [i**2 for i in range(1, x+1) if i%2!=0]
print(lista_dobro_pares_quadrado_impares(5)) #isto retorna [2, 4, 6, 8, 10, 9, 25, 49]

# g)
def functionG(x,y): 
    return x*y
multiplica_elementos_lista = reduce(functionG, [1, 2, 3, 4, 5])
print(multiplica_elementos_lista) #isto retorna 120
    
# h)
def functionH(x,y):
    if(y % 2 == 0):
        return x-y
    else:
        return x+y
soma_elementos_lista = reduce(functionH, [1, 2, 3, 4, 5])
print(soma_elementos_lista) #isto retorna 3

# i)
def functionI(n):
    return [(n1, n2) for n1 in range(1,n+1) for n2 in range(1,n+1) if n1+n2 == n]
print(functionI(4)) #isto retorna [(1, 3), (2, 2), (3, 1)]

# j)
print(list(zip(range(1,6), range(2,7), range(3,8))))

# k)
def functionMaxMin(list):
    return max(list), min(list)
print(functionMaxMin([1, 2, 3, 4, 5])) #isto retorna (5, 1)

# Questao 2
