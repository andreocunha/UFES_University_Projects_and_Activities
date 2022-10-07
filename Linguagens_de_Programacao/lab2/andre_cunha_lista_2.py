# Andre Oliveira Cunha - Lista2

# funcao que verifica se a peca esta no tabuleiro
def verifica_tabuleiro(peca):
    return peca['x'] >= 1 and peca['x'] <= 8 and peca['y'] >= 1 and peca['y'] <= 8

# funcao que verifica se consegue matar a peca na diagonal
def verifica_diagonal(pecaA, pecaB):
    return abs(pecaA['x'] - pecaB['x']) == abs(pecaA['y'] - pecaB['y'])

# funcao que verifica se consegue matar a peca na horizontal ou vertical
def verifica_horizontal_vertical(pecaA, pecaB):
    return pecaA['x'] == pecaB['x'] or pecaA['y'] == pecaB['y']

# verifica se o rei consegue matar a peca
def verifica_rei(rei, peca):
    if (rei['x'] + 1 == peca['x']): return True
    elif (rei['x'] - 1 == peca['x']): return True
    elif (rei['y'] - 1 == peca['y']): return True
    elif (rei['y'] + 1 == peca['y']): return True  
    elif (rei['x'] + 1 == peca['x'] and rei['y'] - 1 == peca['y']): return True
    elif (rei['x'] - 1 == peca['x'] and rei['y'] - 1 == peca['y']): return True
    elif (rei['x'] - 1 == peca['x'] and rei['y'] + 1 == peca['y']): return True
    elif (rei['x'] + 1 == peca['x'] and rei['y'] + 1 == peca['y']): return True
    else: return False
   
# verfica se a dama consegue matar a peca
def verifica_dama(dama, peca):
    return verifica_diagonal(dama, peca) or verifica_horizontal_vertical(dama, peca)
   
# verifica se a torre consegue matar a peca
def verifica_torre(torre, peca):
    return verifica_horizontal_vertical(torre, peca)

# verifica se o bispo consegue matar a peca
def verifica_bispo(bispo, peca):
    return verifica_diagonal(bispo, peca)

# verifica se o cavalo consegue matar a peca
def verfica_cavalo(cavalo, peca):
  if (cavalo['x'] + 2 == peca['x'] and cavalo['y'] - 1 == peca['y']): return True
  elif (cavalo['x'] + 1 == peca['x'] and cavalo['y'] - 2 == peca['y']): return True
  elif (cavalo['x'] - 1 == peca['x'] and cavalo['y'] - 2 == peca['y']): return True
  elif (cavalo['x'] - 2 == peca['x'] and cavalo['y'] - 1 == peca['y']): return True
  elif (cavalo['x'] - 2 == peca['x'] and cavalo['y'] + 1 == peca['y']): return True
  elif (cavalo['x'] - 1 == peca['x'] and cavalo['y'] + 2 == peca['y']): return True
  elif (cavalo['x'] + 1 == peca['x'] and cavalo['y'] + 2 == peca['y']): return True
  elif (cavalo['x'] + 2 == peca['x'] and cavalo['y'] + 1 == peca['y']): return True
  else: return False

# verifica se o peao consegue matar a peca
def verifica_peao(peao, peca):
  return (peao['x'] + 1 == peca['x'] and peao['y'] - 1 == peca['y'] or peao['x'] - 1 == peca['x'] and peao['y'] - 1 == peca['y'])

def consegue_matar_peca(nome, minha_peca, peca_oponente):
    # verifica se a peca esta no tabuleiro
    if (not verifica_tabuleiro(minha_peca) or not verifica_tabuleiro(peca_oponente)): return False

    if nome == 'Rei':  return verifica_rei(minha_peca, peca_oponente)
    elif nome == 'Dama':  return verifica_dama(minha_peca, peca_oponente)
    elif nome == 'Torre':  return verifica_torre(minha_peca, peca_oponente)
    elif nome == 'Bispo':  return verifica_bispo(minha_peca, peca_oponente)
    elif nome == 'Cavalo':  return verfica_cavalo(minha_peca, peca_oponente)
    elif nome == 'Peao':  return verifica_peao(minha_peca, peca_oponente)
    else: print("Peca nao encontrada")
    return False


print(consegue_matar_peca('Rei', {'x': 5, 'y': 4}, {'x': 5, 'y': 5}))
print(consegue_matar_peca('Rei', {'x': 5, 'y': 4}, {'x': 5, 'y': 6}))

print(consegue_matar_peca('Dama', {'x': 1, 'y': 1}, {'x': 3, 'y': 3}))
print(consegue_matar_peca('Dama', {'x': 5, 'y': 4}, {'x': 2, 'y': 8}))

print(consegue_matar_peca('Cavalo', {'x': 3, 'y': 1}, {'x': 1, 'y': 2}))
print(consegue_matar_peca('Cavalo', {'x': 5, 'y': 4}, {'x': 1, 'y': 8}))

print(consegue_matar_peca('Peao', {'x': 5, 'y': 4}, {'x': 4, 'y': 3}))
print(consegue_matar_peca('Peao', {'x': 5, 'y': 4}, {'x': 2, 'y': 8}))

print(consegue_matar_peca('Torre', {'x': 5, 'y': 4}, {'x': 5, 'y': 6}))
print(consegue_matar_peca('Torre', {'x': 5, 'y': 4}, {'x': 1, 'y': 8}))

print(consegue_matar_peca('Bispo', {'x': 5, 'y': 4}, {'x': 1, 'y': 8}))
print(consegue_matar_peca('Bispo', {'x': 4, 'y': 4}, {'x': 1, 'y': 8}))
