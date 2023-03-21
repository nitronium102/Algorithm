// 실버1
// Created by KangMinji on 2023-03-21.
// https://www.acmicpc.net/problem/14888

#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
vector<int> op;
int lmax = -1e9 - 1;
int lmin = 1e9 + 1;

int caLcNum(int n1, int n2, int op) {
	switch (op) {
		case 0:
			return n1 + n2;
		case 1:
			return n1 - n2;
		case 2:
			return n1 * n2;
		case 3:
			return n1 / n2;
	}
}

void calcMinMax(int result, int idx, int n) {
	if (idx == n) {
		lmax = max(lmax, result);
		lmin = min(lmin, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i]) {
			op[i]--;
			calcMinMax(caLcNum(result, num[idx], i), idx + 1, n);
			op[i]++;
		}
	}
}

int main() {
	int n;

	// 입력
	cin >> n;
	num.assign(n, 0);
	op.assign(4, 0);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	// 연산
	calcMinMax(num[0], 1, n);

	// 출력
	cout << lmax << '\n' << lmin << '\n';
}