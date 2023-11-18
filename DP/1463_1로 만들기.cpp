// 실버3
// Created by KangMinji on 2023-01-28.
// https://www.acmicpc.net/problem/1463

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int calc(int n) {
	if (n == 1) {
		return dp[n];
	}
	if (dp[n] == 0) {
		dp[n] = calc(n - 1);
		if (n % 3 == 0) {
			dp[n] = min(dp[n], calc(n / 3));
		}
		if (n % 2 == 0) { // 2와 3으로 동시에 나누어질 수있으므로 else if를 넣으면 안 됨
			dp[n] = min(dp[n], calc(n / 2));
		}
		dp[n] += 1;
	}
	return dp[n];
}

int main() {
	int n;

	// 입력
	cin >> n;

	// 초기화
	dp[1] = 0;

	// 연산
	cout << calc(n);
}