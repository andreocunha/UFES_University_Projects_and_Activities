import java.util.Scanner;

public class J1_03 {
    public static void main(String[] args) {
        int num1=0, num2=0;
        Scanner scan = new Scanner(System.in);

        num1 = scan.nextInt();
        num2 = scan.nextInt();

        while(num1 != num2){
            if(num1 > num2){
                num1 = num1 - num2;
            }
            else if(num2 > num1){
                num2 = num2 - num1;
            }
        }
        scan.close();
        System.out.println(num1);
    }
}
