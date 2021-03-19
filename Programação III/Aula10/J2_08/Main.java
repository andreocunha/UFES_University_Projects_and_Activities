import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scan = new Scanner(new FileReader(args[0]));

        Integer qtd = scan.nextInt();
        scan.nextLine();
        String linha[] = new String[4];

        for(Integer i = 0; i < qtd; i++){
            linha = scan.nextLine().split(",");
            
            if(linha[0].equals("R")){
                Poligono poligono = new Retangulo(Double.parseDouble(linha[1]), Double.parseDouble(linha[2]));
                System.out.println(poligono);
            }
            else if(linha[0].equals("Q")){
                Poligono poligono = new Quadrado(Double.parseDouble(linha[1]));
                System.out.println(poligono);
            }
            else if(linha[0].equals("C")){
                Poligono poligono = new Circulo(Double.parseDouble(linha[1]));
                System.out.println(poligono);
            }
        }

        scan.close();
    }
}
