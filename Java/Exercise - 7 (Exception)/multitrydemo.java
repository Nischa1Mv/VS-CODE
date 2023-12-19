class multitrydemo {
    public static void main(String args[]) {
        try {
            int a = 10, b = 5;
            int c = a / b;
            int d[] = { 0, 1 };
            System.out.println(d[10]);
            System.out.println(c);
        } catch (ArithmeticException e) {
            System.out.println(e);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e);
        }
        System.out.println("After the catch statement");
    }
}
// Output:java.lang.ArrayIndexOutOfBoundsException:Index 10 out of bounds for
// length 2
// After the catch statement