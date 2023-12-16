import java.util.*;
class class1 extends Thread {
    public void run() {
        System.out.println("Java");
    }
}

class class2 extends Thread {
    public void run() {
        System.out.println("vignan");
    }

    public static void main(String[] args) {

        class1 a = new class1();
        a.start();
        class2 b = new class2();
        b.start();
        System.out.println(b.isAlive());
    }
}
