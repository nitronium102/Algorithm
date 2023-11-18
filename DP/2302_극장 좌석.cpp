// 실버1
// Created by KangMinji on 2023-07-17.
// https://www.acmicpc.net/problem/2302

#include <iostream>
#include <vector>

using namespace std;

/*
 * i번째 좌석에
 * i번 앉는 경우 => dp[i-1]
 * i-1번 앉는 경우 -> i-1번 좌석에는 i번 앉음 => dp[i-2];
 * dp[i] = dp[i-1] + dp[i-2];
 */
int main() {
	int n, m, s;

	cin >> n >> m;

	vector<int> vip = {0, };
	int dp[45];

	for (int i = 0; i < m; i++) {
		cin >> s;
		vip.push_back(s);
	}
	vip.push_back(n + 1);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	// 출력
	int answer = 1;
	for (int i = 1; i < vip.size(); i++) {
		answer *= dp[vip[i] - vip[i - 1] - 1];
	}
	cout << answer;
}