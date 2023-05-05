package prac7;

import java.util.Scanner;

class youngerage extends RuntimeException {

    youngerage(String msg) {
        super(msg);
    }

}

class Prac7v {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int age = sc.nextInt();
        try {

            if (age < 18) {
                throw new youngerage("not eligible");
            } else {
                System.out.println("eligible");
            }
        }

        catch (Exception e) {

            e.printStackTrace();
        }

        System.out.println("hello");

    }
}
