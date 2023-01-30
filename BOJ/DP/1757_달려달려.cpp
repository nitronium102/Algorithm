// 골드5
// Created by KangMinji on 2023-01-29.
// https://www.acmicpc.net/problem/1757

#include <iostream>
using namespace std;

int N, M;
int dist[10001];
int dp[10001][501]; // 시간, 지침 지수

int solve(int n, int m){
	if (m == M){
		return 0;
	}
}

int main() {
	int N, N;

	// 입력
	cin >> N >> M;
	for (int i=1; i<=N; i++){
		cin >> dist[i];
	}

	// 연산
	solve(0, 0);

	// 출력
	cout << dp[N] << "\n";
}