#include <iostream>
using namespace std;
int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    while (i < j)
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void quicksort(int a[], int l, int h)
{
    if (l < h)
    {
        int p = partition(a, l, h);
        quicksort(a, l, p);
        quicksort(a, p + 1, h);
    }
}
int main()
{
    int arr[4] = {5, 7, 1, 3};
    quicksort(arr, 0, 3);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}