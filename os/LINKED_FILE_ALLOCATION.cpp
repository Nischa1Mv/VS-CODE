#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct block
{
    int bno;
    block *next;
};

struct fileTable
{
    char name[20];
    int nob;
    block *sb;
} ft[30];

int main()
{
    int i, j, n;
    char s[20];
    block *temp;

    cout << "Enter no of files   :";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "\nEnter file name " << i + 1 << " :";
        cin >> ft[i].name;
        cout << "Enter no of blocks in file " << i + 1 << " :";
        cin >> ft[i].nob;

        ft[i].sb = new block;
        temp = ft[i].sb;

        cout << "Enter the blocks of the file :";
        cin >> temp->bno;
        temp->next = nullptr;

        for (j = 1; j < ft[i].nob; j++)
        {
            temp->next = new block;
            temp = temp->next;

            cin >> temp->bno;
            temp->next = nullptr;
        }
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
        temp = ft[i].sb;

        for (j = 0; j < ft[i].nob; j++)
        {
            cout << temp->bno << " ";
            temp = temp->next;
        }
    }

    delete temp;
    return 0;
}
