// 실버4
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/1026

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;

	// 입력
	cin >> n;
	vector<int> a(n, 0);
	vector<int> b(n, 0);
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	for (int i=0; i<n; i++){
		cin >> b[i];
	}

	// 연산
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	int answer = 0;
	for (int i=0; i<n; i++){
		answer += a[i] * b[i];
	}

	// 출력
	cout << answer << '\n';
}