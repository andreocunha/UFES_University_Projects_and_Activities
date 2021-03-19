import java.util.Scanner;

public class Testador {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        Cliente cliente = new Cliente();
        String valor = scan.nextLine();

        while(!valor.equals(String.valueOf('.'))){
            if(valor.equals(String.valueOf('+'))){
                if(cliente.getCpf() == null){
                    System.out.println(cliente.getNome());
                }
                else{
                    System.out.printf("%s %s\n", cliente.getNome(), cliente.getCpf());
                }
                
                cliente = new Cliente();
            }
            if(!valor.equals(String.valueOf('.')) && !valor.equals(String.valueOf('+'))){
                cliente.setCpf(valor);
            }
            valor = scan.nextLine();
        }
        if(cliente.getCpf() == null){
            System.out.println(cliente.getNome());
        }
        else{
            System.out.printf("%s %s\n", cliente.getNome(), cliente.getCpf());
        }


        scan.close();
    }
}
