class stringbounddemo {
    public static void main(String args[]) {

        try {

            String a = "This is like chipping ";
            char c = a.charAt(24);
            System.out.println(c);
        } catch (StringIndexOutOfBoundsException e) {
            System.out.println(e);
        }
    }
}
// Output:
// java.lang.StringIndexOutOfBoundsException: Index 24 out of bounds for length
// 22
