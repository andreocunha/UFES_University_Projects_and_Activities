dicionario = {}

while True:
    words = input()
    try:
        english, foreign_language = words.split(' ')
        dicionario[foreign_language] = english        
        
    except:        
        while True:
            try:
                word = input()
                if(word in dicionario):
                    print(dicionario[word])
                else:
                    print('eh')
            except EOFError as e:
                break
        break