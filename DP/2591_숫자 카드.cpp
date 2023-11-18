// 골드5
// Created by KangMinji on 2023-02-17.
// https://www.acmicpc.net/problem/2591

#include <iostream>
using namespace std;

int dp[45];

int main() {
	string input;

	// 입력
	cin >> input;

	// 1) 제일 앞자리 0이면 X
	// 2) 모든 자리는 1 ~ 34까지의 숫자
	dp[0] = 1;

	for (int i=1; i<input.size(); i++){
		int cur = input[i] - '0';
		int front = input[i-1] - '0';

		if (cur + front*10 <= 34 && front){
			if (i == 1){
				dp[i] = 1;
			}
			dp[i] = dp[i-2];
		}

		if (cur){
			dp[i] += dp[i-1];
		}
	}

	// 출력
	cout << dp[input.size()-1];
}