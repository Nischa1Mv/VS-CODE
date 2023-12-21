#include <iostream>
using namespace std;

int main()
{
    int n, m, temp = 0, count = 0;
    cout << "Enter the rows and columns: ";
    cin >> n >> m;

    int s[n][m];

    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
            if (s[i][j] != 0)
            {
                count++;
            }
        }
    }

    int a[count][3];

    cout << "Sparse matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] != 0)
            {
                a[temp][0] = i;
                a[temp][1] = j;
                a[temp][2] = s[i][j];
                temp++;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
