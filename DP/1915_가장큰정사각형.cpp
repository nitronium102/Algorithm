// 골드4
// Created by KangMinji on 2023-08-08.
// https://www.acmicpc.net/problem/1915

#include <iostream>

using namespace std;

int n, m;
int dp[1001][1001];
string s;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m;

	// 연산
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			int num = s[j - 1] - '0';
			if (num == 1) {
				// 가로, 세로, 대각선 모두 확인하고 다 1이면 +1
				dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
				answer = max(answer, dp[i][j]);
			}
		}
	}

	// 출력(넓이)
	cout << answer * answer;
}