package prac7;

class Prac7iii {
    public static void main(String[] args) {
        try {
            int a = 8, b = 4, c;
            c = a / b;
            System.out.println(c);
            int[] arr = { 2, 5, 6, 7, 7 };
            System.out.println(arr[9]);
            String str = null;
            System.out.println(str.toLowerCase());
        } catch (ArithmeticException e) {
            System.out.println(e);
        } catch (NullPointerException e) {
            System.out.println(e);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e);
        }
        
        System.out.println("program executed succesfully");
    }
}
