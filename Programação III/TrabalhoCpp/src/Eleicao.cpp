#include "Eleicao.h"
#include "NumberUtils.h"
using namespace std;

Eleicao::Eleicao() {
    this->votos_nominais = 0;
    this->votos_legenda = 0;

    for(int i = 0; i < 5; i++){
        idades[i] = 0; 
        if(i < 2)
        sexos[i] = 0;
    }

}

static bool compare_to_candidato_mais_votados(Candidato* first , Candidato* second){

    if (stoi(first->getVotosNominais()) > stoi(second->getVotosNominais())) { 
        return true; 
    } 
    else if(stoi(first->getVotosNominais()) < stoi(second->getVotosNominais())){ 
        return false;
    }
    else{
        return first->getIdade() > second->getIdade();
    }


}

void Eleicao::cria_lista_candidatos(list<Candidato*>& lista_candidatos){
    lista_candidatos.sort(compare_to_candidato_mais_votados);  
    this->lista_candidatos = lista_candidatos;
}


void Eleicao::cria_lista_candidatos_eleitos(const list<Candidato*>& lista_candidatos){
    for (auto& candidato : lista_candidatos){
        if(candidato->candidato_eleito()){
            this->lista_candidatos_eleitos.push_back(candidato);
            this->num_vagas++;

            int idade = calcula_idade(candidato->getDataNasc() , "15/11/2020");
            string sexo = candidato->getSexo();
            if("M" == sexo){
                sexos[0]++;
            }
            else{
                sexos[1]++;
            }

            if(idade < 30){
                idades[0]++;
            }
            else if(idade >= 30 && idade < 40){
                idades[1]++;
            }
            else if(idade >= 40 && idade < 50){
                idades[2]++;
            }
            else if(idade >= 50 && idade< 60){
                idades[3]++;
            }
            else {
                idades[4]++;
            }
        }
    }
}
//Essa função não tem retorno e recebe um ponteiro para uma lista de candidatos
//tem o objetivo de criar a lista de candidatos mais votados 
void Eleicao::cria_lista_candidatos_mais_votados(const list<Candidato*>& lista_candidatos){
    for (auto& candidato : lista_candidatos){
        this->lista_candidatos_mais_votados.push_back(candidato);

        string destino_voto = candidato->getDestinoVoto();
        if(destino_voto.compare("Válido") == 0){   //
            this->votos_nominais += stoi(candidato->getVotosNominais());
        }
    }
}

 void Eleicao::imprime_lista_candidatos_eleitos_beneficiaram(){
    cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
     int i = 1;
     for (auto& candidato : this->lista_candidatos_mais_votados){
         if(i > this->num_vagas){
            string situacao = candidato->getSituacao();
            if(situacao.compare("Eleito") == 0){
                cout << i << " - ";
                candidato->println();
            }
         }
         i++;
     }
     cout << endl;
 }


void Eleicao::imprime_lista_candidatos_eleitos(){
    cout << "Número de vagas: " << this->num_vagas << endl << endl;
    cout << "Vereadores eleitos:" << endl;

    int i = 1;
    for (auto& candidato : this->lista_candidatos_eleitos){
        cout << i << " - ";
        candidato->println();
        i++;
    }
    cout << endl;
}

void Eleicao::imprime_lista_candidatos_mais_votados(){
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    int i = 1;
    for (auto& candidato : this->lista_candidatos_mais_votados){
        if(i > this->num_vagas){
            break;
        }
        cout << i << " - ";
        candidato->println();
        i++;
    }
    cout << endl;
}


void Eleicao::imprime_lista_candidatos_mais_votados_nao_eleitos(){
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    int i = 1, j = 1;
    for (auto& candidato : this->lista_candidatos_mais_votados){
        if(i > this->num_vagas){
            break;
        }
        string situacao = candidato->getSituacao();
        if(situacao.compare("Eleito")  != 0){
            cout << j << " - ";
            candidato->println();
        }
        j++;
        i++;
    }
    cout << endl;
} 


void Eleicao::cria_lista_partidos(const list<Partido*>& lista_partidos) {
    this->lista_partidos = lista_partidos;
}


static bool ordena_partidos(Partido* first , Partido* second){
    if (first->get_votos_totais() > second->get_votos_totais()) { 
        return true; 
    } 
    else { 
        return false;
    }
}


static bool ordena_partidos_prim_ult(Partido* first , Partido* second){

    if(first->get_numero_candidatos_partido() < 1){
        // cout << "aqui 1 ----------------------------------" << endl;
        return true;
    } 
    else if(second->get_numero_candidatos_partido() < 1){
        // cout << "aqui 2 ----------------------------------" << endl;
        return false;
    }

    Candidato* candidato_prim = first->get_primeiro_candidato(); 
    Candidato* candidato_sec = second->get_primeiro_candidato();
    
    int votos_first = stoi(candidato_prim->getVotosNominais());
    int votos_second = stoi(candidato_sec->getVotosNominais());

    if (votos_first > votos_second){ 
        return true;
    } 
    if(votos_first < votos_second){ 
        return false;
    }
    
    return (stoi(candidato_prim->getNumeroPartido()) < stoi(candidato_sec->getNumeroPartido())); 
 }

void Eleicao::imprime_lista_partidos(){
     cout << "Votação dos partidos e número de candidatos eleitos:" << endl;
     this->lista_partidos.sort(ordena_partidos);
     int i = 1;
     for (auto& partido: this->lista_partidos){
        cout << i << " - ";
        partido->println();
        this->votos_legenda += stoi(partido->get_votos_legenda());
        i++;
    } 
    cout << endl;
}


void Eleicao::imprime_lista_partidos_prim_ult(){
    this->lista_partidos.sort(ordena_partidos_prim_ult);
   
    cout << "Primeiro e último colocados de cada partido:" << endl;
    int i = 1;
    for (auto& partido: this->lista_partidos){
        if(partido->get_votos_totais() != 0){
            cout << i << " - ";
            partido->imprime_partido_prim_ult();
            i++;
        }
    } 
    cout << endl;
}

double Eleicao::calcula_porcentagem(int quant){
    double result = (quant*1.0/this->num_vagas)* 100;
    return result;
}

int Eleicao::calcula_idade(const string& data_cand , const string& data_eleicao){
    int dia_cand = stoi(data_cand.substr(0,2));
    int mes_cand = stoi(data_cand.substr(3,2));
    int ano_cand = stoi(data_cand.substr(6,4));

    int dia_eleicao = stoi(data_eleicao.substr(0,2));
    int mes_eleicao = stoi(data_eleicao.substr(3,2));
    int ano_eleicao = stoi(data_eleicao.substr(6,4));

    int idade;
    if (mes_eleicao > mes_cand || (mes_eleicao == mes_cand  && dia_eleicao >= dia_cand)) {
        idade = ano_eleicao - ano_cand;
    }else {
     idade = ano_eleicao - ano_cand - 1;
    }
    return idade;

}


void Eleicao::imprime_por_faixa_etaria(){
    double porcentagem = 0.00;

    cout << "Eleitos, por faixa etária (na data da eleição):" << endl;

    porcentagem = calcula_porcentagem(this->idades[0]);
    cout << "      Idade < 30: " << idades[0] << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%)" << endl;

    porcentagem = calcula_porcentagem(this->idades[1]);
    cout << "30 <= Idade < 40: " << idades[1] << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%)" << endl;

    porcentagem = calcula_porcentagem(this->idades[2]);
    cout << "40 <= Idade < 50: " << idades[2] << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%)" << endl;

    porcentagem = calcula_porcentagem(this->idades[3]);
    cout << "50 <= Idade < 60: " << idades[3] << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%)" << endl;

    porcentagem = calcula_porcentagem(this->idades[4]);
    cout << "60 <= Idade     : " << idades[4] << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%)\n" << endl;

}

void Eleicao::imprime_por_sexo(){
    double porcentagem = 0.00;

    cout << "Eleitos, por sexo:" << endl;

    porcentagem = calcula_porcentagem(this->sexos[1]);
    cout << "Feminino:  " << sexos[1] << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%)" << endl;

    porcentagem = calcula_porcentagem(this->sexos[0]);
    cout << "Masculino: " << sexos[0] << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%)\n" << endl;

}


void Eleicao::imprime_votos_totais(){
    double porcentagem = 0.00;

    int votos_totais = this->votos_legenda + this->votos_nominais;
    
    cout << "Total de votos válidos:    " << votos_totais << endl;

    porcentagem = (this->votos_nominais*1.0/votos_totais)* 100;
    cout << "Total de votos nominais:   " << this->votos_nominais << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%)" << endl;

    porcentagem = (this->votos_legenda*1.0/votos_totais)* 100;
    cout << "Total de votos de Legenda: " << this->votos_legenda << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%)\n" << endl;

}




Eleicao::~Eleicao(){
    for (auto& candidato : this->lista_candidatos){
        delete candidato;
    }

    for (auto& partido : this->lista_partidos){
        delete partido;
    }
}