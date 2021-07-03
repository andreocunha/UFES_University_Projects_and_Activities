#ifndef LEITURACSV_H_
#define LEITURACSV_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "Candidato.h"
#include "Partido.h"
#include "Eleicao.h"
#include <stdexcept>
using namespace std;

void ler_candidatos(list<Candidato*>& lista_candidatos, const string& nome_arq, const string& data);
void ler_partidos(list<Partido*>& lista_partidos, list<Candidato*>& lista_candidatos, const string& nome_arq);


#endif