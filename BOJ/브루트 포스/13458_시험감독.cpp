// 브론즈2
// Created by KangMinji on 2023-03-29.
// https://www.acmicpc.net/problem/13458

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, b, c;

	// 입력
	cin >> n;
	vector<int> student(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> student[i];
	}
	cin >> b >> c;

	// 연산
	long long answer = n;
	for (int i = 0; i < n; i++) {
		student[i] -= b;
		if (student[i] > 0) {
			answer += student[i] / c;
			if (student[i] % c) {
				answer++;
			}
		}
	}

	// 출력
	cout << answer << "\n";
}