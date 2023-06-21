// 골드5
// Created by KangMinji on 2023-06-21.
// https://www.acmicpc.net/problem/2447

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board;

void func(int x, int y, int n) {
	if (n == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) continue;
				board[x + i][y + j] = '*';
			}
		}
		return;
	}
	int size = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			func(x + i * size, y + j * size, size);
		}
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	// 입력
	cin >> n;

	// 연산
	board.assign(n, vector<char>(n, ' '));
	func(0, 0, n);

	// 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

