import java.util.Locale;
import java.util.Scanner;

public class Testador {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        scan.useLocale(Locale.ENGLISH);

        Integer qtd = scan.nextInt();

        for(Integer i = 0; i < qtd; i++){
            String nome = scan.next();
            Double nota1 = scan.nextDouble();
            Double nota2 = scan.nextDouble();
            Double nota3 = scan.nextDouble();

            Aluno aluno = new Aluno(nome, nota1, nota2, nota3);

            System.out.print(aluno.getNome()+",");
            System.out.printf("%s,", String.format(Locale.ROOT, "%.1f", aluno.notaMedia()));
            System.out.print(aluno.situacao(aluno.notaMedia())+",");
            System.out.println(aluno.media(aluno.notaMedia()));
        }


    }
}
