#include <iostream>
#include <cstring>

using namespace std;

struct fileTable
{
    char name[20];
    int nob;
    int blocks[30];
} ft[30];

int main()
{
    int i, j, n;
    char s[20];

    cout << "Enter no of files :";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "\nEnter file name " << i + 1 << " :";
        cin >> ft[i].name;

        cout << "Enter no of blocks in file " << i + 1 << " :";
        cin >> ft[i].nob;

        cout << "Enter the blocks of the file :";
        for (j = 0; j < ft[i].nob; j++)
            cin >> ft[i].blocks[j];
    }

    cout << "\nEnter the file name to be searched -- ";
    cin >> s;

    for (i = 0; i < n; i++)
        if (strcmp(s, ft[i].name) == 0)
            break;

    if (i == n)
        cout << "\nFile Not Found";
    else
    {
        cout << "\nFILE NAME NO OF BLOCKS BLOCKS OCCUPIED";
        cout << "\n " << ft[i].name << "\t\t" << ft[i].nob << "\t";
        for (j = 0; j < ft[i].nob; j++)
            cout << ft[i].blocks[j] << ", ";
    }

    return 0;
}

// Enter no of files :3

// Enter file name 1 :file1
// Enter no of blocks in file 1 :4
// Enter the blocks of the file :1 2 3 4

// Enter file name 2 :file2
// Enter no of blocks in file 2 :3
// Enter the blocks of the file :5 6 7

// Enter file name 3 :file3
// Enter no of blocks in file 3 :2
// Enter the blocks of the file :8 9

// Enter the file name to be searched -- file2
