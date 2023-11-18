// 브론즈2
// Created by KangMinji on 2023-03-29.
// https://www.acmicpc.net/problem/2858

#include <iostream>

using namespace std;

int main() {
	int r, b;

	// 입력
	cin >> r >> b;

	// 연산
	for (int i = b; i >= 1; i--) {
		if (b % i == 0) {
			int l = i + 2;
			int w = b / i + 2;
			if (l * 2 + w * 2 - 4 == r) {
				cout << l << ' ' << w << '\n';
				return 0;
			}
		}
	}
}