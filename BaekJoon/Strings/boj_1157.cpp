#include <iostream>
using namespace std;

int main()
{
    string word, result;
    int arr[26] = {
        0,
    };
    int max_cnt = 0;
    cin >> word;

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] < 97)
            arr[word[i] - 65]++; //대문자
        else
            arr[word[i] - 97]++; //소문자
    }

    for (int j = 0; j < 26; j++)
    {
        if (arr[j] == 0)
            continue;
        else if (max_cnt < arr[j])
        {
            max_cnt = arr[j];
            result = (char)(j + 65);
        }
        else if (max_cnt == arr[j])
        {
            result = "?";
        }
    }
    cout << result;
}