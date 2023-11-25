// 실버2
// Created by KangMinji on 2023-11-25.
// https://www.acmicpc.net/problem/1912

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int num[100005];
	for (int i=0; i<n; i++){
		cin >> num[i];
	}

	// 연산
	int dp[100005];
	dp[0] = num[0];

	int answer = dp[0];
	for (int i=1; i<n; i++){
		dp[i] = max(dp[i-1] + num[i], num[i]);
		answer = max(answer, dp[i]);
	}

	// 출력
	cout << answer << '\n';
}