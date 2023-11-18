// 골드5
// Created by KangMinji on 2023-04-05.
// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

int knapsack(int n, int k, vector<ci> &object){
	vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

	for (int i=1; i<=n; i++){ // 각 물품
		// 최대 배낭 무게
		for (int j=0; j<=k; j++) { // 최대 weight
			if (j >= object[i].first) { // 가방에 넣을 수 있는 경우
				dp[i][j] = max(dp[i-1][j - object[i].first] + object[i].second,
							   dp[i-1][j]);
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][k];
}

int main() {
	int n, w, v, k;

	// 입력
	cin >> n >> k;
	vector<ci> object(n+1, {0,0});
	for (int i=1; i<=n; i++){
		cin >> object[i].first >> object[i].second;
	}

	// 연산
	cout << knapsack(n, k, object);
}