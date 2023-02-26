package Ex_2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.io.IOException;


public class Main {
    public static void main(String[] args) throws IOException {

        int i;
        List<Integer> list = new ArrayList<>();
        File file = new File("src/Ex_2/in.txt");
        BufferedReader reader = null;

        try {
            reader = new BufferedReader(new FileReader(file));
            String text;

            while ((text = reader.readLine()) != null) {
                list.add(Integer.parseInt(text));
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (reader != null) {
                    reader.close();
                }
            } catch (IOException e) {
            }
        }

        int max = list.get(0);
        for( i = 0; i < list.size();i++){
            if(max < list.get(i)){
                max = list.get(i);
            }
        }

        int min = list.get(0);
        for( i = 0; i < list.size(); i++){
            if(min > list.get(i)){
                min = list.get(i);
            }
        }

        float medie;
        float sum = 0;
        int counter = 0;
        for( i = 0; i < list.size(); i++){
            sum += list.get(i);
            counter++;
        }

        medie = sum/ counter;

        System.out.println(list);
        System.out.println("Maximul este: " + max);
        System.out.println("Minimul este: " + min);
        System.out.println("Suma este: " + sum);
        System.out.println("Media aritmetica este:" + medie);

        BufferedWriter writer = new BufferedWriter(new FileWriter("src/Ex_2/out.txt"));
        writer.write("Maximul: " + max);
        writer.write("\nMinimul: " + min);
        writer.write("\nSuma:" + sum);
        writer.write(("\nMedia aritmetica: " + medie));

        writer.close();
    }
}

