// 골드5 / BFS
// Created by KangMinji on 2023-02-14.
// https://www.acmicpc.net/problem/10026

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 101;
typedef pair<int, int> ci;

int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int cx, int cy, vector<vector<char>> &board) {
	queue<ci> q;
	q.push({cx, cy});
	char color = board[cx][cy];
	board[cx][cy] = '#';

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isValid(nx, ny) && board[nx][ny] == color) {
				board[nx][ny] = '#';
				q.push({nx, ny});
			}
		}
	}
}

int main() {
	// 입력
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n, ' '));
	vector<vector<char>> blind_board(n, vector<char>(n, ' '));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			blind_board[i][j] = board[i][j];
			// 색맹인 경우 R, B로만 구분
			if (board[i][j] == 'G') {
				blind_board[i][j] = 'R';
			}
		}
	}

	// 연산
	int n_ans = 0, b_ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != '#') {
				bfs(i, j, board);
				n_ans++;
			}

			if (blind_board[i][j] != '#') {
				bfs(i, j, blind_board);
				b_ans++;
			}
		}
	}

	// 출력
	cout << n_ans << " " << b_ans << "\n";
}