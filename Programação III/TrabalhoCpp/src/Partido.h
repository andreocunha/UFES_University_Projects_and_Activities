#ifndef PARTIDO_H_
#define PARTIDO_H_

#include "Candidato.h"
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <list>
using namespace std;

class Partido {
  private:
    string votos_legenda;
    string nome_partido;
    string sigla_partido;
    string numero_partido;
    list<Candidato*> lista_candidatos_partido;
    int votos_nominais;  
    int votos_totais;
    int candidatos_eleitos;

  public:
	Partido();
    Partido(const vector<string>& dados_partido);
	
    void set_numero_partido(const string& num_partido){
        this->numero_partido = num_partido;
    }
    void set_votos_legenda(const string& votos_legenda){
        this->votos_legenda = votos_legenda;
    }

    const string& get_votos_legenda() const{
        return this->votos_legenda;
    }

    void set_nome_partido(const string& nome_partido){
        this->nome_partido = nome_partido;
    }
    void set_sigla_partido(const string& sigla_partido){
        this->sigla_partido = sigla_partido;
    }

    int get_numero_candidatos_partido(){
        return this->lista_candidatos_partido.size();
    }

    int get_votos_totais() const{
        return this->votos_totais;
    }


	void println() const;


    //Essa função ira receber uma lista de candidatos
    //não ira retornar nada 
    //Essa função tem o objetivo de adicionar os candidatos que pertecem a esse partido na lista de candidato do partido
    void set_candidatos_do_partido(const list<Candidato*>& lista_candidatos);


    //Essa função ira receber uma lista de candidatos
    //não ira retornar nada
    void imprime_partido_prim_ult();

    Candidato* get_primeiro_candidato(){
      return this->lista_candidatos_partido.front();
    }

	~Partido();
};







#endif