// (i) First form of interface implementation
interface A {
    void display();
}

class B implements A {
    public void display() {
        System.out.println("B's method");
    }
}

class C extends B {
    public void callme() {
        System.out.println("C's method");
    }
}

class interfacedemo1 {
    public static void main(String args[]) {
        C c1 = new C();
        c1.display();
        c1.callme();
    }
}
// Output:
// B's method
// C's method