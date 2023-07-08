// 골드5
// Created by KangMinji on 2023-07-08.
// https://www.acmicpc.net/problem/2294

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10001;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int n, k;
	cin >> n >> k;
	vector<int> coins(n, 0);

	for (int i=0; i<n; i++)
		cin >> coins[i];

	// 연산
	sort(coins.begin(), coins.end());

	vector<int> dp(MAX, MAX); // 가치
	dp[0] = 0;
	for (int coin : coins) {
		for (int j=coin; j<=k; j++){
			dp[j] = min(dp[j], dp[j - coin] + 1);
		}
	}

	// 출력
	if (dp[k] == MAX)
		cout << -1;
	else
		cout << dp[k];
}