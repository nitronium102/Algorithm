// 실버2
// Created by KangMinji on 2023-01-28.
// https://www.acmicpc.net/problem/11053

#include <iostream>
using namespace std;

int dp[1001];
int arr[1001];

int main() {
	int n;

	// 입력
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}

	// 연산
	int answer = 0;
	for (int i=0; i<n; i++){
		dp[i] = 1;
		for (int j=i-1; j>=0; j--){
			if (arr[j] < arr[i]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		answer = max(answer, dp[i]);
	}
	cout << answer;
}