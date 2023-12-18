import java.io.*;

class filenotfounddemo {
    public static void main(String args[]) {
        try {
            File file = new File("E://file.txt");
            FileReader fr = new FileReader(file);
        } catch (FileNotFoundException e) {
            System.out.println(e);
        }
    }
}
// Output:java.io.FileNotFoundException:E:\file.txt(The system
// cannot find
// the file specified
// )