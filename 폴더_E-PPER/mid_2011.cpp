//
// Created by KangMinji on 2022-03-15.
//

/*
 * 암호
 * dp[i] = dp[i-1] + dp[i-2] (dp[1] = 1, i>1)
 * 1) 0 혼자는 해석 불가
 * 2) 처음 시작이 0인 경우 주의
 * 3) 현재 수가 0이 아닌데, 앞의 수가 1,2가 아닌 경우
 * 4) 두 개의 수를 알파벳으로 고려할 때 26 이하인지 확인
 */

#include <iostream>
#include <vector>
using namespace std;
// 정답이 매우 클 수 있으므로, 1000000으로 나눈 나머지를 출력한다.
const int MOD = 1e6; // 연산 과정에서 int 범위 넘어갈 수 있음

int solution(string s, int length){
    int answer = 0;
    vector<long long> dp(length+1, 0);
    // 해독 불가 2) 처음 시작이 0인 경우
    if (s[0] == '0')
        return 0;
    dp[0] = dp[1] = 1;

    for (int i=2; i<=length; i++){
        int string_idx = i-1;
        // 해독 불가 3) 30, 40 등
        if (s[string_idx] == '0' && (s[string_idx - 1] < '1' || s[string_idx - 1] > '2'))
            return 0;
        // 해독 불가 2) 0 혼자는 해석 불가
        if (s[string_idx] != '0')
            dp[i] += dp[i-1]; // 한 자리 수 확인
        // 해독 불가 4) 두 개의 수가 26 이하인지 확인
        if (s[string_idx-1] == '1' || (s[string_idx-1] == '2' && s[string_idx] <= '6'))
            dp[i] += dp[i-2]; // 두 자리 수 확인
        dp[i] %= MOD;
    }
    answer = (int) dp[length];
    return answer;
}

int main() {
    string s;
    cin >> s;

    int answer = solution(s, s.length());
    cout << answer;
}