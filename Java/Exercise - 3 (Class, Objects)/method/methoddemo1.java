// 1.no return type and without parameter-list:
class A {
    int l = 10, b = 20;

    void display() {
        System.out.println(l);
        System.out.println(b);
    }
}

class methoddemo1 {
    public static void main(String args[]) {
        A a1 = new A();
        a1.display();
    }
}
// Output:
// 10
// 20