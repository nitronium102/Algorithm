// 브론즈1
// Created by KangMinji on 2023-02-01.
// https://www.acmicpc.net/problem/14659

#include <iostream>
using namespace std;

int main() {
	int n, max_height = -1, height;
	int ans = 0;
	int sum = 0;

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> height;
		if (max_height < height){
			max_height = height;
			ans = max(ans, sum);
			sum = 0;
		} else {
			sum++;
		}
	}

	// 마지막에 한 번 더 필요
	ans = max(ans, sum);

	// 출력
	cout << ans << "\n";
}