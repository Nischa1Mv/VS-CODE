import java.util.*;

class mergedemo {
    public static void main(String args[]) {
        int n1, n2, i, j, k;
        int a[] = new int[20];
        int b[] = new int[20];
        int c[] = new int[20];
        Scanner s = new Scanner(System.in);
        System.out.println("Enter number of elements in first array:");
        n1 = s.nextInt();
        System.out.println("Enter sorted elements of first array:");
        for (i = 0; i < n1; i++)
            a[i] = s.nextInt();
        System.out.println("Enter number of elements in second array:");
        n2 = s.nextInt();
        System.out.println("Enter sorted elements of second array:");
        for (j = 0; j < n2; j++)
            b[j] = s.nextInt();
        i = 0;
        j = 0;
        k = 0;
        while ((i < n1) && (j < n2)) {
            if (a[i] > b[j])
                c[k++] = b[j++];
            else
                c[k++] = a[i++];
        }
        while (i < n1)
            c[k++] = a[i++];
        while (j < n2)
            c[k++] = b[j++];
        System.out.println("After merging the elements are:\n");
        for (i = 0; i < (n1 + n2); i++)
            System.out.print("\t" + c[i]);
    }
}
// Output:
// Enter number of elements in first array:
// 6
// Enter elements of first array:
// 8 9 12 13 15 18
// Enter number of elements in second array:
// 5
// Enter elements of second array:
// 6 7 10 11 20
// After merging the elements are:
// 6 7 8 9 10 11 12 13 15 18 20