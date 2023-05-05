package prac7;

public class prac7i {

    public static void main(String[] args) {

        try {
            int a = 9, b = 0, c;
            c = a / b;

        } catch (Exception e) {
            e.printStackTrace();
        }

        try {
            int[] a = { 2, 6, 8, 1, 3, 1, 7, 9 };
            System.out.println(a[9]);
        } catch (Exception e) {

            e.printStackTrace();
        }
        System.out.println("program executed succesfully");
    }
}

