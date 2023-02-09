// 실버1 / 이분탐색
// Created by KangMinji on 2023-02-06.
// https://www.acmicpc.net/problem/1992

#include <iostream>

using namespace std;

char board[64][64];

void checkBoard(int x, int y, int length) {
	char color = board[x][y];
//	if (length == 1){
//		cout << color;
//		return;
//	}

	int half = length / 2;
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			// 영상 분리 필요
			if (color != board[i][j]) {
				cout << "(";
				checkBoard(x, y, half);
				checkBoard(x, y + half, half);
				checkBoard(x + half, y, half);
				checkBoard(x + half, y + half, half);
				cout << ")";
				return;
			}
		}
	}
	// 하나의 색으로 통일된 경우
	cout << color;

}

int main() {
	int n;
	string s;

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			board[i][j] = s[j];
		}
	}

	// 연산
	checkBoard(0, 0, n);
}