#include <iostream>
using namespace std;

int main()
{
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg = 0, tatavg = 0;

    cout << "Enter the number of processes --- ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        p[i] = i;
        cout << "Enter the Burst Time & Priority of Process " << i << " --- ";
        cin >> bt[i] >> pri[i];
    }

    for (i = 0; i < n; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (pri[i] > pri[k])
            {
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    cout << "\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME" << endl;
    for (i = 0; i < n; i++)
        cout << p[i] << "\t\t" << pri[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;

    cout << "\nAverage Waiting Time is --- " << wtavg / n << endl;
    cout << "Average Turnaround Time is --- " << tatavg / n << endl;

    return 0;
}

// Enter the number of processes --- 5
// Enter the Burst Time & Priority of Process 0 --- 10 4
// Enter the Burst Time & Priority of Process 1 --- 3 1
// Enter the Burst Time & Priority of Process 2 --- 7 5
// Enter the Burst Time & Priority of Process 4 --- 9 3

// PROCESS         PRIORITY        BURST TIME      WAITING TIME    TURNAROUND TIME
// 1               1               3               0               3
// 3               2               2               3               5
// 4               3               9               5               14
// 0               4               10              14              24
// 2               5               7               24              31

// Average Waiting Time is --- 9.2
// Average Turnaround Time is --- 15.4