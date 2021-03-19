import java.util.Formatter;

public class Circulo implements Poligono {
    private Double raio;
    Formatter fmt = new Formatter();

    public Circulo(Double raio){
        setRaio(raio);
    }

    public Double getRaio() {
        return this.raio;
    }

    public void setRaio(Double raio) {
        this.raio = raio;
    }

    @Override
    public Double getArea() {
        return Math.PI * this.raio * this.raio;
    }

    @Override
    public Double getPerimetro() {
        return 2 * Math.PI * this.raio;
    }

    @Override
    public String toString(){
        return "Circulo de raio " + this.raio + fmt.format(" - perimetro: %.2f; area: %.2f.", this.getPerimetro(), this.getArea());
    }

}
