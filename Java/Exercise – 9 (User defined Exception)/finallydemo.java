class finallydemo {
    public static void main(String args[]) {
        try {
            int a = 10, b = 0;
            int c = a / b;
            System.out.println(c);
        } catch (ArithmeticException e) {
            System.out.println(e);

        } finally {
            System.out.println("This is inside finally block");
        }
    }
}
// java.lang.ArithmeticException: / by zero
// This is inside finally