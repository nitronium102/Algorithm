// 실버2
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/2168

#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	int x, y;

	// 입력
	cin >> x >> y;

	// 출력
	cout << x + y - gcd(max(x, y), min(x, y)) << '\n';
}