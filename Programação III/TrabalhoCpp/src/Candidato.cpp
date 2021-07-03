#include<cstdio>
#include <iostream>
#include "Candidato.h"


Candidato::Candidato(const vector<string>& dadosCandidato ) {
    setNumero(dadosCandidato[0]);
    setVotosNominais(dadosCandidato[1]);
    setSituacao(dadosCandidato[2]);
    setNome(dadosCandidato[3]);
    setNomeUrna(dadosCandidato[4]);
    setSexo(dadosCandidato[5]);
    setDataNasc(dadosCandidato[6]);
    setDestinoVoto(dadosCandidato[7]);
    setNumeroPartido(dadosCandidato[8]);
}

bool Candidato::candidato_eleito() const{
    if(!this->situacao.compare("Eleito")){
        return true;
    }
    return false;
}

void Candidato::calcula_idade_e_armazena(const string& data_cand , const string& data_eleicao){
    int dia_cand = stoi(data_cand.substr(0,2));
    int mes_cand = stoi(data_cand.substr(3,2));
    int ano_cand = stoi(data_cand.substr(6,4));

    int dia_eleicao = stoi(data_eleicao.substr(0,2));
    int mes_eleicao = stoi(data_eleicao.substr(3,2));
    int ano_eleicao = stoi(data_eleicao.substr(6,4));

    int idade = 0;
    if (mes_eleicao > mes_cand || (mes_eleicao == mes_cand  && dia_eleicao >= dia_cand)) {
        idade = ano_eleicao - ano_cand;
    }else {
     idade = ano_eleicao - ano_cand - 1;
    }
    
    setIdade(idade);
}


void Candidato::print() const {
    cout << this->nome << " / " <<  this->nomeUrna << " (" << this->siglaPartido <<", " << this->votosNominais << " votos)";
}

void Candidato::println() const {
    this->print();
    cout << endl;
}



Candidato::~Candidato(){
}
