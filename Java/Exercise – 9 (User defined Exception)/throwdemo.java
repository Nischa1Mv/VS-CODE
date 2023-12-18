class throwdemo {
    public static void main(String args[]) {
        try {
            throw new NullPointerException("demo");
        } catch (NullPointerException e) {
            System.out.println(e);
        }
    }
}
// Output:
// java.lang.NullPointerException: demo