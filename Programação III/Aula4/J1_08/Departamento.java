import java.util.ArrayList;

public class Departamento {
    private String nome;
    ArrayList<Funcionario> funcionarios = new ArrayList();

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setFuncionarios(Funcionario funcionario){
        this.funcionarios.add(funcionario);
    }

    public Funcionario removeFuncionario(int posicao){
        return this.funcionarios.remove(posicao); 
    }

    public String getNome(){
        return this.nome;
    }

    public int getQtdFuncionarios(){
        return this.funcionarios.size();
    }

    public Funcionario getFuncionario(int posicao){
        return this.funcionarios.get(posicao);
    }

    public Double somaDosSalarios(){
        Double soma = 0.0;
        for(int i = 0; i < this.funcionarios.size(); i++){
            soma = soma + this.getFuncionario(i).getSalario();
        }
        return soma;
    }
}
