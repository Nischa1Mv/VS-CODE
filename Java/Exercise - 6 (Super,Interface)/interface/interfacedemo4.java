// (iv) Fourth form of interface implementation
interface A {
    void display();
}

interface B {
    void callme();
}

interface C extends A, B {
    void call();
}

class D implements C {
    public void display() {
        System.out.println("interface A");
    }

    public void callme() {
        System.out.println("interface B");
    }

    public void call() {
        System.out.println("interface C");
    }
}

class interfacedemo {
    public static void main(String args[]) {
        D d1 = new D();
        d1.display();
        d1.callme();
        d1.call();
    }
}
// Output:
// interface A
// interface B
// interface C