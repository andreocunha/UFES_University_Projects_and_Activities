#include "LeituraCSV.h"

using namespace std;

const vector<string> explode(const string &s, const char &c)
{
    string buff{""};
    vector<string> v;

    for (auto n : s)
    {
        if (n != c)
            buff += n;
        else if (n == c && buff != "")
        {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "")
        v.push_back(buff);

    return v;
}

void ler_candidatos(list<Candidato *> &lista_candidatos, const string& nome_arq, const string& data)
{
    ifstream cand(nome_arq); //leitura candidato
    string linha = "";

    if (cand.is_open())
    {
        getline(cand, linha);
        while (getline(cand, linha))
        {
            vector<string> v{explode(linha, ',')};
            Candidato *candidato = new Candidato(v);
            string destino_voto = candidato->getDestinoVoto();

            if (destino_voto.compare("Válido") == 0)
            { 
                candidato->calcula_idade_e_armazena(candidato->getDataNasc(), data);
                lista_candidatos.push_back(candidato);
            }
            else {
                delete candidato;
            }
        }
        cand.close();
    }
    else
    {
        throw runtime_error("Não foi possível abrir o arquivo do candidato");
    }
}

void ler_partidos(list<Partido *> &lista_partidos, list<Candidato *> &lista_candidatos, const string& nome_arq)
{
    ifstream part(nome_arq); //leitura partido
    string linha = "";

    if (part.is_open())
    {
        getline(part, linha);
        while (getline(part, linha))
        {
            vector<string> vetor{explode(linha, ',')};

            Partido *partido = new Partido(vetor);

            partido->set_candidatos_do_partido(lista_candidatos);
            lista_partidos.push_back(partido);
        }
        part.close();
    }
    else
    {
        throw runtime_error("Não foi possível abrir o arquivo de partido");
    }
}
