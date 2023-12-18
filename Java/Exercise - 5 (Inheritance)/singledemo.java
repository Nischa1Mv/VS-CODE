class A
{
A()
{
    System.out.println("Inside A's Constructor");
}
}
class B extends A
{
B()
{
    System.out.println("Inside B's Constructor");
}
}
class singledemo
{
public static void main(String args[])
{
B b1=new B();
}
}
// Output:
// Inside A's Constructor
// Inside B's Constructor