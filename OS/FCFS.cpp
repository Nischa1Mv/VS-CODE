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

        //calcukation waiting time
        wt[i] = tat[i] - 0;

        cout << i << "\t" << bt[i] << "\t" << tat[i + 1] << "\t" << wt[i] << endl;

        //total tat
        ta += tat[i + 1];

        //total wat
        wat += wt[i];

    }

    cout << "Average Turn Around Time = " << ta / p << endl;

    cout << "Average Waiting Time = " << wat / p << endl;

    return 0;
}
