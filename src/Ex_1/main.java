package Ex_1;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static Ex_1.Parabola.middleSegment2;
import static Ex_1.Parabola.lenghtSegment2;

public class main {

    public static List<Parabola> parabList = new ArrayList<>();

    public static void main(String[] args) throws FileNotFoundException {
        readFile();
        for (Parabola par : parabList) {
            Punct p = new Punct(par.getX(), par.getY());
            System.out.println(par + "\tVarf: " + p);
        }
        System.out.println("Parabola 0 si 1:\nMijlocul segmentului: " + middleSegment2(parabList.get(0), parabList.get(1)) + "\nLungimea segmentului: " + lenghtSegment2(parabList.get(0), parabList.get(1)));
        System.out.println("Parabola 2 si 3:\nMijlocul segmentului: " + parabList.get(2).middleSegment(parabList.get(3)) + "\nLungimea segmentului: " + parabList.get(2).lenghtSegment(parabList.get(3)));

    }

    public static void readFile() throws FileNotFoundException {
        String fileName = "src/Ex_1/in.txt";
        Scanner input = new Scanner(new File(fileName));
        while (input.hasNextLine()) {
            int a = input.nextInt();
            int b = input.nextInt();
            int c = input.nextInt();
            Parabola p = new Parabola(a, b, c);
            parabList.add(p);
        }
    }
}
