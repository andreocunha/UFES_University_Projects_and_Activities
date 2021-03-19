import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scan = new Scanner(new FileReader(args[0]));

        Integer qtd = scan.nextInt();
        scan.nextLine();
        String linha[] = new String[4];

        Produto produtos[] = new Produto[qtd];

        for(Integer i = 0; i < qtd; i++){
            linha = scan.nextLine().split(",");
            if(linha[0].equals("L")){
                Produto produto = new Livro(linha[1], linha[2], linha[3]);
                produtos[i] = produto;
            }
            else if(linha[0].equals("C")){
                Produto produto = new Cd(linha[1], linha[2], linha[3]);
                produtos[i] = produto;
            }
            else if(linha[0].equals("D")){
                Produto produto = new Dvd(linha[1], linha[2], linha[3]);
                produtos[i] = produto;
            }
        }

        Arrays.sort(produtos);

        for(Produto produto: produtos){
            System.out.println(produto);
        }

        scan.close();
    }
}
