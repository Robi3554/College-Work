package Ex_5;

import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random r = new Random();
        int low = 0;
        int high = 20;
        int nr = r.nextInt(high - low) + low;
        System.out.println("Numarul ales aleatoriu: " + nr);
        int a = 1;
        int b = 1;
        int c;
        boolean esteTermen = false;
        if(nr == 1){
            esteTermen = true;
            System.out.println("Numarul apartine de sirul ui Fibonacci");
        }
        do{
            c = a + b;
            a = b;
            b = c;
            if(nr == c){
                esteTermen = true;
                System.out.println("Numarul apartine de sirul ui Fibonacci");
                break;
            }
        }while(c <= nr);
        if(esteTermen == false){
            System.out.println("Numarul NU apartine de sirul ui Fibonacci");
        }
    }
}
