#include <iostream>
using namespace std;
int main()
{
    int ms, bs, tif = 0, n;

    // total memory input
    cout << "gib-memory";
    cin >> ms;

    // block size input
    cout << "gib-block size";
    cin >> bs;

    // finding no of blocks
    int nob = ms / bs;

    // finding external fragmentation
    int ef = ms - nob * bs;

    // no of the process
    cout << "enter the no process : ";
    cin >> n;
    int m[n];
    cout << "give the memory of the process : ";
    for (int i = 0; i < n; i++)
    {
        // memory of the process
        cin >> m[i];
    }
    int i = 0;
    while (i < n && nob-- >= 0)
    {
        if (m[i] > bs)
        {
            cout << " not allocated" << endl;
        }
        else
        {
            tif += (bs - m[i]);
        }
        i++;
    }
    if (n > nob)
    {
        cout << "memory is full,process cannot be allocated" << endl;
    }
    cout << "total internal fragmnetation =" << tif << endl;
    cout << "total external fragmnetation =" << ef << endl;

    return 0;
}
