// 실버4
// Created by KangMinji on 2023-01-28.
// https://www.acmicpc.net/problem/2491

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001][2]; // i번째까지의 오름차순/내림차순 수열의 길이

int main() {
	int n;

	// 입력
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}

	// 연산(연속성 고려)
	int answer = 0;
	for (int i=0; i<n; i++){
		dp[i][0] = dp[i][1] = 1;

		// 오름차순
		if (arr[i] >= arr[i-1]){
			dp[i][0] = dp[i-1][0]+1;
		}
		// 내림차순
		if (arr[i] <= arr[i-1]){
			dp[i][1] = dp[i-1][1] +1;
		}

		answer = max({answer, dp[i][0], dp[i][1]});
	}

	// 출력
	cout << answer << "\n";
}