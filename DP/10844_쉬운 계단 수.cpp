// 실버1
// Created by KangMinji on 2023-09-03.
// https://www.acmicpc.net/problem/10844

#include <iostream>

using namespace std;
const int MOD = 1000000000;

int n;
long long dp[101][10]; // dp[i][j] : i번째 자리에 j가 왔을 때 가능한 수

int main() {
	cin >> n;

	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	/*
	 * dp[n][0] = dp[n-1][1]
	 * dp[n][9] = dp[n-1][8];
	 * dp[n][1] = dp[n-1][0] + dp[n-1][2];
	 */
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) { // 1밖에 안됨
				dp[i][j] = dp[i - 1][j + 1] % MOD;
			} else if (j == 9) { // 8밖에 안 됨
				dp[i][j] = dp[i - 1][j - 1] % MOD;
			} else {
				dp[i][j] = dp[i - 1][j - 1] % MOD + dp[i - 1][j + 1] % MOD;
			}
		}
	}

	long long answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += dp[n][i] % MOD;
	}

	cout << answer % MOD;
}