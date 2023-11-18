// 실버3
// Created by KangMinji on 2023-01-28.
// https://www.acmicpc.net/problem/2579

#include <iostream>

using namespace std;

int dp[301];
int score[301];

int main() {
	int n;

	// 입력
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> score[i];
	}

	// 연산
	/* 0~n-2
	 * 1) 마지막 계단(n-1)은 밟고 시작
	 * 2) n-1 ~ 0까지 2개씩 가는 경우 / 1개씩 가는 경우 계산
	 */
	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	dp[3] = max(score[1], score[2]) + score[3];

	for (int i = 3; i <= n; i++) {
		// (2칸 + 1칸), 2캔
		dp[i] = max(dp[i - 3] + score[i - 1], dp[i - 2]) + score[i];
	}

	cout << dp[n] << "\n";
}