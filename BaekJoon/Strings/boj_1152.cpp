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
    // 맨 처음 공백이 오는 경우
    if (str[0] == ' ' || str[0] == '\n')
        cnt--;
    // 맨 뒤에 공백이 오는 경우
    if (str[str.length() - 1] == ' ')
        cnt--;

    cout << cnt;
}