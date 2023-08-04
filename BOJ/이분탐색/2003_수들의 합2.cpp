// 실버4
// Created by KangMinji on 2023-07-25.
// https://www.acmicpc.net/problem/2003

#include <iostream>
using namespace std;

int arr[10001];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> arr[i];
	}

	// 연산
	int answer = 0;
	int start = 1, end = 1;
	int sum = arr[start];
	while(end <= n) {
		if (sum < m) {
			sum += arr[++end];
		} else if (sum == m){
			answer++;
			sum -= arr[start++];
		} else {
			sum -= arr[start++];
		}
	}

	cout << answer << '\n';
}