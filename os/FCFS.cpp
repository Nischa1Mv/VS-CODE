#include <iostream>
using namespace std;

int main()
{
    int p;

    // read no of process
    cout << "enter the no of process : " << endl;
    cin >> p;

    int bt[p], wt[p], tat[p + 1];
    double ta = 0, wat = 0;

    // read burst time
    cout << "enter the burst time in sequence:" << endl;

    for (int i = 0; i < p; i++)
    {
        cin >> bt[i];
    }

    cout << " PID \t BT \t TAT \t WT" << endl;
    tat[0] = 0;

    for (int i = 0; i < p; i++)
    {
        // calculating tat
        tat[i + 1] = tat[i] + bt[i];

        // calcukation waiting time
        wt[i] = tat[i] - 0;

        cout << i + 1 << "\t" << bt[i] << "\t" << tat[i + 1] << "\t" << wt[i] << endl;

        // total tat
        ta += tat[i + 1];

        // total wat
        wat += wt[i];
    }

    cout << "Average Turn Around Time = " << ta / p << endl;

    cout << "Average Waiting Time = " << wat / p << endl;

    return 0;
}

// enter the no of process :
// 3
// enter the burst time in sequence:
// 24 3 3
//  PID     BT      TAT     WT
// 1       24      24      0
// 2       3       27      24
// 3       3       30      27
// Average Turn Around Time = 27
// Average Waiting Time = 17