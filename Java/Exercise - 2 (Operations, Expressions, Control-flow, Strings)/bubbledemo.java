import java.util.Scanner;
class bubbledemo
{
public static void main(String args[])
{
int n, i,j, temp;
int a[ ]=new int[20];
Scanner s = new Scanner(System.in);
System.out.println("Enter total number of elements:");
n = s.nextInt();
System.out.println("Enter elements:");
for (i = 0; i < n; i++)
a[i] = s.nextInt();
for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
System.out.println("The sorted elements are:");
for(i=0;i<n;i++)
System.out.print("\t"+a[i]);
}
}
// Output:
// Enter total number of elements:
// 10
// Enter elements:
// 3 2 5 7 6 8 9 1 4 0
// The sorted elements are:
// 0 1 2 3 4 5 6 7 8 9