// (iii) Third form of interface implementation
interface A
{
void display();
}
class B implements A
{
public void display()
{
System.out.println("This is in B's method");
}
}
class C implements A
{
public void display()
{
System.out.println("This is C's method");
}
}
class interfacedemo
{

public static void main(String args[])
{
B b1=new B();
C c1=new C();
b1.display();
c1.display();
}
}
// Output:
// This is in B's method
// This is C's method
