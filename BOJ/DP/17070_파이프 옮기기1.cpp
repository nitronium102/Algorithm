// 골드5
// Created by KangMinji on 2023-01-29.
// https://www.acmicpc.net/problem/17070

#include <iostream>
using namespace std;

int house[16][16];
int dp[16][16][3]; // 행, 열, {가로, 세로, 대각선}

void solve(int n){
	// 초기화
	dp[0][1][0] = 1;

	for (int j=2; j<n; j++){
		if (house[0][j]){ // 벽이 있다면
			continue;
		}
		dp[0][j][0] = dp[0][j-1][0]; // 1로 하면 안 됨!(중간에 끊길 수도)
	}

	// 연산
	for (int i=1; i<n; i++){
		for (int j=2; j<n; j++){
			if (house[i][j]){
				continue;
			}
			dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2]; // 가로(노랑)
			dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2]; // 세로(초록)
			if (!house[i-1][j] && !house[i][j-1]){
				dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
			}
		}
	}
}

int main() {
	int n;

	// 입력
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> house[i][j];
		}
	}

	// 연산
	solve(n);

	// 출력
	cout << dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2];
}