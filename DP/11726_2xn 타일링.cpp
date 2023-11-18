// 실버3
// Created by KangMinji on 2023-01-28.
// https://www.acmicpc.net/problem/11726

#include <iostream>
using namespace std;
const int NUM = 10007;

int dp[1001];

int tiling(int n) {
	if (n == 1 || n == 2) {
		return dp[n];
	}
	if (dp[n] == 0) {
		dp[n] = (tiling(n - 1) + tiling(n - 2)) % NUM;
	}
	return dp[n];
}

int main() {
	int n;

	// 입력
	cin >> n;

	// 초기화
	dp[1] = 1;
	dp[2] = 2;

	// 연산 & 출력
	cout << tiling(n);
}