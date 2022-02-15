import java.io.IOException;
import java.util.Scanner;

public class main {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        int N;

        do {
            //System.out.println("Insira um número inteiro e maior que 0: ");
            N = scanner.nextInt();
        } while ( N <= 0);

        for(int i = 0; i <= N; i++){
            if(i % 2 == 0 && i != 0){
                System.out.println(i);
            }
        }
    }
}

