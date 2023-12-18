class trydemo {
    public static void main(String args[]) {
        try {
            int a = 10, b = 0;
            int c = a / b;
            System.out.println(c);
        } catch (ArithmeticException e) {
            System.out.println(e);
        }
        System.out.println("After the catch statement");
    }
}
// Output:
// java.lang.ArithmeticException: / by zero
// After the catch statement