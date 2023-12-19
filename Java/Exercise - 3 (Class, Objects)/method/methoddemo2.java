// 2.no return type and with parameter-list:
class A {
    void display(int l, int b) {
        System.out.println(l);
        System.out.println(b);
    }
}

class methoddemo2 {
    public static void main(String args[]) {
        A a1 = new A();
        a1.display(10, 20);
    }
}
// Output:
// 10
// 20