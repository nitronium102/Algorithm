// 실버2
// Created by KangMinji on 2023-06-20.
// https://www.acmicpc.net/problem/1780

#include <iostream>
#include <vector>

using namespace std;

vector<int> cnt(3, 0);
vector<vector<int>> board;

bool check(int x, int y, int n) {
	int target = board[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[i][j] != target)
				return false;
		}
	}
	return true;
}

void recursion(int x, int y, int n) {
	if (check(x, y, n)) {
		cnt[board[x][y]]++;
		return;
	}
	int size = n/3;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){ // x, y를 더해줬어야 함
			recursion(x + i * size, y + j * size, size);
		}
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;
	board.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			board[i][j] += 1;
		}
	}

	recursion(0, 0, n);

	// 출력
	for (int i=0; i<3; i++)
		cout << cnt[i] << '\n';
}