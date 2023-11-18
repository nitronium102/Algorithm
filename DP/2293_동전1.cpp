// 골드5
// Created by KangMinji on 2023-01-29.
// https://www.acmicpc.net/problem/2293

#include <iostream>

using namespace std;

int dp[100001];
int val[101];

void solve(int n, int k) {

	// 초기화
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = val[i]; j <= k; j++) {
			dp[j] += dp[j - val[i]];
		}
	}
}

int main() {
	int n, k;

	// 입력
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}

	// 연산
	solve(n, k);

	// 출력
	cout << dp[k];
}