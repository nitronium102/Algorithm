// 실버3
// Created by KangMinji on 2023-09-25.
// https://www.acmicpc.net/problem/14501
// 🔥인덱스 범위 조심

#include <iostream>
using namespace std;

int n;
int time[16];
int money[16];
int dp[16];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> time[i] >> money[i];
	}

	// 연산
	for (int i=n-1; i>=0; i--){
		int deadline = i + time[i];
		// 상담 못 하는 경우 : 전날 돈 그대로
		if (deadline > n){
			dp[i] = dp[i+1];
		} else {
			dp[i] = max(dp[i + 1], dp[deadline] + money[i]);
		}
	}

	// 출력
	cout << dp[0] << "\n";
}