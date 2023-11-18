// 실버3
// Created by KangMinji on 2023-07-18.
// https://www.acmicpc.net/problem/11659

#include <iostream>
using namespace std;

int dp[100001];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, num;

	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> num;
		dp[i] = dp[i-1] + num;
	}

	int i, j;
	while(m--){
		cin >> i >> j;
		cout << dp[j] - dp[i-1] << '\n';
	}
}