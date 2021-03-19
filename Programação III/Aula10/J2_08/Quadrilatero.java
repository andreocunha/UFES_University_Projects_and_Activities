public class Quadrilatero implements Poligono {
    private Double base;
    private Double altura;

    public Quadrilatero(Double base, Double altura){
        setBase(base);
        setAltura(altura);
    }

    public Double getBase() {
        return this.base;
    }

    public void setBase(Double base) {
        this.base = base;
    }

    public Double getAltura() {
        return this.altura;
    }

    public void setAltura(Double altura) {
        this.altura = altura;
    }

    @Override
    public Double getArea() {
        return base * altura;
    }

    @Override
    public Double getPerimetro() {
        return (2*base + 2*altura);
    }
}
