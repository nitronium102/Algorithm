// 실버1
// Created by KangMinji on 2023-07-18.
// https://www.acmicpc.net/problem/12852

#include <iostream>
using namespace std;
const int MAX = 1e6 + 1;

int dp[MAX];
int pre[MAX];

int main(){
	int n;
	cin >> n;

	dp[1] = 0;
	for (int i=2; i<=n; i++){
		dp[i] = dp[i-1] + 1;
		pre[i] = i-1;
		if (i%2 == 0 && dp[i] > dp[i/2] + 1){
			dp[i] = dp[i/2] + 1;
			pre[i] = i/2;
		}
		if (i%3 == 0 && dp[i] > dp[i/3] + 1){
			dp[i] = dp[i/3] + 1;
			pre[i] = i/3;
		}
	}

	cout << dp[n] << '\n';

	int cur = n;
	while(true) {
		cout << cur << ' ';
		if (cur == 1) break;
		cur = pre[cur];
	}
}
