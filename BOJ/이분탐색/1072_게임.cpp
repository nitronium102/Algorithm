// 실버3
// Created by KangMinji on 2023-08-09.
// https://www.acmicpc.net/problem/1072

#include <bits/stdc++.h>

using namespace std;

int main() {
	long x, y, z;
	long cnt = -1;

	// 입력
	cin >> x >> y;

	// 연산
	z = (y * 100) / x;

	if (z >= 99) {
		cout << cnt;
		return 0;
	}

	int left = 0;
	int right = x; // x번 만큼 게임 해보고도 안 바뀌면 답 없음

	while (left < right) {
		long mid = (left + right) / 2;
		long tmp = ((y + mid) * 100) / (x + mid);
		if (tmp > z) { // 오버인 경우
			right = mid; // 왼쪽에 더 최적인 값이 있기 때문!!
		} else { // 같은 경우 (다운인 경우는 발생하지 않음)
			left = mid + 1;
		}
	}
	// left == right일 때 탈출
	cout << left << '\n';


	/*
	 * mid를 살리는 경우 -> s==e일 때 탈출
	 * mid를 계속 버리면 뒤집힘 -> s>e일 때 탈출
	 * */
}