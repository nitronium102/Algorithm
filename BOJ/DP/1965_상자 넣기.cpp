// 실버2
// Created by KangMinji on 2023-01-29.
// https://www.acmicpc.net/problem/1965

#include <iostream>
using namespace std;

int dp[1001];
int box_size[1001];

int main() {
	int n;

	// 입력
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> box_size[i];
	}

	// 연산
	dp[0] = 1;

	int answer = 0;
	for (int i=1; i<n; i++){
		dp[i] = 1;
		for (int j=i-1; j>=0; j--){
			if (box_size[j] < box_size[i]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		answer = max(answer, dp[i]);
	}

	// 출력
	cout << answer << "\n";
}