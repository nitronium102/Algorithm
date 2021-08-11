#include <iostream>
using namespace std;

bool self[10001];

int d(int num)
{
    int res = num / 1000 + (num % 1000) / 100 + (num % 100) / 10 + num % 10 + num;
    return res;
}

int main()
{
    for (int num = 1; num < 10000; num++)
    {
        int res = d(num);
        if (res <= 10000)
            self[res] = true;
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (!self[i])
            cout << i << endl;
    }
}