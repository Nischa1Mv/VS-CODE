#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of n : ";
    cin >> n;
    int *ptr = (int *)malloc(n * sizeof(int));
    if (!ptr)
    {
        cout << "memory not allocated";
    }
    else
    {
        cout << "enter elements";
        for (int i = 0; i < n; i++)
        {
            cin >> ptr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << ptr[i] << " ";
        }

        free(ptr);
    }
}