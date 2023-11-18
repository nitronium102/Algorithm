// 브론즈1
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/2309

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> height(9, 0);
	int sum = 0;

	// 입력
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}
	sort(height.begin(), height.end());

	// 연산
	for (int i = 0; i < 9; i++) {
		int n1 = height[i];
		for (int j = i + 1; j < 9; j++) {
			int n2 = height[j];

			if (sum - (n1 + n2) == 100) {
				for (int v: height) {
					if (v == n1 || v == n2) {
						continue;
					}
					cout << v << "\n";
				}
				return 0;
			}
		}
	}
}