class A extends Exception {
    A(String s1) {
        super(s1);
    }
}

class owndemo {
    public static void main(String args[]) {
        try {
            throw new A("demo ");
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
// Output:A:demo