// 실버2
// Created by KangMinji on 2023-04-05.
// https://www.acmicpc.net/problem/11048

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;

	// 입력
	cin >> n >> m;
	vector<vector<int>> board(n+1, vector<int>(m+1, 0));
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> board[i][j];
		}
	}

	// 연산
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + board[i][j];
		}
	}

	// 출력
	cout << dp[n][m];
}