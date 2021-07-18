#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int line, cnt, idx;
    string str;
    int alpha[26];

    cin >> line;
    cnt = line;

    for (int i = 0; i < line; i++)
    {
        cin >> str;
        fill_n(alpha, 26, 0);
        for (int j = 0; j < str.length(); j++)
        {
            idx = str[j] - 97;
            if (alpha[idx] == 0)
                alpha[idx] = 1;
            else if (str[j - 1] != str[j])
            {
                if (alpha[idx] == 1)
                    cnt -= 1;
                break;
            }
        }
    }
    cout << cnt;
}