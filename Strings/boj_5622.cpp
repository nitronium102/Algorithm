#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string dial;
    cin >> dial;
    int time = 0;
    vector<string> dial_list{"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    for (int i = 0; i < dial.length(); i++)
    {
        for (int j = 0; j < dial_list.size(); j++)
        {
            if (dial_list[j].find(dial[i]) != string::npos)
                time += j + 3;
        }
    }
    cout << time;
}