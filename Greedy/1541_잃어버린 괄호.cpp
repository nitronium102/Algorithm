// 실버2
// Created by KangMinji on 2023-09-09.
// https://www.acmicpc.net/problem/1541

#include <iostream>
using namespace std;

int before = 0;
int after = 0;
bool isMinus = false;
int num = 0;

void addNum() {
	if (!isMinus) {
		before += num;
	} else {
		after += num;
	}
	num = 0;
}

int main() {
	string input;

	cin >> input;

	// +와 -만으로 이루어져 있음
	// -가 나오면 그 이후의 수 모두 묶어준다
	for (char c : input) {
		if (isdigit(c)) {
			num *= 10;
			num += c - '0';
		} else {
			addNum();

			if (c == '-'){
				isMinus = true;
			}
		}
	}

	// 마지막 숫자
	addNum();

	// 출력
	cout << before - after;
}