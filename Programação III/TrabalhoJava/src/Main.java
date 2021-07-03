import java.io.*;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

    private static final String SEPARACAO = ",";

    public static void main(String[] args) {

        try {
            Scanner reader = new Scanner(new FileReader(args[0]));
            String linha = null;
            LinkedList<Candidato> candidatos = new LinkedList<Candidato>();
            Eleicao eleicao = new Eleicao();

            linha = reader.nextLine(); // le a primeira linha com o cabecalho
            while (reader.hasNextLine()) { // le todos os candidatos
                linha = reader.nextLine();
                String[] dadosCandidato = linha.split(SEPARACAO);

                Candidato candidato = new Candidato(dadosCandidato);
                if("Válido".equals(candidato.getDestinoVoto())){
                    candidatos.add(candidato); 
                }  
            }
            reader.close();
            Collections.sort(candidatos); //ordena a lista de candidatos

            try{
                eleicao.setCandidatosEleitos(candidatos, args[2]);
            }catch(Exception e){
                System.out.println("Erro ao ler a data");
                System.exit(1);
            }
            eleicao.setCandidatosMaisVotados(candidatos);

            try {
                reader = new Scanner(new FileReader(args[1]));
                linha = null;
                LinkedList<Partido> partidos = new LinkedList<Partido>();
        
                linha = reader.nextLine();
                while (reader.hasNextLine()) { // le todos os partidos
                    linha = reader.nextLine();
                    String[] dadosPartido = linha.split(SEPARACAO);
        
                    Partido partido = new Partido(dadosPartido);
                    partido.setCandidatosPartido(candidatos);
        
                    partidos.add(partido);  // adiciona o partido criado na lista de partidos      
                }
        
                reader.close();
                Collections.sort(partidos); // ordena a lista de partidos
                eleicao.setPartidos(partidos);
                
                Collections.sort(partidos, new ComparaPartidoNumeroVotoCandidato());
                eleicao.setPartidosPrimUlt(partidos);
                eleicao.filtroVotosNominaisPartido(partidos);
    
                System.out.println("Número de vagas: "+eleicao.getNumVagas()+"\n");
                eleicao.imprimeCandidatosEleitos();
                eleicao.imprimeCandidatosMaisVotados();
                eleicao.imprimeEleitosMajoritario();
                eleicao.imprimeEleitosQueSeBeneficiaram();
                eleicao.imprimeVotacaoPartidos();
                eleicao.imprimePartidosPrimUlt();
                eleicao.imprimePorFaixaEtaria();
                eleicao.imprimePorSexo();
                eleicao.imprimeVotosTotais();
                
            }catch( Exception e) {
                System.out.println("Erro na leitura do arquivo do partido.");
                System.exit(1);
            }
        } catch( Exception e){
            System.out.println("Erro na leitura do arquivo do candidato.");
            System.exit(1);
        }
    }
}