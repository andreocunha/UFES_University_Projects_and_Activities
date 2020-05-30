#ifndef MIDIA_
#define MIDIA_

//Tipo midia (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementação do TAD
typedef struct midia Midia;


/*Aloca uma Midia vazia
*inputs: vazio;
*outputs: retorna uma Midia vazia, alocada
* pre-condicao: nenhuma
* pos-condicao: retorna uma Midia vazia, alocada
*/
Midia* AlocaMidia();

/*Imprime midia
*inputs: uma midia
* pre-condicao: uma midia ja alocada
* pos-condicao: nenhuma
*/
void ImprimeMidia(Midia* midia);

/*Cria uma nova midia
*inputs: varios dados que compoe uma midia
* pre-condicao: uma midia alocada e varios ponteiros de char, inteiro e float
* pos-condicao: Cria uma nova midia no sistema
*/
void CriaMidia(Midia* midia, char* nome, char* artista,char* artista2,
                char* compositor,char* compositor2, char* compositor3, 
                char* genero, char* produtora,  int tipo, float duracao, 
                int qtdArtista, int qtdCompositor);

/*Edita o nome da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: Edita o nome da midia
*/
void EditaNomeMidia(Midia *midia, char* nome);

/*Edita o nome de um artista da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: Edita o nome de um artista da midia
*/
void EditaArtista1(Midia *midia, char* nomeArtista);

/*Edita o nome de um artista da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: Edita o nome de um artista da midia
*/
void EditaArtista2(Midia *midia, char* nomeArtista);

/*Edita o nome um compositor da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: Edita o nome de um compositor da midia
*/
void EditaCompositor1(Midia *midia, char* nomeCompositor);

/*Edita o nome um compositor da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: Edita o nome de um compositor da midia
*/
void EditaCompositor2(Midia *midia, char* nomeCompositor);

/*Edita o nome um compositor da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: Edita o nome de um compositor da midia
*/
void EditaCompositor3(Midia *midia, char* compositor);

/*Edita o nome do genero da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: Edita o nome de genero da midia
*/
void EditaNomeGenero(Midia *midia, char* genero);

/*Edita o tipo da midia
*inputs: uma midia e um tipo
* pre-condicao: midia e um inteiro
* pos-condicao: Edita o tipo da midia
*/
void EditaTipo(Midia *midia, int tipo);

/*Edita a duracao da midia
*inputs: uma midia e um float
* pre-condicao: midia alocada
* pos-condicao: Edita a duracao da midia
*/
void EditaDuracao(Midia *midia, float duracao);

/*Edita o nome do produtor da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: Edita o nome do produtor da midia
*/
void EditaNomeProdutora(Midia *midia, char* produtora);

/*Apaga uma midia do programa
*inputs: uma midia
* pre-condicao: uma midia alocada
* pos-condicao: apaga a midia
*/
void DeletaMidiaPrograma(Midia *midia);

/*Pesquisa o nome da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: nenhuma
*/
void PesquisaMidia(Midia *midia, char* nome);

/*Pesquisa um artista da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: nenhuma
*/
void PesquisaArtistaMidia(Midia *midia, char* nomeA);

/*Pesquisa um compositor da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: nenhuma
*/
void PesquisarNomeCompositorMidia(Midia *midia, char* nomeC);

/*Pesquisa um genero da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: nenhuma
*/
void PesquisarGeneroMidia(Midia *midia, char* nomeG);

/*Pesquisa um produtor da midia
*inputs: uma midia e um nome;
* pre-condicao: midia e ponteiro de char alocados
* pos-condicao: nenhuma
*/
void PesquisarProdutoraMidia(Midia *midia, char* nomeP);

/*Retorna a quantidade de artistas
*inputs: uma midia e um nome;
* pre-condicao: midia alocada
* pos-condicao: retorna uma quantidade de artistas
*/
int RetornaQtdArtista(Midia *midia);

/*Retorna a quantidade de compositores
*inputs: uma midia e um nome;
* pre-condicao: midia alocada
* pos-condicao: retorna uma quantidade de compositores
*/
int RetornaQtdCompositor(Midia *midia);

/*Salva dados no arquivo.txt
*inputs: um arquivo e uma midia
* pre-condicao: uma midia alocada e um arquivo
* pos-condicao: nenhuma
*/
void salvaDadosArquivoMidia(FILE *arquivo, Midia *midia);

#endif