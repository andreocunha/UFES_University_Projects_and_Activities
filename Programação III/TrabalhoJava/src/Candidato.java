import java.util.Calendar;
import java.util.Date;
import java.text.SimpleDateFormat;

public class Candidato implements Comparable<Candidato> {
    private String nome;
    private String numero;
    private String votosNominais;
    private String situacao;
    private String nomeUrna;
    private String sexo;
    private Date dataNasc;
    private String destinoVoto;
    private String numeroPartido;
    private String siglaPartido;

    public Candidato(String[] dadosCandidato ){
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



    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNumero() {
        return this.numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public String getVotosNominais() {
        return this.votosNominais;
    }

    public void setVotosNominais(String votosNominais) {
        this.votosNominais = votosNominais;
    }

    public String getSituacao() {
        return this.situacao;
    }

    public void setSituacao(String situacao) {
        this.situacao = situacao;
    }

    public String getNomeUrna() {
        return this.nomeUrna;
    }

    public void setNomeUrna(String nomeUrna) {
        this.nomeUrna = nomeUrna;
    }

    public String getSexo() {
        return this.sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public Date getDataNasc() {
        return this.dataNasc;
    }

    public Integer getIdade(Date dataHoje) {
        Calendar dataNascimento = Calendar.getInstance();  
        dataNascimento.setTime(this.dataNasc); 
        Calendar hoje = Calendar.getInstance();  
        hoje.setTime(dataHoje); 

        int idade = hoje.get(Calendar.YEAR) - dataNascimento.get(Calendar.YEAR); 

        if (hoje.get(Calendar.MONTH) < dataNascimento.get(Calendar.MONTH)) {
        idade--;  
        } 
        else 
        { 
            if (hoje.get(Calendar.MONTH) == dataNascimento.get(Calendar.MONTH) && hoje.get(Calendar.DAY_OF_MONTH) < dataNascimento.get(Calendar.DAY_OF_MONTH)) {
                idade--; 
            }
        }

        return idade;
    }

    public void setDataNasc(String dataNasc) {
        SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy"); 
        try {
            Date data = formato.parse(dataNasc);
            this.dataNasc = data;
        }catch(Exception e){
            System.out.println(e);
        }
        
    }

    public String getDestinoVoto() {
        return this.destinoVoto;
    }

    public void setDestinoVoto(String destinoVoto) {
        this.destinoVoto = destinoVoto;
    }

    public String getNumeroPartido() {
        return this.numeroPartido;
    }

    public void setNumeroPartido(String numeroPartido) {
        this.numeroPartido = numeroPartido;
    }

    public String getSiglaPartido() {
        return this.siglaPartido;
    }

    public void setSiglaPartido(String siglaPartido) {
        this.siglaPartido = siglaPartido;
    }

    public int comparaCandidatoNome(Candidato candidato){
        if(this.nome == candidato.nome){
            return 1;
        }else{
            return 0;
        }
    }


    @Override 
    public int compareTo(Candidato outroCandidato) { 
        if (Integer.parseInt(this.votosNominais) > Integer.parseInt(outroCandidato.votosNominais)) { 
            return -1; 
        } if (Integer.parseInt(this.votosNominais) < Integer.parseInt(outroCandidato.votosNominais)) { 
            return 1; 
        } 
        return this.dataNasc.compareTo(outroCandidato.getDataNasc());
    }

    @Override
    public String toString() {
        return this.nome + " / " + this.nomeUrna + " (" + this.siglaPartido + ", "+ this.votosNominais + ( Integer.parseInt(this.votosNominais)>1 ? " votos)" : " voto)");
    }

    public void imprimeCandidato(){
        System.out.println("Numero: " + this.numero);
        System.out.println("Votos_nominais: " + this.votosNominais);
        System.out.println("Situacao: " + this.dataNasc);
        System.out.println("Nome: " + this.nome);
        System.out.println("Nome_urna: " + this.nomeUrna);
        System.out.println("Sexo: " + this.sexo);
        System.out.println("Data_nasc: " + this.dataNasc);
        System.out.println("Destino_voto: " + this.destinoVoto);
        System.out.println("Numero_partido: " + this.numeroPartido);
        System.out.println("--------------------------");    
    }

    
}
