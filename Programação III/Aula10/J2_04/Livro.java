import java.util.Formatter;

public class Livro extends Produto {
    private String autor;
    Formatter fmt = new Formatter();

    public String getAutor() {
        return this.autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public Livro (String nome, String preco, String autor){
        super(nome, preco);
        setAutor(autor);
    }

    @Override
    public String toString(){
        return super.getNome() + " (R$ " + fmt.format("%.2f", Double.parseDouble(super.getPreco())) + ") - " + this.autor; 
    }
}
