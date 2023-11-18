// 골드5
// Created by KangMinji on 2023-07-05.
// https://www.acmicpc.net/problem/16987

#include <iostream>

using namespace std;

int n;
int egg[9];
int weight[9];
int answer = 0;

void backtracking(int idx) {
	if (idx == n + 1) { // n으로 하면 마지막 계란으로는 못 침
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (egg[i] <= 0) cnt++;
		}
		answer = max(answer, cnt);
		return;
	}

	// 손에 든 계란이 이미 깨지면 다른 계란 안 치고 넘어간다
	if (egg[idx] <= 0) {
		backtracking(idx + 1);
		return;
	}

	bool is_broken = false;
	for (int i = 1; i <= n; i++) {
		if (i == idx || egg[i] <= 0) continue;
		is_broken = true;

		egg[idx] -= weight[i];
		egg[i] -= weight[idx];
		backtracking(idx + 1);
		egg[idx] += weight[i];
		egg[i] += weight[idx];
	}

	// 깨지지 않은 다른 계란이 없는 경우(모두 깨진 경우)
	if (!is_broken)
		backtracking(idx + 1);
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> egg[i] >> weight[i];

	// 연산
	backtracking(1);

	// 출력
	cout << answer;
}