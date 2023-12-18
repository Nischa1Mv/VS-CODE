class A {
    A() {
        System.out.println("Inside A's Constructor");
    }
}

class B extends A {
    B() {
        System.out.println("Inside B's Constructor");
    }
}

class C extends B {
    C() {
        System.out.println("Inside C's Constructor");
    }
}

class multidemo {
    public static void main(String args[]) {
        C c1 = new C();
    }
}
// Output:
// Inside A's Constructor
// Inside B's Constructor
// Inside C's Constructor