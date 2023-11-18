qm// 브론즈2
// Created by KangMinji on 2023-02-01.
// https://www.acmicpc.net/problem/5585

#include <iostream>
using namespace std;

int main() {
	int n;
	int money[6] = {500, 100, 50, 10, 5, 1};

	// 입력
	cin >> n;

	// 연산
	n = 1000 - n;
	int ans = 0;
	for (int i=0; i<6; i++){
		ans += n/money[i];
		n %= money[i];
	}

	// 출력
	cout << ans << "\n";
}
