#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "LeituraCSV.h"
#include "Candidato.h"
#include "Eleicao.h"
#include "Partido.h"
using namespace std;

int main(int argc, char* argv[]){
    list<Candidato*> lista_candidatos;
    list<Partido*> lista_partidos;
    Eleicao* eleicao = new Eleicao(); 

    if(argc < 4){
        cout << "Quantidade de arquivos insuficiente" << endl;
        exit(1);
    }

    try {
        string arq_candidatos = argv[1];
        string data = argv[3];
        ler_candidatos(lista_candidatos, arq_candidatos, data);            
        
        eleicao->cria_lista_candidatos(lista_candidatos);
        eleicao->cria_lista_candidatos_eleitos(lista_candidatos);
        eleicao->cria_lista_candidatos_mais_votados(lista_candidatos);
    
        string arq_partido = argv[2];
        ler_partidos(lista_partidos, lista_candidatos, arq_partido);   

        eleicao->cria_lista_partidos(lista_partidos);
        eleicao->imprime_lista_candidatos_eleitos();
        eleicao->imprime_lista_candidatos_mais_votados();
        eleicao->imprime_lista_candidatos_mais_votados_nao_eleitos();
        eleicao->imprime_lista_candidatos_eleitos_beneficiaram();
        eleicao->imprime_lista_partidos();
        eleicao->imprime_lista_partidos_prim_ult();
        eleicao->imprime_por_faixa_etaria();
        eleicao->imprime_por_sexo();
        eleicao->imprime_votos_totais(); 

        
        
    } catch(exception &ex){
        cout << "ERRO: " << ex.what() << "!\n";
    }

    delete eleicao;

    return 0;
}

