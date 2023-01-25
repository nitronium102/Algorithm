// 골드5
// Created by KangMinji on 2023-01-24.
// https://www.acmicpc.net/problem/1107
// https://yjios.tistory.com/8

#include <iostream>
#include <vector>

using namespace std;

int buttons[10];

bool check(int num) {
	string s = to_string(num);

	for (char c: s) {
		if (buttons[c - '0'] == -1) {
			return false;
		}
	}
	return true;
}

int main() {
	int N, M, input;

	for (int i = 0; i < 10; i++) {
		buttons[i] = i;
	}

	// 입력
	cin >> N >> M;

	while (M--) {
		cin >> input;
		buttons[input] = -1;
	}

	string target = to_string(N);

	// 고장난 버튼이 없는 경우
	if (M == 0) {
		cout << target.length();
		return 0;
	}

	// 1) +, -로 이동
	int ans = abs(N - 100);

	// 2) 숫자 이동
	for (int i = 0; i <= 1e6; i++) {
		if (check(i)) {
			// (자릿수) + ( +/- 횟수 )
			int tmp = to_string(i).length() + abs(N - i);
			ans = min(ans, tmp);
		}
	}
	// 출력
	cout << ans << "\n";
}