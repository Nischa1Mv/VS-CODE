#include <iostream>
using namespace std;

int main()
{
    int p;

    // read no of process
    cout << "Enter the number of processes: " << endl;
    cin >> p;

    int bt[p], wt[p], tat[p + 1];
    double tatavg, wtavg = 0;

    // read burst time
    int pid[p];
    cout << "Enter the burst time in sequence:" << endl;

    for (int i = 0; i < p; i++)
    {
        pid[i] = i;
        cin >> bt[i];
    }

    // sorting the burst and pid
    for (int i = 0; i < p - 1; i++)
    {
        for (int k = i + 1; k < p; k++)
        {
            if (bt[i] > bt[k])
            {
                swap(bt[i], bt[k]);
                swap(pid[i], pid[k]);
            }
        }
    }
    wt[0] = 0;
    tat[0] = tatavg = bt[0];

    for (int i = 1; i < p; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    cout << "\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n";
    for (int i = 0; i < p; i++)
        cout << "\n\t P" << pid[i] << "\t\t " << bt[i] << "\t\t " << wt[i] << "\t\t " << tat[i];
    cout << "\nAverage Waiting Time -- " << wtavg / p;
    cout << "\nAverage Turnaround Time -- " << tatavg / p;

    return 0;
}

// Enter the number of processes:
// 5
// Enter the burst time in sequence:
// 10
// 3 7 2 9

//          PROCESS        BURST TIME       WAITING TIME    TURNAROUND TIME

//          P3              2               0               2
//          P1              3               2               5
//          P2              7               5               12
//          P4              9               12              21
//          P0              10              21              31
// Average Waiting Time -- 8
// Average Turnaround Time -- 14.2