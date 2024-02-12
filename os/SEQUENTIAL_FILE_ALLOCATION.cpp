#include <iostream>
using namespace std;

int main()
{
    int f[50], i, st, len, j, c, k, count = 0;

    for (i = 0; i < 50; i++)
        f[i] = 0;

    cout << "Files Allocated are : \n";
x:
    count = 0;
    cout << "Enter starting block and length of files: ";
    cin >> st >> len;

    for (k = st; k < (st + len); k++)
        if (f[k] == 0)
            count++;

    if (len == count)
    {
        for (j = st; j < (st + len); j++)
            if (f[j] == 0)
            {
                f[j] = 1;
                cout << j << "\t" << f[j] << endl;
            }

        if (j != (st + len - 1))
            cout << "The file is allocated to disk\n";
    }
    else
    {
        cout << "The file is not allocated \n";
    }

    cout << "Do you want to enter more file(Yes - 1/No - 0)";
    cin >> c;

    if (c == 1)
        goto x;
    else
        return 0;
}
