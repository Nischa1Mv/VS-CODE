#include <iostream>
using namespace std;

int main()
{
    int allocated[15][15], max[15][15], need[15][15], avail[15], tres[15], work[15], flag[15];
    int pno, rno, i, j, prc, count, t, total;
    count = 0;

    cout << "\nEnter number of processes:";
    cin >> pno;
    cout << "\nEnter number of resources:";
    cin >> rno;

    for (i = 1; i <= pno; i++)
    {
        flag[i] = 0;
    }

    cout << "\nEnter total numbers of each resource:";
    for (i = 1; i <= rno; i++)
        cin >> tres[i];

    cout << "\nEnter Max resources for each process:";
    for (i = 1; i <= pno; i++)
    {
        cout << "\nFor process " << i << ":";
        for (j = 1; j <= rno; j++)
            cin >> max[i][j];
    }

    cout << "\nEnter allocated resources for each process:";
    for (i = 1; i <= pno; i++)
    {
        cout << "\nFor process " << i << ":";
        for (j = 1; j <= rno; j++)
            cin >> allocated[i][j];
    }

    cout << "\nAvailable resources:\n";
    for (j = 1; j <= rno; j++)
    {
        avail[j] = 0;
        total = 0;
        for (i = 1; i <= pno; i++)
        {
            total += allocated[i][j];
        }
        avail[j] = tres[j] - total;
        work[j] = avail[j];
        cout << "     " << work[j] << "\t";
    }

    do
    {
        for (i = 1; i <= pno; i++)
        {
            for (j = 1; j <= rno; j++)
            {
                need[i][j] = max[i][j] - allocated[i][j];
            }
        }

        cout << "\nAllocated matrix        Max      Need";
        for (i = 1; i <= pno; i++)
        {
            cout << "\n";
            for (j = 1; j <= rno; j++)
                cout << "    " << allocated[i][j];
            cout << "|";
            for (j = 1; j <= rno; j++)
                cout << "    " << max[i][j];
            cout << "|";
            for (j = 1; j <= rno; j++)
                cout << "    " << need[i][j];
        }

        prc = 0;

        for (i = 1; i <= pno; i++)
        {
            if (flag[i] == 0)
            {
                prc = i;

                for (j = 1; j <= rno; j++)
                {
                    if (work[j] < need[i][j])
                    {
                        prc = 0;
                        break;
                    }
                }
            }

            if (prc != 0)
                break;
        }

        if (prc != 0)
        {
            cout << "\nProcess " << i << " completed";
            count++;
            cout << "\nAvailable matrix:";
            for (j = 1; j <= rno; j++)
            {
                work[j] += allocated[prc][j];
                allocated[prc][j] = 0;
                max[prc][j] = 0;
                flag[prc] = 1;
                cout << "   " << work[j];
            }
        }
    } while (count != pno && prc != 0);

    if (count == pno)
        cout << "\nThe system is in a safe state!!";
    else
        cout << "\nThe system is in an unsafe state!!";

    return 0;
}
// Enter number of processes:3

// Enter number of resources:4

// Enter total numbers of each resource:10 5 7 8

// Enter Max resources for each process:
// For process 1:7 5 3 0

// For process 2:3 2 2 2

// For process 3:9 0 2 2

// Enter allocated resources for each process:
// For process 1:0 1 0 0

// For process 2:2 0 0 0

// For process 3:3 0 2 2

// Available resources:
//      5       4       5       6
// Allocated matrix        Max      Need
//     0    1    0    0|    7    5    3    0|    7    4    3    0
//     2    0    0    0|    3    2    2    2|    1    2    2    2
//     3    0    2    2|    9    0    2    2|    6    0    0    0
// Process 2 completed
// Available matrix:   7   4   5   6
// Allocated matrix        Max      Need
//     0    1    0    0|    7    5    3    0|    7    4    3    0
//     0    0    0    0|    0    0    0    0|    0    0    0    0
//     3    0    2    2|    9    0    2    2|    6    0    0    0
// Process 1 completed
// Available matrix:   7   5   5   6
// Allocated matrix        Max      Need
//     0    0    0    0|    0    0    0    0|    0    0    0    0
//     0    0    0    0|    0    0    0    0|    0    0    0    0
//     3    0    2    2|    9    0    2    2|    6    0    0    0
// Process 3 completed
// Available matrix:   10   5   7   8
// The system is in a safe state!!