// 골드5
// Created by KangMinji on 2023-08-09.
// https://www.acmicpc.net/problem/5582

#include <bits/stdc++.h>
using namespace std;

int dp[4001][4001];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	string s1, s2;
	cin >> s1 >> s2;

	// dp[i][j] = str1의 i번째, str2의 j번째까지 비교했을 때 최대 공통 부분 길이
	// str1과 str2에 같은 문자가 있을 때만 연산
	// dp[i][j] = dp[i-1][j-1] + 1;
	int s1_len = s1.length();
	int s2_len = s2.length();

	int answer = 0;
	for (int i=1; i<s1_len+1; i++){
		for (int j=1; j<s2_len+1; j++){
			if (s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				answer = max(answer, dp[i][j]);
			}
		}
	}

	// 출력
	cout << answer;
}