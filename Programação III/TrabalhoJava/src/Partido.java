import java.util.Comparator;
import java.util.LinkedList;

public class Partido implements Comparable<Partido> {
    private String numeroPartido;
    private String votosLegenda;
    private String nomePartido;
    private String siglaPartido;
    private LinkedList<Candidato> candidatosPartido;
    private Integer votosNominais = 0;

    public Integer getVotosNominais()
    {
        return this.votosNominais ;
    }

    public void setVotosNominais(Integer votosNominais)
    {
        this.votosNominais = votosNominais ;
    }

    private Integer votosTotais = 0;
    private Integer candidatosEleitos=0;

	public Integer getVotosTotais() {
		return this.votosTotais; 
	}

    public Partido(String[] partido){
        setNumeroPartido(partido[0]);
        setVotosLegenda(partido[1]);
        setNomePartido(partido[2]);    
        setSiglaPartido(partido[3]);
    }

    public String getNumeroPartido() {
        return this.numeroPartido;
    }

    public void setNumeroPartido(String numeroPartido) {
        this.numeroPartido = numeroPartido;
    }

    public String getVotosLegenda() {
        return this.votosLegenda;
    }

    public void setVotosLegenda(String votosLegenda) {
        this.votosLegenda = votosLegenda;
    }

    public String getNomePartido() {
        return this.nomePartido;
    }

    public void setNomePartido(String nomePartido) {
        this.nomePartido = nomePartido;
    }

    public String getSiglaPartido() {
        return this.siglaPartido;
    }

    public void setSiglaPartido(String siglaPartido) {
        this.siglaPartido = siglaPartido;
    }

    public LinkedList<Candidato> getCandidatosPartido() {
        return this.candidatosPartido;
    }

    public void setCandidatosPartido(LinkedList<Candidato> candidatos) {
        this.candidatosPartido = new LinkedList<Candidato>();

        for(Candidato candidato: candidatos){
            if(this.numeroPartido.equals(candidato.getNumeroPartido())){                              
                candidatosPartido.add(candidato);
                candidato.setSiglaPartido(this.siglaPartido);

                if("Válido".equals(candidato.getDestinoVoto())){
                    this.votosNominais += Integer.parseInt(candidato.getVotosNominais());
                }

                if("Eleito".equals(candidato.getSituacao())){                              
                    this.candidatosEleitos++;
                }
			}
        }
        this.votosTotais = this.votosNominais+ Integer.parseInt((this.votosLegenda));
    }

    



    @Override
    public String toString() {
        String candidato = " candidato eleito";
        String nominal = " nominal ";
        String voto = " voto ";
        if(this.candidatosEleitos > 1){
            candidato = " candidatos eleitos";
        }
        if(this.votosNominais > 1){
            nominal = " nominais ";
        }
        if(this.votosTotais > 1){
            voto = " votos ";
        }

        return this.siglaPartido + " - " + this.numeroPartido + ", " + this.votosTotais + voto + "(" + this.votosNominais + nominal + "e "+ this.votosLegenda+ " de legenda), "  + this.candidatosEleitos + candidato;
    }

    public void imprimePartidoPrimUlt(){
        Candidato candidatoPrim =  this.candidatosPartido.getFirst();
        Candidato candidatoUlt =  this.candidatosPartido.getLast();
        Integer votoprim = Integer.parseInt(candidatoPrim.getVotosNominais());
        Integer votoult = Integer.parseInt(candidatoUlt.getVotosNominais());

        System.out.println(this.siglaPartido + " - " + this.numeroPartido + ", " + candidatoPrim.getNomeUrna() + " (" + candidatoPrim.getNumero() + ", " + candidatoPrim.getVotosNominais() + ( votoprim>1 ? " votos)" : " voto)") + " / " + candidatoUlt.getNomeUrna() + " (" + candidatoUlt.getNumero() + ", " + candidatoUlt.getVotosNominais() +   ( votoult>1 ? " votos)" : " voto)"));
        
    }


    @Override 
    public int compareTo(Partido outroPartido) { 
        if (this.votosTotais > outroPartido.getVotosTotais() ) { 
            return -1; 
        } if (this.votosTotais < outroPartido.getVotosTotais()) { 
            return 1; 
        } 
        return 0; 
    }
}

class ComparaPartidoNumeroVotoCandidato implements Comparator<Partido> {

    public int compare(Partido part1, Partido part2){
        LinkedList<Candidato> listaCandidatodPart1 = part1.getCandidatosPartido();
        LinkedList<Candidato> listaCandidatodPart2 = part2.getCandidatosPartido();

        if(listaCandidatodPart1.size() < 1 ){
            return 1;
        } if (listaCandidatodPart2.size() < 1){
            return -1;
        }
        Candidato candidatoPart1 = listaCandidatodPart1.getFirst();
        Candidato candidatoPart2 = listaCandidatodPart2.getFirst();  

        Integer votosCandidatoPart1 = Integer.parseInt(candidatoPart1.getVotosNominais());
        Integer votosCandidatoPart2 = Integer.parseInt(candidatoPart2.getVotosNominais());

        if (votosCandidatoPart1 > votosCandidatoPart2) { 
            return -1; 
        } if (votosCandidatoPart1 < votosCandidatoPart2) { 
            return 1; 
        } 
        
        Integer numeroPartidarioCandidatoPart1 = Integer.parseInt(candidatoPart1.getNumeroPartido());
        Integer numeroPartidarioCandidatoPart2 = Integer.parseInt(candidatoPart2.getNumeroPartido());
        
        return numeroPartidarioCandidatoPart1.compareTo(numeroPartidarioCandidatoPart2);
    }
}
