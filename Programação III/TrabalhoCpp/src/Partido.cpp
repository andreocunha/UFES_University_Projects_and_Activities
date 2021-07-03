#include "Partido.h"

Partido::Partido(const vector<string>& dados_partido) {
    set_numero_partido(dados_partido[0]);
    set_votos_legenda(dados_partido[1]);
    set_nome_partido(dados_partido[2]);    
    set_sigla_partido(dados_partido[3]);
    this->votos_totais=0;
    this->votos_nominais=0;
    this->candidatos_eleitos=0;
}

void Partido::println() const {

    string candidato = " candidato eleito";
    string nominal = " nominal ";
    string voto = " voto ";
    if(this->candidatos_eleitos > 1){
        candidato = " candidatos eleitos";
    }
    if(this->votos_nominais > 1){
        nominal = " nominais ";
    }
    if(this->votos_totais > 1){
        voto = " votos ";
    }

    cout << this->sigla_partido << " - " <<  this->numero_partido << ", " << this->votos_totais << voto << "(" << this->votos_nominais << nominal << "e " << this->votos_legenda  << " de legenda), " << this->candidatos_eleitos << candidato << endl;
}

void Partido::imprime_partido_prim_ult(){
    Candidato* candidato_prim = this->lista_candidatos_partido.front();
    Candidato* candidato_ult = this->lista_candidatos_partido.back();
    int votoprim = stoi(candidato_prim->getVotosNominais());
    int votoult = stoi(candidato_ult->getVotosNominais());


  
   cout << this->sigla_partido << " - " << this->numero_partido << ", " << candidato_prim->getNomeUrna() << " (" << candidato_prim->getNumero() << ", " << candidato_prim->getVotosNominais() << ( votoprim>1 ? " votos)" : " voto)") << " / " + candidato_ult->getNomeUrna() << " (" << candidato_ult->getNumero() << ", " + candidato_ult->getVotosNominais() << ( votoult>1 ? " votos)" : " voto)") << endl;
}


void Partido::set_candidatos_do_partido(const list<Candidato*>& lista_candidatos) {
    string valido = "Válido";
    string eleito = "Eleito";

    for(auto candidato: lista_candidatos){
        if(this->numero_partido.compare(candidato->getNumeroPartido()) == 0){    

            this->lista_candidatos_partido.push_back(candidato);
 
            candidato->setSiglaPartido(this->sigla_partido);

            if(valido.compare(candidato->getDestinoVoto()) == 0){
               this->votos_nominais += stoi(candidato->getVotosNominais());
            }

            if(eleito.compare(candidato->getSituacao()) == 0){                              
                this->candidatos_eleitos++;
            }
        }
    }
    this->votos_totais = this->votos_nominais + stoi(this->votos_legenda);
}




Partido::~Partido(){
}