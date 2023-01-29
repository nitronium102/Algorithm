// 실버3
// Created by KangMinji on 2023-01-28.
// https://www.acmicpc.net/problem/9461

#include <iostream>

using namespace std;

long long dp[101];

// 1,1,1,2,2까지는 초기값
// dp[n] = dp[n-1] + dp[n-5]
int main() {
	int t, n;

	// 초기화
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;

	// 입력
	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 6; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}

		cout << dp[n] << "\n";
	}
}