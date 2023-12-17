#include <iostream>
using namespace std;

int main()
{
    int ms, mp[10], i, temp, n = 0;
    char ch = 'y';

    cout << "\nEnter the total memory available (in Bytes)-- ";
    cin >> ms;

    temp = ms;

    for (i = 0; ch == 'y'; i++, n++)
    {
        cout << "\nEnter memory required for process " << i + 1 << " (in Bytes) -- ";
        cin >> mp[i];

        if (mp[i] <= temp)
        {
            cout << "\nMemory is allocated for Process " << i + 1;
            temp = temp - mp[i];
        }
        else
        {
            cout << "\nMemory is Full";
            break;
        }

        cout << "\nDo you want to continue(y/n) -- ";
        cin >> ch;
    }

    cout << "\n\nTotal Memory Available -- " << ms;
    cout << "\n\n\tPROCESS\t\t MEMORY ALLOCATED ";

    for (i = 0; i < n; i++)
        cout << "\n \t" << i + 1 << "\t\t" << mp[i];

    cout << "\n\nTotal Memory Allocated is " << ms - temp;
    cout << "\nTotal External Fragmentation is " << temp;

    return 0;
}

// Enter the total memory available (in Bytes)-- 500

// Enter memory required for process 1 (in Bytes) -- 150

// Memory is allocated for Process 1
// Do you want to continue(y/n) -- y

// Enter memory required for process 2 (in Bytes) -- 320

// Memory is allocated for Process 2
// Do you want to continue(y/n) -- y

// Enter memory required for process 3 (in Bytes) -- 50

// Memory is Full

// Total Memory Available -- 500

//         PROCESS          MEMORY ALLOCATED
//         1               150
//         2               320

// Total Memory Allocated is 470
// Total External Fragmentation is 30