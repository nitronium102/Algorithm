// 실버2
// Created by KangMinji on 2023-01-24.
// https://www.acmicpc.net/problem/18111

#include <iostream>
using namespace std;
const int MAX = 501;
typedef pair<int, int> ci;

int N, M, B;
int board[MAX][MAX];

ci solve() {
	int min_time = 6.4 * 1e7 * 2;
	int max_height = -1;

	for (int h = 256; h >= 0; h--) {
		int del_cnt = 0;
		int add_cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int diff = (board[i][j] - h);
				if (diff > 0) {
					del_cnt += diff;
				} else if (diff < 0) {
					add_cnt -= diff;
				}
			}
		}

		// 채울 수 없는 경우
		if (del_cnt + B < add_cnt){
			continue;
		}

		// 걸린 시간 계산
		int time = del_cnt * 2 + add_cnt;
		if (time < min_time) {
			min_time = time;
			max_height = h;
		}
	}
	return {min_time, max_height};
}

int main() {

	// 입력
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	// 연산 & 출력
	cout << solve().first << " " << solve().second << "\n";
}