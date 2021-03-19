import java.util.Formatter;

public class Retangulo extends Quadrilatero {
    Formatter fmt = new Formatter();

    public Retangulo(Double base, Double altura){
        super(base, altura);
    }

    @Override
    public String toString(){
        return "Retangulo de base " + this.getBase() + " e altura " + this.getAltura() + fmt.format(" - perimetro: %.2f; area: %.2f.", this.getPerimetro(), this.getArea());
    }
}
