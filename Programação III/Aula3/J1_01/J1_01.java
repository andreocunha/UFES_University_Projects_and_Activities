
public class J1_01 {
    public static void main(String[] args) {
        double s1 = 0, s2 = 0, s3 = 0;
        double numerador = 1;

        for(int i=1, j=50; i <= 50; i++, j--){
            s1 = s1 + (numerador/i);
            numerador += 2;

            s2 = s2 + (Math.pow(2, i))/j;

            if(i <= 10){
                if((i%2) == 0){
                    s3 = s3 - (i/(Math.pow(i, 2)));
                }
                else{
                    s3 = s3 + (i/(Math.pow(i, 2)));
                }
            }
        }

        System.out.println("S1 = "+s1);
        System.out.println("S2 = "+s2);
        System.out.println("S3 = "+s3);
    }
}
