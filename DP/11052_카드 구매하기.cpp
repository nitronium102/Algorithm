// 실버1
// Created by KangMinji on 2023-09-07.
// https://www.acmicpc.net/problem/11052

#include <iostream>

using namespace std;
const int MAX = 10005;

int n;
int num[MAX]; // idx : cnt, value : money
int dp[MAX]; // cnt개의 카드를 갖기 위해 지불할 돈의 최댓값

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	// 연산
	// dp[2] = max(dp[2], dp[1] + num[1]);
	// dp[3] = max(num[3], dp[1] + num[2], dp[2] + num[1]);
	// dp[4] = max(num[4], dp[1] + num[3], dp[2] + num[2], dp[3]+num[1]);
	dp[1] = num[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], num[j] + dp[i - j]);
		}
	}

	cout << dp[n];
}