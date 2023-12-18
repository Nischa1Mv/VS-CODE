class arithmeticdemo {
    public static void main(String args[]) {
        try {
            int a = 10, b = 0;
            int c = a / b;
            System.out.println(c);
        } catch (ArithmeticException e) {
            System.out.println(e);
        }
    }
}
// Output:java.lang.ArithmeticException:/

// by zero