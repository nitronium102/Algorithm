// 골드4
// Created by KangMinji on 2023-07-24.
// https://www.acmicpc.net/problem/5569

#include <iostream>
using namespace std;
const int MOD = 100000;

// dir = 0(동쪽), 1(북쪽)
int dp[101][101][2][2]; // [i][j][dir][k] - dir(방향), k(방향 전환 가능 여부)

int main() {
	int w, h;

	cin >> w >> h;

	for (int i=2; i<=h; i++)
		dp[i][1][0][0] = 1;

	for (int i=2; i<=w; i++)
		dp[1][i][0][1] = 1;

	for (int i=2; i<=h; i++){
		for (int j=2; j<=w; j++){
			dp[i][j][0][0] = (dp[i-1][j][0][0] + dp[i-1][j][0][1]) % MOD;
			dp[i][j][0][1] = dp[i-1][j][0][1] % MOD;
			dp[i][j][1][0] = (dp[i][j-1][1][0] + dp[i][j-1][1][1]) % MOD;
			dp[i][j][1][1] = dp[i][j-1][0][0] % MOD;
		}
	}
	cout << (dp[h][w][0][0] + dp[h][w][0][1] + dp[h][w][1][0] + dp[h][w][1][1]) % MOD << '\n';
}