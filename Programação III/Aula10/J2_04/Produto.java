public class Produto {
    private String nome;
    private String preco;

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getPreco() {
        return this.preco;
    }

    public void setPreco(String preco) {
        this.preco = preco;
    }

    public Produto(String nome, String preco){
        setNome(nome);
        setPreco(preco);
    }

    
}
