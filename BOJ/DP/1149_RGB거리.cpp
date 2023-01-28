// 실버1
// Created by KangMinji on 2023-01-28.
// https://www.acmicpc.net/problem/1149

#include <iostream>
#include <algorithm>
using namespace std;

int cost[1001][3]; // {n번쨰 집, r/g/b로 칠하는 비용}
int dp[1001][3]; // i번째 집을 c색으로 칠했을 때 1~i번째 집까지의 최소 비용

// 인접한 집은 같은 색으로 칠하면 안 된다
int main() {
	int n;

	// 입력
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	// 초기화
	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];

	// 연산
	for (int i=2; i<=n; i++){
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
	}

	// 출력
	cout << min({dp[n][0], dp[n][1], dp[n][2]});
}