import java.util.Locale;
import java.util.Scanner;

public class Testador {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        scan.useLocale(Locale.ENGLISH);

        Ponto[] pontos = new Ponto[3];
        Triangulo triagulo = new Triangulo();

        for(int i = 0; i < 3; i++){
            double x = scan.nextDouble();
            double y = scan.nextDouble();
            pontos[i] = new Ponto();
            pontos[i].setPoint(x, y);
        }

        triagulo.setPoints(pontos);
        System.out.printf(Locale.ENGLISH, "%.5f", triagulo.getPerimetro());

    }
}
