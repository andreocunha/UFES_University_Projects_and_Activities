public class Testador {
    public static void main(String[] args) {
        Aleatorio[] numAleatorios = new Aleatorio[10];

        for(int i = 0; i < 10; i++){
            numAleatorios[i] = new Aleatorio();
        }
        
        for(int i = 0; i < 10; i++){
            System.out.print(numAleatorios[i].getNumber() + " ");
        }
    }
}
