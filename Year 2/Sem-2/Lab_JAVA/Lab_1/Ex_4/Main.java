package Ex_4;

import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random r = new Random();
        int high = 30;
        int nr1 = r.nextInt(high);
        int nr2 = r.nextInt(high);

        System.out.print("Numarul 1: " + nr1);
        System.out.print("\nNumarul 2: " + nr2);

        while(nr1 != nr2){
            if(nr1 > nr2)
                nr1 -= nr2;
            else
                nr2 -=nr1;
        }
        System.out.print("\nCMMDC: " + nr1);
    }
}
