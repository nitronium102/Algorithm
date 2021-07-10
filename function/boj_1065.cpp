#include <iostream>
using namespace std;

bool calc_num(int num)
{
    int a, b, c;
    if (num < 100)
        return true;
    a = num / 100;
    b = num % 100 / 10;
    c = num % 10;
    if (a - b == b - c)
        return true;
    else
        return false;
}
int main()
{
    int num, cnt = 0;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        if (calc_num(i))
            cnt += 1;
    }
    cout << cnt << endl;
}