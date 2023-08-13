// 골드3
// Created by KangMinji on 2023-08-09.
// https://www.acmicpc.net/problem/7579

#include <bits/stdc++.h>
using namespace std;

int n, m;
// dp[i][j] : i번째 앱까지 입력된 앱에 대하여 j 비용으로 구할 수 있는 최대 메모리 크기
int dp[101][10001]; // c 최대 100개 * n 최대 100개
int memory[101];
int cost[101];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> memory[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	// 최대 메모리 크기 : dp[i][j] = max(dp[i-1][j-cost[i]] + memory[i], dp[i-1][j])
	int answer = 1e9 + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 10000; j++) {
			// 앱이 1개인 경우 : 현재 cost보다 같거나 큰 경우에 대해서 모두 초기화
			if (i == 0) {
				if (j >= cost[i]) dp[i][j] = memory[i];
			} else {
				if (j >= cost[i]) {
					dp[i][j] = max(dp[i - 1][j - cost[i]] + memory[i], dp[i - 1][j]);
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}

			if (dp[i][j] >= m) {
				answer = min(answer, j); // j가 비용
			}
		}
	}

	// 출력
	cout << answer;
}