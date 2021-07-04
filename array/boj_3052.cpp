#include <iostream>
using namespace std;

int main()
{
    int num, sum = 0;
    int remainder[42] = {
        0,
    };

    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        // 배열 인덱스의 값이 0인 경우
        if (!remainder[num % 42]++)
            sum++;
    }
    cout << sum;
    return 0;
}