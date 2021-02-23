public class J1_02 {
    public static void main(String[] args) {
        int result = 0;

        for(int i = 1000; i<9999; i++){
            if(i == (Math.pow((i/100 + i%100), 2))){
                System.out.println(i);
            }
        }
    }
}
