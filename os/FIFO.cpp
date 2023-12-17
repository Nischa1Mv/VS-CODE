#include <iostream>
using namespace std;

int main()
{
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;

    cout << "\nEnter the length of the reference string -- ";
    cin >> n;

    cout << "\nEnter the reference string -- ";
    for (i = 0; i < n; i++)
        cin >> rs[i];

    cout << "\nEnter the number of frames -- ";
    cin >> f;

    for (i = 0; i < f; i++)
        m[i] = -1;

    cout << "\nThe Page Replacement Process is -- \n";

    for (i = 0; i < n; i++)
    {
        for (k = 0; k < f; k++)
        {
            if (m[k] == rs[i])
                break;
        }

        if (k == f)
        {
            m[count++] = rs[i];
            pf++;
        }

        for (j = 0; j < f; j++)
            cout << "\t" << m[j];

        if (k == f)
            cout << "\tPF No. " << pf;

        cout << "\n";

        if (count == f)
            count = 0;
    }

    cout << "\nThe number of Page Faults using FIFO are " << pf;

    return 0;
}

// Enter the length of the reference string -- 7

// Enter the reference string -- 1 2 3 1 2 2 1

// Enter the number of frames -- 3

// The Page Replacement Process is --
//         1       -1      -1      PF No. 1
//         1       2       -1      PF No. 2
//         1       2       3       PF No. 3
//         1       2       3
//         1       2       3
//         1       2       3
//         1       2       3

// The number of Page Faults using FIFO are 3