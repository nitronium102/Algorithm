// 실버1 / 이분탐색
// Created by KangMinji on 2023-02-06.
// https://www.acmicpc.net/problem/1074

#include <iostream>
#include <cmath>

using namespace std;
const long MAX = 32768;

int n, r, c;
int cnt = 0;

void findVisitCnt(int x, int y, int len) {
	if (x == r && y == c) {
		cout << cnt << "\n";
		return;
	}

	// 해당 사분면 내에 좌표 존재
	if (x <= r && r < x + len && y <= c && c < y + len) {
		int half = len / 2;
		findVisitCnt(x, y, half);
		findVisitCnt(x, y + half, half);
		findVisitCnt(x + half, y, half);
		findVisitCnt(x + half, y + half, half);
	} else {
		cnt += len * len;
	}
}

int main() {
	// 입력
	cin >> n >> r >> c;

	// 연산
	findVisitCnt(0, 0, pow(2, n));

}