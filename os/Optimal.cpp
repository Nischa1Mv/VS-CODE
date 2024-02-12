#include <iostream>
using namespace std;

int fr[3], n, m;

void display();

int main()
{
    int i, j, page[20];
    int max, found = 0, lg[3], index, k, l, flag1 = 0, flag2 = 0, pf = 0;
    float pr;

    cout << "Enter length of the reference string: ";
    cin >> n;

    cout << "Enter the reference string: ";
    for (i = 0; i < n; i++)
        cin >> page[i];

    cout << "Enter no of frames: ";
    cin >> m;

    for (i = 0; i < m; i++)
        fr[i] = -1;

    pf = m;

    for (j = 0; j < n; j++)
    {
        flag1 = 0;
        flag2 = 0;

        for (i = 0; i < m; i++)
        {
            if (fr[i] == page[j])
            {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (i = 0; i < m; i++)
            {
                if (fr[i] == -1)
                {
                    fr[i] = page[j];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            for (i = 0; i < m; i++)
                lg[i] = 0;

            for (i = 0; i < m; i++)
            {
                for (k = j + 1; k < n; k++)
                {
                    if (fr[i] == page[k])
                    {
                        lg[i] = k - j;
                        break;
                    }
                }
            }

            found = 0;

            for (i = 0; i < m; i++)
            {
                if (lg[i] == 0)
                {
                    index = i;
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                max = lg[0];
                index = 0;

                for (i = 0; i < m; i++)
                {
                    if (max < lg[i])
                    {
                        max = lg[i];
                        index = i;
                    }
                }
            }

            fr[index] = page[j];
            pf++;
        }

        display();
    }

    cout << "Number of page faults: " << pf << endl;

    pr = (float)pf / n * 100;
    cout << "Page fault rate = " << pr << endl;

    return 0;
}

void display()
{
    int i;
    for (i = 0; i < m; i++)
        cout << fr[i] << "\t";
    cout << endl;
}

// Output

// Enter length of the reference string: 12
// Enter the reference string: 1 2 3 4 1 2 5 1 2 3 4 5
// Enter no of frames: 3
// 1	-1	-1
// 1	2	-1
// 1	2	3
// 1	2	4
// 1	2	4
// 1	2	4
// 1	2	5
// 1	2	5
// 1	2	5
// 3	2	5
// 4	2	5
// 4	2	5
// Number of page faults: 7
// Page fault rate = 58.333332
