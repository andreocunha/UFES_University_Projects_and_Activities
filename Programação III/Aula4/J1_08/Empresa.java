import java.util.ArrayList;

public class Empresa {
    private String nome;
    private String cnpj;
    ArrayList<Departamento> departamentos = new ArrayList();


    public void setNome(String nome){
        this.nome = nome;
    }

    public void setCNPJ(String cnpj){
        this.cnpj = cnpj;
    }

    public void setDepartamento(Departamento departamento){
        this.departamentos.add(departamento);
    }

    public Departamento removeDepartamento(int posicao){
        return this.departamentos.remove(posicao); 
    }

    public String getNome(){
        return this.nome;
    }

    public String getCNPJ(){
        return this.cnpj;
    }

    public int getQtdDepartamentos(){
        return this.departamentos.size();
    }

    public Departamento getDepartamento(int posicao){
        return this.departamentos.get(posicao);
    }
}
