// 11047
// Created by KangMinji on 2023-02-01.
// https://www.acmicpc.net/problem/11047

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	vector<int> arr;

	// 입력
	cin >> n >> k;
	arr.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 연산
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		cnt += k / arr[i];
		k %= arr[i];
	}

	// 출력
	cout << cnt << "\n";
}