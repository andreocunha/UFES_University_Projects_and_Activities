#ifndef ELEICAO_H_
#define ELEICAO_H_

#include "Candidato.h"
#include "Partido.h"
#include <string>
#include <list>
#include <iomanip>
using namespace std;

class Eleicao {
  private:
    list<Candidato*> lista_candidatos;
    list<Candidato*> lista_candidatos_eleitos;
    list<Candidato*> lista_candidatos_mais_votados;
    list<Candidato*> lista_candidatos_eleitos_beneficiaram;
    list<Partido*> lista_partidos;
    int num_vagas = 0;
    int idades[5];
    int sexos[2];
    int votos_nominais;
    int votos_legenda;


  public:
	Eleicao();
	
    //Essa função não tem retorno e recebe um ponteiro para uma lista de candidatos
    //tem o objetivo ordenar a lista de candidatos e adicionar a lista dentro de eleição 
    void cria_lista_candidatos(list<Candidato*>& lista_candidatos);

    //Essa função não tem retorno e recebe um ponteiro para uma lista de candidatos
    //tem o objetivo de criar a lista de candidatos eleitos 
    void cria_lista_candidatos_eleitos(const list<Candidato*>& lista_candidatos);

    //Essa função não tem retorno e recebe um ponteiro para uma lista de candidatos
    //tem o objetivo de criar a lista de candidatos mais votados 
    void cria_lista_candidatos_mais_votados(const list<Candidato*>& lista_candidatos);


    //Essa função não tem retorno e não recebe parametros
    //tem o objetivo de imprimir os candidatos que se beneficaram do sistema 
    void imprime_lista_candidatos_eleitos_beneficiaram();


    //Essa função não tem retorno e não recebe parametros
    //tem o objetivo de imprimir a lista de candidatos eleitos
    void imprime_lista_candidatos_eleitos();

    //Essa função não tem retorno e não recebe parametros
    //tem o objetivo de imprimir a lista de candidatos mais votados
    void imprime_lista_candidatos_mais_votados();

    //Essa função não tem retorno e não recebe parametros
    //tem o objetivo de imprimir a lista de candidatos mais votados mas que não foram eleitos
    void imprime_lista_candidatos_mais_votados_nao_eleitos();


    //Essa função não tem retorno e recebe um ponteiro para uma lista de partidos
    //tem o objetivo de criar a lista de partidos dentro de eleição
    void cria_lista_partidos(const list<Partido*>& lista_partidos);
  

    //Essa função não tem retorno e não recebe parametros
    //tem o objetivo de imprimir a lista de partidos e suas informações
    void imprime_lista_partidos();

    //Essa função não tem retorno e não recebe parametros
    //tem o objetivo de imprimir a lista de partidos ordenada(com o maior candidato e o menor)
    void imprime_lista_partidos_prim_ult();


    //Essa função recebe um int quant e retorna um double
    //ira retornar o ca
    double calcula_porcentagem(int quant);

    void imprime_por_sexo();

    void imprime_por_faixa_etaria();

    void imprime_votos_totais();

    int calcula_idade(const string& data_cand, const string& data_eleicao);

	void print() const;
	void println() const;

	~Eleicao();
};

#endif