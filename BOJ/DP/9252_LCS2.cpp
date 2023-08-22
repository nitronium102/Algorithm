// 골드4
// Created by KangMinji on 2023-08-09.
// https://www.acmicpc.net/problem/9252

#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int dp[1001][1001];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> s1 >> s2;
	int length1 = s1.length();
	int length2 = s2.length();

	for (int i = 1; i <= length1; i++) {
		for (int j = 1; j <= length2; j++) {
			// 같은 알파벳인 경우 : LCS 길이 증가
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} // 다른 알파벳인 경우 : 길이 유지
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << dp[length1][length2] << '\n';

	// 역순으로 LCS를 찾아감
	string result = "";
	while (length1 > 0 && length2 > 0) {
		if (s1[length1-1] == s2[length2-1]) {
			result = s1[length1 - 1] + result; // 문자열 인덱스는 dp 인덱스 - 1
			length1--;
			length2--;
		} else if (dp[length1][length2] == dp[length1 - 1][length2]) { // 위에 이미 같은 수가 있는 경우
			length1--;
		} else if (dp[length1][length2] == dp[length1][length2 - 1]) { // 왼쪽에 이미 같은 수가 있는 경우
			length2--;
		}
	}

	// 출력
	cout << result;

}