// 실버3
// Created by KangMinji on 2023-07-23.
// https://www.acmicpc.net/problem/9095

#include <iostream>
using namespace std;

int dp[11];

void makeDP() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2; // 2, 1+1
	dp[3] = 4; // 3, 2+1, 1+2, 1+1+1

	for (int i=4; i<11; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
}

int main() {
	int n, t;

	makeDP();

	cin >> t;
	while(t--){
		cin >> n;
		cout << dp[n] << '\n';
	}
}