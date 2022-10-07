def mov_rei(posAtual, movimento):
  return True

def mov_torre(posAtual, pecaInimiga):
  if(posAtual[0] == pecaInimiga[0] or posAtual[1] == pecaInimiga[1]):
    return True
  return False

def esta_dentro_do_tabuleiro(posAtual):
  return True

def eh_mov_valido(posAtual, movimento):
  return True

def eh_possivel_eliminar_peca(posAtual, posPeca, movimento):
  return True

# (1, 8) (5, 4)
# (4, 6) (3, 5)
# (3, 5) (2, 6)



# (5, 4) (1, 8)   ->  (4, 4)
# (4, 6) (3, 5)   ->  (1, 1)