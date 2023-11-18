// 브론즈1
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/2609

#include <iostream>

using namespace std;

int findGCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return findGCD(b, a % b);
}

int main() {
	int a, b;

	// 입력
	cin >> a >> b;

	// 연산
	if (a < b) {
		swap(a, b);
	}
	int gcd = findGCD(a, b);
	int lcm = a * b / gcd;

	// 출력
	cout << gcd << '\n' << lcm << "\n";
}