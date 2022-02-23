import java.util.Scanner;
import java.text.DecimalFormat;

public class DIO {

    public static void main(String[] args){
        Scanner leitor = new Scanner(System.in);
        double A = leitor.nextDouble();
        double B = leitor.nextDouble();
        //Escreva aqui a sua lógica

        double result = (B/A - 1.00) * 100;
        String valorResultFormatado = new DecimalFormat("##0.00").format(result);

        System.out.println(valorResultFormatado + "%");
    }

}