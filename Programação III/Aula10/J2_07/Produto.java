public class Produto implements Comparable<Produto> {
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
    
    @Override
    public int compareTo(Produto produto) {
        if(Double.parseDouble(this.preco) < Double.parseDouble(produto.getPreco())){
            return 1;
        }else if(Double.parseDouble(this.preco) > Double.parseDouble(produto.getPreco())){
            return -1;
        }else{
            if(this.nome.compareToIgnoreCase(produto.getNome()) < 0){
                return -1;
            }else{
                return 1;
            }
        }
    }
}
