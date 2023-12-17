#include <iostream>
using namespace std;

int main()
{
    int i, j, n, t, max;
    float awt = 0, att = 0, temp = 0;

    cout << "Enter the number of processes -- ";
    cin >> n;

    int bu[10], wa[10], tat[10], ct[10];

    for (i = 0; i < n; i++)
    {
        cout << "\nEnter Burst Time for process " << i + 1 << " -- ";
        cin >> bu[i];
        ct[i] = bu[i];
    }

    cout << "\nEnter the size of time slice -- ";
    cin >> t;

    max = bu[0];

    for (i = 1; i < n; i++)
        if (max < bu[i])
            max = bu[i];

    for (j = 0; j < (max / t) + 1; j++)
        for (i = 0; i < n; i++)
            if (bu[i] != 0)
                if (bu[i] <= t)
                {
                    tat[i] = temp + bu[i];
                    temp += bu[i];
                    bu[i] = 0;
                }
                else
                {
                    bu[i] -= t;
                    temp += t;
                }

    for (i = 0; i < n; i++)
    {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    cout << "\nThe Average Turnaround time is -- " << att / n << endl;
    cout << "The Average Waiting time is -- " << awt / n << endl;

    cout << "\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n";
    for (i = 0; i < n; i++)
        cout << "\t" << i + 1 << "\t" << ct[i] << "\t\t" << wa[i] << "\t\t" << tat[i] << endl;

    return 0;
}

// Enter the number of processes -- 5

// Enter Burst Time for process 1 -- 10

// Enter Burst Time for process 2 -- 5

// Enter Burst Time for process 3 -- 7

// Enter Burst Time for process 4 -- 2

// Enter Burst Time for process 5 -- 9

// Enter the size of time slice -- 3

// The Average Turnaround time is -- 24.8
// The Average Waiting time is -- 18.2
//         PROCESS  BURST TIME      WAITING TIME   TURNAROUND TIME
//         1       10              23              33
//         2       5               14              19
//         3       7               22              29
//         4       2               9               11
//         5       9               23              32