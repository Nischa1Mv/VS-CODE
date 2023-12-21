#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number of elements" << endl;
    cin >> n;
    int *ptr = (int *)calloc(n, sizeof(int));
    if (!ptr)
    {
        cout << "memory not allocated" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cin >> ptr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << ptr[i];
        }
        free(ptr);
    }
}