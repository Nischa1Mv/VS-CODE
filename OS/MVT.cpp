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

        //temp-> temporary memory

        if (temp >= v[i])
        {
            temp -= v[i];
            i++;
            cout << "do u want to continue t/f: ";
        }
        else
        {
            cout << "memory full" << endl;
            b=false;
            break;
        }
       
        char ch;
        cin >> ch;
        if (ch == 'f')
        {
            b=false;
        }
    }
    cout <<"internal fragmentation : "<< temp<<endl;
    cout <<"meomory allocated : "<< ms - temp<<endl;
}
