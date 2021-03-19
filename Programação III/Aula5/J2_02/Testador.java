public class Testador {
    public static void main(String[] args) {
        for(int i = 0; i < 5; i++){
            Aleatorio numAleatorio = new Aleatorio();
            System.out.print(numAleatorio.getNumber() + " ");
            numAleatorio.renovar();
            System.out.print(numAleatorio.getNumber() + " ");
        }
    }
}
