// 실버4
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/9613

#include <iostream>
#include <vector>
using namespace std;

int findGCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return findGCD(b, a % b);
}

long long calcGCDSum(vector<int> &v) {
	long long sum = 0; // n * (n-1) / 2 * gcd = 1e4 * 1e6
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			sum += findGCD(max(v[i], v[j]), min(v[i], v[j]));
		}
	}
	return sum;
}

int main() {
	int t, n;

	// 입력
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		// 연산
		cout << calcGCDSum(v) << '\n';
	}
}