package Ex_3;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Introduceti un numar: ");
        int nr = scanner.nextInt();
        int counter = 0;
        for(int d = 1; d <= nr; d++) {
            if (nr % d == 0) {
                System.out.print(d + " ");
                counter++;
            }
        }
        if(counter < 3)
            System.out.print("\nNumarul introdus este prim!");
        scanner.close();
    }
}
