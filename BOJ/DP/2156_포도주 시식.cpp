// 실버1
// Created by KangMinji on 2023-04-05.
// https://www.acmicpc.net/problem/2156

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;

	// 입력
	cin >> n;
	vector<int> wine(n+1, 0);
	vector<int> dp(n+1, 0);
	for (int i=1; i<=n; i++){
		cin >> wine[i];
	}

	// 연산
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i=3; i<=n; i++){
		// 와인을 마시는 경우 2가지, 안 마시는 경우 1가지
		dp[i] = max({dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i], dp[i-1]});
	}

	// 출력
	cout << dp[n];
}