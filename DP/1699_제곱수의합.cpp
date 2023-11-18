// 실버2
// Created by KangMinji on 2023-11-15.
// https://www.acmicpc.net/problem/1699

#include <iostream>
using namespace std;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int n;
	cin >> n;

	// 연산
	int dp[100005];

	for (int i=1; i<=n; i++){
		dp[i] = i;
	}

	for (int i=1; i<=n; i++){
		for (int j=1; j*j<=i; j++){
			dp[i] = min(dp[i], dp[i - j*j] + 1);
		}
	}

	// 출력
	cout << dp[n];

}