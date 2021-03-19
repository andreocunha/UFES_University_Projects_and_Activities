public class Funcionario {
    private String nome;
    private Double salario;
    private String admissao;


    public void setNome(String nome){
        this.nome = nome;
    }

    public void setSalario(Double salario){
        this.salario = salario;
    }

    public void setAdmissao(String admissao){
        this.admissao = admissao;
    }

    public String getNome(){
        return this.nome;
    }

    public Double getSalario(){
        return this.salario;
    }

    public String getAdmissao(){
        return this.admissao;
    }

    public void aumentarSalario(float percentual){
        this.salario = this.salario + this.salario*(percentual/100);
    }
}
