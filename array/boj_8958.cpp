#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int num;
    int sum, result = 0;
    char arr[80] = {
        0,
    };
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> arr; // �迭�� ���ڿ� �Է�
        for (int i = 0; i < strlen(arr); i++)
        {
            if (arr[i] == 'O')
            {
                sum++;
                result += sum;
            }
            if (arr[i] == 'X')
            {
                sum = 0;
            }
        }
        cout << result << endl;
        sum = 0;
        result = 0;
    }
    return 0;
}