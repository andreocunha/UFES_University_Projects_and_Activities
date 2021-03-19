public class Aluno {
    private String nome;
    private Double nota1;
    private Double nota2;
    private Double nota3;

    public Aluno(String nome, Double nota1, Double nota2, Double nota3){
        setNome(nome);
        setNota1(nota1);
        setNota2(nota2);
        setNota3(nota3);
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Double getNota1() {
        return this.nota1;
    }

    public void setNota1(Double nota1) {
        this.nota1 = nota1;
    }

    public Double getNota2() {
        return this.nota2;
    }

    public void setNota2(Double nota2) {
        this.nota2 = nota2;
    }

    public Double getNota3() {
        return this.nota3;
    }

    public void setNota3(Double nota3) {
        this.nota3 = nota3;
    }

    public Double notaMedia(){
        return (this.nota1 + this.nota2 + this.nota3)/3;
    }

    public String situacao(Double nota){
        if(nota >= 7.0){
            return "Aprovado";
        }
        return "Prova Final";
    }

    public String media(Double nota){
        if(nota > 7.0){
            return "Acima";
        }
        else if(nota < 7.0){
            return "Abaixo";
        }
        return "Na media";
    }

}
