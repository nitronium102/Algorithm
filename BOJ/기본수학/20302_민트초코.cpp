// 골드4
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/20302

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e5;

vector<int> prime(MAX + 1, 0);
vector<int> exponent(MAX + 1, 0);

void makePrime() {

	for (int i = 2; i * i <= MAX; i++) {
		if (prime[i]) {
			continue;
		}
		for (int j = i * i; j <= MAX; j += i) {
			if (!prime[j]) {
				prime[j] = i;
			}
		}
	}
}

void countExp(int num, int cnt) {
	while (prime[num]) {
		num /= prime[num];
		exponent[prime[num]] += cnt;
	}
	exponent[num] += cnt;
}

bool isRational() {
	for (int i = 2; i <= MAX; i++) {
		if (exponent[i] < 0) {
			return true;
		}
	}
	return false;
}

int main() {
	int n, num;
	char op;

	makePrime();

	// 입력
	cin >> n >> num;

	if (num == 0) {
		cout << "mint chocolate\n";
		return 0;
	}

	// 연산
	countExp(abs(num), 1); // 처음 수

	for (int i = 1; i < n; i++) {
		cin >> op >> num;

		if (num == 0) {
			cout << "mint chocolate\n";
			return 0;
		}
		if (op == '*') {
			countExp(abs(num), 1);
		} else {
			countExp(abs(num), -1);
		}
	}

	// 출력
	if (isRational()) {
		cout << "toothpaste\n";
	} else {
		cout << "mint chocolate\n";
	}
}