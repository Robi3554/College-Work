package Ex_1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Latime = ");
        float lat = scanner.nextFloat();
        System.out.print("Lungime = ");
        float lun = scanner.nextFloat();

        Dreptunghi drept = new Dreptunghi(lat, lun);
        float aria = drept.aria(lat, lun);
        float perimetru = drept.perimetru(lat, lun);
        System.out.print("Aria = " + aria);
        System.out.print("\nPerimetru = " + perimetru);
    }
}
