import java.util.Formatter;

public class Quadrado extends Quadrilatero {
    Formatter fmt = new Formatter();

    public Quadrado(Double lado){
        super(lado, lado);
    }

    @Override
    public String toString(){
        return "Quadrado de lado " + this.getBase() + fmt.format(" - perimetro: %.2f; area: %.2f.", this.getPerimetro(), this.getArea());
    }
}
