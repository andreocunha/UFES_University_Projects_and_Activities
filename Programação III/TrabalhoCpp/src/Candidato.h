#ifndef CANDIDATO_H_
#define CANDIDATO_H_

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Candidato {
  private:
	string nome;                     
	string numero;
    string votosNominais;
    string situacao;
    string nomeUrna;
    string sexo;
    string dataNasc;
    string destinoVoto;
    string numeroPartido;
    string siglaPartido;
    int idade;


  public:
    Candidato();
    Candidato(const vector<string>& dadosCandidato );

    void setNome(const string& nome) {        
        this->nome = nome;
    }

    void setNumero(const string& numero) {
        this->numero = numero;
    }

    void setIdade(int idade) {
        this->idade = idade;
    }

    int getIdade()const{
        return this->idade;
    }

    const string& getNumero() const{
        return this->numero;
    }

    void setVotosNominais(const string& votosNominais) {
        this->votosNominais = votosNominais;
    }

    const string& getVotosNominais()const{
        return this->votosNominais;
    }

    void setSituacao(const string& situacao) {
        this->situacao = situacao;
    }

    const string& getSituacao()const {
        return this->situacao; 
    }

    void setNomeUrna(const string& nomeUrna) {
        this->nomeUrna = nomeUrna;
    }

    const string& getNomeUrna()const {
        return this->nomeUrna;
    }

    void setSexo(const string& sexo) {
        this->sexo = sexo;
    }

    const string& getSexo() const{
        return this->sexo;
    }

    const string& getDataNasc()const {
        return this->dataNasc;
    }

    void setDataNasc(const string& data) {
        this->dataNasc = data;
    }

    void setDestinoVoto(const string& destinoVoto) {
        this->destinoVoto = destinoVoto;
    }

    const string& getDestinoVoto()const {
        return this->destinoVoto;
    }

    void setNumeroPartido(const string& numeroPartido) {
        this->numeroPartido = numeroPartido;
    }

    const string& getNumeroPartido()const {
        return this->numeroPartido;
    }

    void setSiglaPartido(const string& siglaPartido) {
        this->siglaPartido = siglaPartido;
    }

    //Essa função tem por objetivo comparar o se a situação do candidato é eleito
    //retorna true se sim
    bool candidato_eleito() const;


    //Essa função ira receber ums string data candiadto e uma string data eleição
    //não ira retornar nada
    //essa função ira calcular a idade do candidato usando as strings passadas e ira armazenar dentro do candidato
    void calcula_idade_e_armazena(const string& data_cand, const string& data_eleicao);

	void print() const;
	void println() const;

	~Candidato();
};

#endif