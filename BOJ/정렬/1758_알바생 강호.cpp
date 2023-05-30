// 실버4
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/1758

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;

	// 입력
	cin >> n;
	vector<int> tip(n, 0);
	for (int i=0; i<n; i++){
		cin >> tip[i];
	}

	// 연산
	sort(tip.begin(), tip.end(), greater<>());

	// 출력
	long long answer = 0;
	for (int i=0; i<n; i++){
		if (tip[i] - i > 0) {
			answer += tip[i] - i;
		}
	}

	cout << answer << "\n";
}
