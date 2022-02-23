import java.util.Scanner;


public class Main {
    public static void main(String[] args){

        Scanner leitor = new Scanner(System.in);


        int a = leitor.nextInt(); //pimentões amarelos
        int b = leitor.nextInt(); //pimentões vermelhos

        //digite o seu código
        int X = a + b;
        System.out.println("X = " + X);
    }
}