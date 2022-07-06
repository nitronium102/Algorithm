//
// Created by KangMinji on 2022-03-15.
//

/*
 * 비슷한 단어
 * 1) 하나의 문자를 더하는 경우(크기 차이 1)
 * 2) 하나의 문자를 빼는 경우(크기 차이 1)
 * 3) 하나의 문자를 다른 문자로 바꾸는 경우(크기 차이 0)
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;

void countAlphabet(int ch[26], string word){
    for (int k=0; k<word.length(); k++)
        ch[word[k]-'A']++;
}

int solution(int n, vector<string> words) {
    int answer = 0;
    int ch_standard[26] = {0, };
    int ch_other[26];

    int length = words[0].length();
    countAlphabet(ch_standard, words[0]);

    for (int i = 1; i < n; i++) {
        // 초기화
        fill_n(ch_other, 26, 0); // ch_other = {0, }은 먹히지 않는다...
        int diff = 0;
        countAlphabet(ch_other, words[i]);

        for (int j = 0; j < 26; j++)
            diff += abs(ch_standard[j] - ch_other[j]);

        if (diff == 0 || diff == 1 || (diff == 2 && words[i].length() == length))
            answer++;
    }
    return answer;
}

int main() {
    int n;

    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];

    cout << solution(n, words);
}
