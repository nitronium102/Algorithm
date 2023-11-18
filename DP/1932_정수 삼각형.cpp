// 실버1
// Created by KangMinji on 2023-07-23.
// https://www.acmicpc.net/problem/1932

#include <bits/stdc++.h>
using namespace std;

int num[502][502];
int dp[502][502];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> num[i][j];
		}
	}

	// 연산
	dp[1][1] = num[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + num[i][j];
		}
	}

	// 출력
	cout << *max_element(dp[n] + 1, dp[n] + n + 1);
}