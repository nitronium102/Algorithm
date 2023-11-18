// 실버2
// Created by KangMinji on 2023-10-26.
// https://www.acmicpc.net/problem/11055

#include <iostream>
#include <vector>
using namespace std;

int num[1005];
int dp[1005];

int main() {
	// 입력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> num[i];
	}

	// 연산
	int answer = -1;
	for (int i=0; i<n; i++){
		dp[i] = num[i];
		// i보다 작은 idx를 순회하면서
		for (int j=0; j<i; j++){
			if (num[i] > num[j] && dp[i] < dp[j] + num[i]){
				dp[i] = dp[j] + num[i];
			}
		}
		answer = max(answer, dp[i]);
	}

	// 출력
	cout << answer;
}