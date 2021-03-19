public class Triangulo {
    Ponto[] pontos;

    public double getPerimetro(){
        double dist1, dist2, dist3;

        dist1 = Math.sqrt((Math.pow((pontos[0].getPointX() - pontos[1].getPointX()), 2) + Math.pow((pontos[0].getPointY() - pontos[1].getPointY()), 2)));
        dist2 = Math.sqrt((Math.pow((pontos[1].getPointX() - pontos[2].getPointX()), 2) + Math.pow((pontos[1].getPointY() - pontos[2].getPointY()), 2)));
        dist3 = Math.sqrt((Math.pow((pontos[2].getPointX() - pontos[0].getPointX()), 2) + Math.pow((pontos[2].getPointY() - pontos[0].getPointY()), 2)));

        return dist1 + dist2 + dist3;  
    }

    public void setPoints(Ponto[] pontos){
        this.pontos = pontos;
    }
}
