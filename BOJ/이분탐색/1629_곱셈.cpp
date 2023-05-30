// 실버1 / 분할정복
// Created by KangMinji on 2023-02-06.
// https://www.acmicpc.net/problem/1629

#include <iostream>

using namespace std;

long long a, b, c, half;

/*
 * base^n
 * (짝수) base(n/2)*base(n/2)
 * (홀수) base(n-1/2)*base(n-1/2)*base
 */
long long power(long long exp) {
	if (exp == 0) {
		return 1;
	}
	if (exp == 1) {
		return a % c;
	}

	half = power(exp / 2) % c;

	if (exp % 2 == 0) {
		return half * half % c;
	}
	return half * half % c * a % c;
}

int main() {

	// 입력
	cin >> a >> b >> c;

	// 연산
	// A^B % C
	cout << power(b);

}