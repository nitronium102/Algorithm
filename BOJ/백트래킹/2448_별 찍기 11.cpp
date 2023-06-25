// 골드4
// Created by KangMinji on 2023-06-21.
// https://www.acmicpc.net/problem/2448

#include <iostream>
using namespace std;
const int MAX = 1024 * 3 + 1;

char board[MAX][2 * MAX];

void makeTriangle(int x, int y) {
	board[x][y] = '*'; // 1행
	board[x+1][y-1] = board[x+1][y+1] = '*'; // 2행

	// 3행
	for (int i=y-2; i<= y+2; i++)
		board[x+2][i] = '*';
}

void func(int x, int y, int n) {
	if (n == 3) {
		makeTriangle(x, y);
		return;
	}
	int half = n / 2;
	func(x, y, half);
	func(x + half, y - half, half);
	func(x + half, y + half, half);
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	// 입력
	cin >> n;

	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + 2 * n, ' ');

	// 연산
	// col 전체가 2n-2
	func(0, n - 1, n);

	// 출력
	for (int i=0; i<n; i++){
		for (int j=0; j<2*n-1; j++){
			cout << board[i][j];
		}
		cout << "\n";
	}
}