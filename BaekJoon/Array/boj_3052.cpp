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
        // �迭 �ε����� ���� 0�� ���
        if (!remainder[num % 42]++)
            sum++;
    }
    cout << sum;
    return 0;
}