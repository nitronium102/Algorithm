#include <iostream>
using namespace std;

int main()
{
    int test_case, R;
    string str, result;
    cin >> test_case;
    for (int t = 0; t < test_case; t++)
    {
        cin >> R >> str;
        result = "";
        for (int i = 0; i < str.length(); i++)
            for (int j = 0; j < R; j++)
                result += str[i];
        cout << result << endl;
    }
}