#include <iostream>
using namespace std;

int main()
{
    string S;
    cin >> S;
    for (char i = 'a'; i <= 'z'; i++)
    {
        cout << (int)S.find(i) << " ";
    }
}