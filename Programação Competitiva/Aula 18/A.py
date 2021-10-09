letterH = 0
letterE = 0
letterL = 0
letterO = 0

word = input()

for i in range(len(word)):
    if letterH == 0:
        if word[i] == 'h':
            letterH += 1
    
    if letterH == 1 and letterE == 0:
        if word[i] == 'e':
            letterE += 1
    
    if letterE == 1 and letterL <= 1:
        if word[i] == 'l':
            letterL += 1
    
    if letterL == 2 and letterO == 0:
        if word[i] == 'o':
            letterO += 1

    
if letterH == 1 and letterE == 1 and letterL == 2 and letterO == 1:
    print('YES')
else:
    print('NO')