class Nota {
  int ponto = 10;
}

main() {
  var minhaNota = new Nota();
  var teste = minhaNota;

  print(minhaNota.ponto);
  alteraNota(teste);
  print(minhaNota.ponto);
}

void alteraNota(Nota nota) {
  nota.ponto = 20;
}
