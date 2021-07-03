import java.util.Date;
import java.util.LinkedList;
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;

public class Eleicao {
    private LinkedList<Candidato> candidatosEleitos;
    private LinkedList<Candidato> candidatosMaisVotados;
	private LinkedList<Partido> partidos;
	private LinkedList<Partido> partidosPrimUlt;
	private Integer[] idades = {0, 0, 0, 0, 0};
	private Integer[] sexos = {0, 0}; 
	private Integer numVagas = 0;
	private Integer votosNominais = 0;
	private Integer votosLegenda = 0;
 

	public Integer getNumVagas() {
		return this.numVagas;
	}

	public LinkedList<Candidato> getCandidatosEleitos() {
		return this.candidatosEleitos;
	}

	public void setCandidatosEleitos(LinkedList<Candidato> candidatos, String data) {
		this.candidatosEleitos = new LinkedList<Candidato>();

		SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy"); 
		Date dataEleicao = null;
		try {
			dataEleicao = formato.parse(data);
			
		}catch(Exception e){
			System.out.println(e);
		}
        
        for(Candidato candidato: candidatos){
            if("Eleito".equals(candidato.getSituacao())){                              
                candidatosEleitos.add(candidato);
				this.numVagas++;
				
				Integer idade = candidato.getIdade(dataEleicao);

				String sexo = candidato.getSexo();
				if("M".equals(sexo)){
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

	public LinkedList<Candidato> getCandidatosMaisVotados() {
		return this.candidatosMaisVotados;
	}

	public void setCandidatosMaisVotados(LinkedList<Candidato> candidatos) {
		this.candidatosMaisVotados = new LinkedList<Candidato>();

		Integer i = 0;
		
		for(Candidato candidato: candidatos){
            candidatosMaisVotados.add(candidato);
			i++;

			if("Válido".equals(candidato.getDestinoVoto())){
				this.votosNominais += Integer.parseInt(candidato.getVotosNominais());
			}
        }
	}

	public LinkedList<Partido> getPartidos() {
		return this.partidos;
	}

	public void setPartidos(LinkedList<Partido> partidos) {
		this.partidos = new LinkedList<Partido>();
		this.partidos.addAll(partidos);
	}

	public LinkedList<Partido> getPartidosPrimUlt() {
		return this.partidosPrimUlt;
	}

	public void setPartidosPrimUlt(LinkedList<Partido> partidos) {
		this.partidosPrimUlt = new LinkedList<Partido>();
		this.partidosPrimUlt.addAll(partidos);
	}

    public void imprimeCandidatosEleitos(){
		System.out.println("Vereadores eleitos:");
		Integer i = 1;
        for(Candidato candidato: this.candidatosEleitos){
			System.out.print(i + " - ");
            System.out.println(candidato);
			i++;
        }
	}

    public void imprimeCandidatosMaisVotados(){
		System.out.println("\nCandidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):");
        Integer i = 1;
		if(this.numVagas == 0){
			return;
		}
		for(Candidato candidato: this.candidatosMaisVotados){
			System.out.print(i + " - ");
            System.out.println(candidato);
			i++;

			if(i > this.numVagas){
				break;
			}
        }
	}

	public void imprimeEleitosMajoritario(){
		Integer i = 1;
		Integer contador=0;
		System.out.println("\nTeriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)");
		for(Candidato candidato: this.candidatosMaisVotados){
			Integer existe=0;
			
			for(Candidato candidatoEleito: this.candidatosEleitos){
				if(candidato.comparaCandidatoNome(candidatoEleito)==1){
					existe = 1;	
					contador++;
				}
			}
			if((existe==0 ) &&( contador < this.numVagas)){
			 System.out.print(i + " - ");
             System.out.println(candidato);
			 contador++;
			}
			existe=0;
			i++;
        }
	}


    public void imprimeEleitosQueSeBeneficiaram(){
		Integer i=1;
		System.out.println("\nEleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)");
		for(Candidato candidato: this.candidatosMaisVotados){
			if(i > this.numVagas){
				if("Eleito".equals(candidato.getSituacao())){            
					System.out.print(i + " - ");              
					System.out.println(candidato);
				}
			}
			i++;
        }
	}


	public void imprimeVotacaoPartidos(){
		Integer i = 1;
		System.out.println("\nVotação dos partidos e número de candidatos eleitos:");
		for(Partido partido: this.partidos){
			System.out.print(i + " - ");   
			System.out.println(partido);
			i++;


			this.votosLegenda += Integer.parseInt(partido.getVotosLegenda());
        }
	}

	public void imprimePartidosPrimUlt(){
		Integer i = 1;
		System.out.println("\nPrimeiro e último colocados de cada partido:");
		for(Partido partido: this.partidosPrimUlt){
			if(partido.getVotosTotais() != 0){
				System.out.print(i + " - ");   
				partido.imprimePartidoPrimUlt();
				i++;
			}
        }
	}

	public void filtroVotosNominaisPartido(LinkedList<Partido> partidos){
		LinkedList<Partido> nova = new LinkedList<Partido>();
    
		for(Partido partido: partidos){
			if(partido.getVotosNominais() > 0){
				nova.add(partido);
			}
		}

		 this.setPartidosPrimUlt(nova); 	
	}



	private String calculaPorcentagem(Integer quant){
		Float result = (quant.floatValue()/this.numVagas.floatValue())* 100;
		return new DecimalFormat("#,##0.00").format(result);
	}

	public void imprimePorFaixaEtaria(){
		String porcentagem = "0.00";
		System.out.println("\nEleitos, por faixa etária (na data da eleição):");

		porcentagem = calculaPorcentagem(this.idades[0]);
		System.out.println("      Idade < 30: " + idades[0] +" ("+ porcentagem +"%)");

		porcentagem = calculaPorcentagem(this.idades[1]);
		System.out.println("30 <= Idade < 40: " + idades[1] +" ("+ porcentagem +"%)");

		porcentagem = calculaPorcentagem(this.idades[2]);
		System.out.println("40 <= Idade < 50: " + idades[2] +" ("+ porcentagem +"%)");

		porcentagem = calculaPorcentagem(this.idades[3]);
		System.out.println("50 <= Idade < 60: " + idades[3] +" ("+ porcentagem +"%)");

		porcentagem = calculaPorcentagem(this.idades[4]);
		System.out.println("60 <= Idade     : " + idades[4] +" ("+ porcentagem +"%)");
	}

	public void imprimePorSexo(){
		String porcentagem = "0.00";
		System.out.println("\nEleitos, por sexo:");

		porcentagem = calculaPorcentagem(this.sexos[1]);
		System.out.println("Feminino:  " + sexos[1] +" ("+ porcentagem +"%)");

		porcentagem = calculaPorcentagem(this.sexos[0]);
		System.out.println("Masculino: " + sexos[0] +" ("+ porcentagem +"%)");
	}

	private String calculaPorcentagemTotal(Integer total, Integer valor){
		Float result = (valor.floatValue()/total.floatValue())* 100;
		return new DecimalFormat("#,##0.00").format(result);
	}

	public void imprimeVotosTotais(){
		Integer votosValidos = this.votosNominais + this.votosLegenda;
		String porcentagem = "0.00";

		System.out.println("\nTotal de votos válidos:    " + votosValidos);

		porcentagem = calculaPorcentagemTotal(votosValidos, this.votosNominais);
		System.out.println("Total de votos nominais:   " + this.votosNominais + " (" + porcentagem + "%)");
		
		porcentagem = calculaPorcentagemTotal(votosValidos, this.votosLegenda);
		System.out.println("Total de votos de Legenda: " + this.votosLegenda + " (" + porcentagem + "%)\n");
	}
}
