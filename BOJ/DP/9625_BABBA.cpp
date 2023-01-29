// 실버5
// Created by KangMinji on 2023-01-28.
// https://www.acmicpc.net/problem/9625

#include <iostream>
using namespace std;

int dp[45][2];

int main() {
	int k;

	// 입력
	cin >> k;

	// 초기화
	dp[0][0] = 1;

	// 연산
	for (int i=1; i<=k; i++){
		// A = 이전 단계 B의 개수
		dp[i][0] = dp[i-1][1];
		// B = 이전 단계 B의 개수 + A의 개수
		dp[i][1] = dp[i-1][0] + dp[i-1][1];
	}

	// 출력
	cout << dp[k][0] << ' ' << dp[k][1];
}