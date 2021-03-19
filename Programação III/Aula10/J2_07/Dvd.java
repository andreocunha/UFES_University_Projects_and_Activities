import java.util.Formatter;

public class Dvd extends Produto {
    private String duracao;
    Formatter fmt = new Formatter();

    public String getDuracao() {
        return this.duracao;
    }

    public void setDuracao(String duracao) {
        this.duracao = duracao;
    }

    public Dvd (String nome, String preco, String duracao){
        super(nome, preco);
        setDuracao(duracao);
    }

    @Override
    public String toString(){
        return super.getNome() + " (R$ " + fmt.format("%.2f", Double.parseDouble(super.getPreco())) + ") - " + this.duracao + " minutos"; 
    }
}
