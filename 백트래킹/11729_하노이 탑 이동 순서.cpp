// 실버1
// Created by KangMinji on 2023-06-20.
// https://www.acmicpc.net/problem/11729

#include <iostream>
using namespace std;

void func(int a, int b, int n){
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	func(a, 6-a-b, n-1);
	cout << a << ' ' << b << '\n';
	func(6-a-b, b, n-1);
	return;
}

int main() {
	int n;

	cin >> n;
	cout << (1 << n) - 1 << "\n";
	func(1, 3, n);
}