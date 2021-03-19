import java.util.Formatter;

public class Cd extends Produto {
    private String numFaixas;
    Formatter fmt = new Formatter();

    public String getNumFaixas() {
        return this.numFaixas;
    }

    public void setNumFaixas(String numFaixas) {
        this.numFaixas = numFaixas;
    }

    public Cd (String nome, String preco, String numFaixas){
        super(nome, preco);
        setNumFaixas(numFaixas);
    }

    @Override
    public String toString(){
        return super.getNome() + " (R$ " + fmt.format("%.2f", Double.parseDouble(super.getPreco())) + ") - " + this.numFaixas + " faixas"; 
    }

}
