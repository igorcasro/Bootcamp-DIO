import java.util.Scanner;

class Classe{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        //declare suas variaveis do tipo double
        double raio;
        double area;
        //continue a solucao
        raio = scan.nextDouble();

        area = 3.14159 * (Math.pow(raio,2));

        System.out.printf("A=%.4f\n", area);
    }
}