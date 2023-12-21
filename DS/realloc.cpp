#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cout << "enter the value of n";
    cin >> n;
    int *ptr = (int *)malloc(n * sizeof(int));
    if (!ptr)
    {
        cout << "memory not alllocated" << endl;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            cin >> ptr[i];
        }
        for (i = 0; i < n; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
        int r;
        cin >> r;
        ptr = (int *)realloc(ptr, r * sizeof(int));
        cout << "new memmory : ";
        for (i = n; i < r; i++)
        {
            cin >> ptr[i];
        }
        for (i = 0; i < r; i++)
        {
            cout << ptr[i] << " ";
        }
        free(ptr);
    }
}