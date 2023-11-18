// 실버3
// Created by KangMinji on 2023-07-23.
// https://www.acmicpc.net/problem/1003

#include <bits/stdc++.h>
using namespace std;

int dp[41][2];

void makeDP() {
	dp[0][0] = 1;
	dp[1][1] = 1;

	for (int i=2; i<=40; i++){
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
	}
}

int main() {

	int t, n;

	makeDP();

	cin >> t;
	while(t--){
		cin >> n;
		cout << dp[n][0] << ' ' << dp[n][1] << '\n';
	}
}