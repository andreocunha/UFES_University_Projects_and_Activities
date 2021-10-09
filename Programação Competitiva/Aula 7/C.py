from re import split
from sys import stdin

texto = stdin.read() # le tudo
texto = texto.strip().lower() # remove os espaços e deixa tudo minusculo
palavras = sorted(set(split(r'[^a-z]', texto))) # remove tudo que não for do alfabeto, converte em lista e ordena

for palavra in palavras:
    if(palavra != ''):
        print(palavra)