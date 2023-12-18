class numberformatdemo {
    public static void main(String args[]) {
        try {
            int num = Integer.parseInt("akki");
            System.out.println(num);
        } catch (NumberFormatException e) {
            System.out.println(e);
        }
    }
}
// Output:java.lang.NumberFormatException:
// For input string:
// "akki