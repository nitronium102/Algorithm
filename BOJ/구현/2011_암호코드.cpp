// 골드5
// Created by KangMinji on 2023-03-03.
// https://www.acmicpc.net/problem/2011

#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e6;

/* https://luv-n-interest.tistory.com/1258
 * 1) (병합X) dp[n-1] + dp[n] : 뒤에 한 글자만 더해주는 경우
 * 2) (병합O) dp[n-2] + dp[n-1:n] : 뒤에 합친 숫자 추가
 * => dp[]가 절대 0으로 시작하면 안 된다!
 */
int cntPassword(int n, string s){
	vector<int> dp(n+1, 0);

	if (s[0] == '0'){
		return 0;
	}

	s = ' ' + s; // 앞에 공백 문자 더하기
	dp[0] = dp[1] = 1;
	for (int i=2; i<=n; i++){
		if (s[i] == '0' && (s[i-1] < '1' || s[i-1] > '2') { // 30, 40, ...
			return 0;
		}
		// 1) 한 글자 암호 해석
		if (s[i] != '0'){
			dp[i] += dp[i-1];
		}
		// 2) 두 글자 암호 해석 : 추가되는 숫자가 26이하인 경우
		if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
			dp[i] += dp[i-2];
		}
		dp[i] %= MOD;
	}
	return dp[n];
}

int main() {
	string s;

	// 입력
	cin >> s;

	// 연산 & 출력
	cout << cntPassword(s.length(), s);
}