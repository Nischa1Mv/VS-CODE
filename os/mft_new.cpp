#include <iostream>
using namespace std;

int main()
{
    int ms, bs, nob, ef, n, mp[10], tif = 0;
    int i, p = 0;

    cout << "Enter the total memory available (in Bytes) -- ";
    cin >> ms;

    cout << "Enter the block size (in Bytes) -- ";
    cin >> bs;

    nob = ms / bs;

    cout << "\nEnter the number of processes -- ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter memory required for process " << i + 1 << " (in Bytes)-- ";
        cin >> mp[i];
    }

    cout << "\nNo. of Blocks available in memory -- " << nob;
    cout << "\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION";

    for (i = 0; i < n && p < nob; i++)
    {
        cout << "\n"
             << i + 1 << "\t\t" << mp[i];
        if (mp[i] > bs)
            cout << "\t\tNO\t\t---";
        else
        {
            cout << "\t\tYES\t" << bs - mp[i];
            tif = tif + bs - mp[i];
            p++;
        }
    }

    if (i < n)
        cout << "\nMemory is Full, Remaining Processes cannot be accommodated";

    cout << "\n\nTotal Internal Fragmentation is " << tif;

    return 0;
}

// Enter the total memory available (in Bytes) -- 500
// Enter the block size (in Bytes) -- 100

// Enter the number of processes -- 7
// Enter memory required for process 1 (in Bytes)-- 75
// Enter memory required for process 2 (in Bytes)-- 56
// Enter memory required for process 3 (in Bytes)-- 102
// Enter memory required for process 4 (in Bytes)-- 78
// Enter memory required for process 5 (in Bytes)-- 29
// Enter memory required for process 6 (in Bytes)-- 79
// Enter memory required for process 7 (in Bytes)-- 90

// No. of Blocks available in memory -- 5

// PROCESS MEMORY REQUIRED ALLOCATED       INTERNAL FRAGMENTATION
// 1               75              YES     25
// 2               56              YES     44
// 3               102             NO              ---
// 4               78              YES     22
// 5               29              YES     71
// 6               79              YES     21
// Memory is Full, Remaining Processes cannot be accommodated

// Total Internal Fragmentation is 183