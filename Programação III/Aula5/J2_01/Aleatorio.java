import java.util.Random;
import java.util.Scanner;

public class Aleatorio {
    private int numero;
    static int VALOR_MAXIMO_DEFAULT = 100;
    private static Random rand;

    static {
        Scanner scan = new Scanner(System.in);
        Long entrada = 0L;
        entrada = scan.nextLong();
        rand = new Random(entrada);
        scan.close();
    }

    public Aleatorio() {
        this(VALOR_MAXIMO_DEFAULT);
    }

    public Aleatorio(int max) {
        numero = rand.nextInt(max);
    }

    public int getNumber(){
        return this.numero;
    }
}
