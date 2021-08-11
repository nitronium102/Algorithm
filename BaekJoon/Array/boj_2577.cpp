#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3, num;
    int arr[10] = {
        0,
    }; // 0~9까지 숫자
    cin >> n1 >> n2 >> n3;
    num = n1 * n2 * n3;

    while (num > 0)
    {
        arr[num % 10]++; // 기존값 증가
        num /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}