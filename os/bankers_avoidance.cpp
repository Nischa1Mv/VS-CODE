#include <iostream>
using namespace std;

struct File
{
    int allocation[10];
    int max[10];
    int need[10];
    int flag;
};

int main()
{
    File f[10];
    int fl;
    int i, j, k, p, b, n, r, g, cnt = 0, id, newr;
    int avail[10], seq[10];

    cout << "Enter number of processes -- ";
    cin >> n;

    cout << "Enter number of resources -- ";
    cin >> r;

    for (i = 0; i < n; i++)
    {
        cout << "Enter details for P" << i << endl;
        cout << "Enter allocation\t -- \t";
        for (j = 0; j < r; j++)
            cin >> f[i].allocation[j];

        cout << "Enter Max\t\t -- \t";
        for (j = 0; j < r; j++)
            cin >> f[i].max[j];

        f[i].flag = 0;
    }

    cout << "\nEnter Available Resources\t -- \t";
    for (i = 0; i < r; i++)
        cin >> avail[i];

    cout << "\nEnter New Request Details -- " << endl;
    cout << "\nEnter pid \t -- \t";
    cin >> id;

    cout << "Enter Request for Resources \t -- \t";
    for (i = 0; i < r; i++)
    {
        cin >> newr;
        f[id].allocation[i] += newr;
        avail[i] = avail[i] - newr;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            f[i].need[j] = f[i].max[j] - f[i].allocation[j];
            if (f[i].need[j] < 0)
                f[i].need[j] = 0;
        }
    }

    cnt = 0;
    fl = 0;
    bool safe = true;

    while (cnt != n)
    {
        g = 0;
        for (j = 0; j < n; j++)
        {
            if (f[j].flag == 0)
            {
                b = 0;
                for (p = 0; p < r; p++)
                {
                    if (avail[p] >= f[j].need[p])
                        b = b + 1;
                    else
                        b = b - 1;
                }
                if (b == r)
                {
                    cout << "\nP" << j << " is visited";
                    seq[fl++] = j;
                    f[j].flag = 1;
                    for (k = 0; k < r; k++)
                        avail[k] = avail[k] + f[j].allocation[k];
                    cnt = cnt + 1;
                    cout << "(";
                    for (k = 0; k < r; k++)
                        cout << avail[k] << " ";
                    cout << ")";
                    g = 1;
                }
            }
        }
        if (g == 0)
        {
            cout << "\n REQUEST NOT GRANTED -- DEADLOCK OCCURRED";
            cout << "\n SYSTEM IS IN UNSAFE STATE";
            safe = false;
            break;
        }
    }

    if (safe)
    {
        cout << "\nSYSTEM IS IN SAFE STATE";
        cout << "\nThe Safe Sequence is -- (";
        for (i = 0; i < fl; i++)
            cout << "P" << seq[i] << " ";
        cout << ")";
    }

    cout << "\nProcess\t\tAllocation\t\tMax\t\t\tNeed\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << i << "\t";
        for (j = 0; j < r; j++)
            cout << f[i].allocation[j] << "  "
                 << "   ";

        for (j = 0; j < r; j++)
            cout << f[i].max[j] << "  "
                 << "   ";

        for (j = 0; j < r; j++)
            cout << f[i].need[j] << "  "
                 << "   ";

        cout << "\n";
    }

    return 0;
}

// Enter number of processes -- 3
// Enter number of resources -- 4
// Enter details for P0
// Enter allocation         --     1 2 2 1
// Enter Max                --     3 3 2 2
// Enter details for P1
// Enter allocation         --     1 0 3 3
// Enter Max                --     2 1 3 4
// Enter details for P2
// Enter allocation         --     1 3 5 0
// Enter Max                --     3 4 5 6

// Enter Available Resources        --     1 0 2 1

// Enter New Request Details --

// Enter pid        --     1
// Enter Request for Resources      --     0 2 1 1

//  REQUEST NOT GRANTED -- DEADLOCK OCCURRED
//  SYSTEM IS IN UNSAFE STATE
// Process         Allocation              Max                     Need
// P0      1     2     2     1     3     3     2     2     2     1     0     1
// P1      1     2     4     4     2     1     3     4     1     0     0     0
// P2      1     3     5     0     3     4     5     6     2     1     0     6