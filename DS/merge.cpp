#include <iostream>
using namespace std;

void merge(int *arr, int l, int mid, int h)
{
    int i = l, j = mid + 1, k = 0;
    int a[h - l + 1];
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            a[k] = arr[i];
            i++, k++;
        }
        else
        {
            a[k] = arr[j];
            k++, j++;
        }
    }
    while (i <= mid)
    {
        a[k] = arr[i];
        k++, i++;
    }
    while (j <= h)
    {
        a[k] = arr[j];
        k++, j++;
    }
    for (int x = l; x < k; x++)
    {
        arr[l + x] = a[x];
    }
}
void mergesort(int *arr, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

int main()
{
    int arr[4] = {5, 7, 1, 3};
    mergesort(arr, 0, 3);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}