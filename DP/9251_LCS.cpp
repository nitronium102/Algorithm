// 골드5
// Created by KangMinji on 2023-04-06.
// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <vector>

using namespace std;

int findLCS(string s1, string s2) {
	int n = s1.length();
	int m = s2.length();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (s1[i-1] == s2[j-1]){
				// max(dp[i-1][j], dp[i][j-1]) + 1이 아님!
				// 만약 두 문자가 같으면 두 문자의 idx를 하나씩 늘려줘야 하기 때문이라고 생각하자
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[n][m];
}

int main() {
	string s1, s2;

	// 입력
	cin >> s1 >> s2;

	// 연산
	cout << findLCS(s1, s2);
}