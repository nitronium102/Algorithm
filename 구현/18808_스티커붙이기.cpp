// 골드3
// Created by KangMinji on 2023-09-01.
// https://www.acmicpc.net/problem/18808

#include <iostream>

using namespace std;

int n, m, k;
int r, c;
int board[41][41];
int sticker[11][11];
int tmp_sticker[11][11];

void rotate() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp_sticker[j][r - 1 - i] = sticker[i][j];
		}
	}

	swap(r, c);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sticker[i][j] = tmp_sticker[i][j];
		}
	}
}

bool check(int x, int y) {
	// 스티커 붙일 자리가 비어있는지 확인
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[x + i][y + j] == 1 && sticker[i][j] == 1)
				return false;
		}
	}
	return true;
}

void stick(int x, int y) {
	// 스티커 붙이기
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j] == 1)
				board[x + i][y + j] = 1;
		}
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	while (k--) {
		// 스티커 입력
		cin >> r >> c;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}

		bool flag = false;
		for (int dir = 0; dir < 4; dir++) {
			for (int i = 0; i <= n - r; i++) {
				if (flag) break;
				for (int j = 0; j <= m - c; j++) {
					if (check(i, j)) {
						flag = true;
						stick(i, j);
						break;
					}
				}
			}
			if (flag) break;
			rotate();
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answer += board[i][j];
		}
	}

	cout << answer << "\n";
}