#include <iostream>
using namespace std;

void print(int frameno, int frame[])
{
    for (int j = 0; j < frameno; j++)
        cout << frame[j] << "\t";
    cout << endl;
}

int main()
{
    int i, j, k, n, page[50], frameno, frame[10], move = 0, flag, count = 0, count1[10] = {0},
                                                  repindex, leastcount;
    float rate;

    cout << "Enter the number of pages: ";
    cin >> n;

    cout << "Enter the page reference numbers: ";
    for (i = 0; i < n; i++)
        cin >> page[i];

    cout << "Enter the number of frames: ";
    cin >> frameno;

    for (i = 0; i < frameno; i++)
        frame[i] = -1;

    cout << "Page reference string\tFrames\n";

    for (i = 0; i < n; i++)
    {
        cout << page[i] << "\t\t\t";

        flag = 0;

        for (j = 0; j < frameno; j++)
        {
            if (page[i] == frame[j])
            {
                flag = 1;
                count1[j]++;
                cout << "No replacement" << endl;
                break;
            }
        }

        if (flag == 0 && count < frameno)
        {
            frame[move] = page[i];
            count1[move] = 1;
            move = (move + 1) % frameno;
            count++;
            print(frameno, frame);
        }
        else if (flag == 0)
        {
            repindex = 0;
            leastcount = count1[0];

            for (j = 1; j < frameno; j++)
            {
                if (count1[j] < leastcount)
                {
                    repindex = j;
                    leastcount = count1[j];
                }
            }

            frame[repindex] = page[i];
            count1[repindex] = 1;
            count++;
            print(frameno, frame);
        }
    }

    rate = static_cast<float>(count) / static_cast<float>(n);
    cout << "Number of page faults is " << count << endl;
    cout << "Fault rate is " << rate << endl;

    return 0;
}

//  OUTPUT:
// Enter the number of pages
// 12
// Enter the page reference numbers
// 0 2 1 6 4 0 1 0 3 1 2 1
// Enter the number of frames
// 4
// Page reference string   Frames
// 0                       0       -1      -1      -1
// 2                       0       2       -1      -1
// 1                       0       2       1       -1
// 6                       0       2       1       6
// 4                       4       2       1       6
// 0                       0       2       1       6
// 1                       No replacement
// 0                       No replacement
// 3                       0       3       1       6
// 1                       No replacement
// 2                       0       2       1       6
// 1                       No replacement
// Number of page faults is 8
// Fault rate is 0.666667