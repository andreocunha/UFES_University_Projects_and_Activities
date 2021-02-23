import java.util.Scanner;

public class J1_10 {
    public static void main(String[] args) {
        int num=0, numAnterior=0, numPosterior=1, temp=0;

        Scanner scan = new Scanner(System.in);

        num = scan.nextInt();
        scan.close();
        
        for(int i = 0; i < num && num <= 47; i++){
            if(i == 0 || i == 1){
                System.out.print(i+" ");
            }
            else{
                temp = numPosterior;
                numPosterior = numPosterior + numAnterior;
                numAnterior = temp;
                System.out.print(numPosterior+" ");
            }
        }
    }
}
