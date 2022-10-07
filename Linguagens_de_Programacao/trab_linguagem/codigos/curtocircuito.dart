bool curtoCircuito() {
  print('Curto circuito');
  return true;
}

main() {

	if(true == true && curtoCircuito()) {
    print('Deu bom\n');
  }
  
  if(true == false && curtoCircuito()){
    print('Deu ruim\n');
  }

  if(true == true || curtoCircuito()) {
    print('Deu bom\n');
  }
}
