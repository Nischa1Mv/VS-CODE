package Java.Threadexp;

class class1 extends Thread {
    public void run() {
        System.out.println("Java");
    }
}

class threadexp extends Thread {
    public void run() {
        System.out.println("vignan");
    }

    public static void main(String[] args) {

        class1 a = new class1();
        a.start();
        threadexp b = new threadexp();
        b.start();
        System.out.println(b.isAlive());
    }
}
