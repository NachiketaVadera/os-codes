import java.util.Scanner;

public class Fibonacci {

    public static int[] fiboArray = new int[50];

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter a number:");
        int number = input.nextInt();

        input.close();

        ThatRunsFiboThread[] objArray = new ThatRunsFiboThread[number];

        for (int i = 0; i < number; i++) {
            objArray[i] = new ThatRunsFiboThread(i);
            try {
                objArray[i].join();
            } catch (InterruptedException ie) {
                System.out.println(ie.getMessage());
            }
        }

        for (int i : fiboArray) {
            System.out.print(i + " ");
        }
    }
}

class ThatRunsFiboThread extends Thread {

    private int number;

    public ThatRunsFiboThread(int number) {
        this.number = number;
        new Thread(this, "seq_printer").start();
    }

    @Override
    public void run() {
        if(number == 0) {
            Fibonacci.fiboArray[number] = 0;
        } else if(number == 1) {
            Fibonacci.fiboArray[number] = 1;
        } else {
            Fibonacci.fiboArray[number] = Fibonacci.fiboArray[number - 1] + Fibonacci.fiboArray[number - 2];
        }
    }
}