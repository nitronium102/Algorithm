#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int cnt = 1;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            cnt++;
        }
    }
    // �� ó�� ������ ���� ���
    if (str[0] == ' ' || str[0] == '\n')
        cnt--;
    // �� �ڿ� ������ ���� ���
    if (str[str.length() - 1] == ' ')
        cnt--;

    cout << cnt;
}