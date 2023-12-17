#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int ms, n = 0, i = 0, b = true;
    // give the memory
    cout << "gib the memory : ";
    cin >> ms;
    int temp = ms;
    while (b)
    {
        cout << "enter the memory of the process" << ++n << " :";
        int t;
        cin >> t;
        v.push_back(t);

        // temp-> temporary memory

        if (temp >= v[i])
        {
            temp -= v[i];
            i++;
            cout << "do u want to continue t/f: ";
        }
        else
        {
            cout << "memory full" << endl;
            b = false;
            break;
        }

        char ch;
        cin >> ch;
        if (ch == 'f')
        {
            b = false;
        }
    }
    cout << "internal fragmentation : " << temp << endl;
    cout << "meomory allocated : " << ms - temp << endl;
}

// gib the memory : 500
// enter the memory of the process1 :150
// do u want to continue t/f: t
// enter the memory of the process2 :320
// do u want to continue t/f: t
// enter the memory of the process3 :50
// memory full
// internal fragmentation : 30
// meomory allocated : 470