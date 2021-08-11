#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int cnt = 0, idx;
    vector<string> croa{"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    for (int i = 0; i < croa.size(); i++)
    {
        while (1)
        {
            idx = str.find(croa[i]);
            if (idx == string::npos)
                break;
            str.replace(idx, croa[i].length(), "#");
        }
    }
    cout << str.length();
}