package prac7;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

class file {
    void read() throws FileNotFoundException {
        FileInputStream a = new FileInputStream("d:/abc.txt");

    }

}

public class Prac7iv {
    public static void main(String[] args) {

        file f = new file();
        try {

            f.read();
        } catch (Exception e) {

            System.out.println(e);
        }
    }
}

