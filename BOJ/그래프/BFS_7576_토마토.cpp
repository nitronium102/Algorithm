// 골드5
// Created by KangMinji on 2023-02-14.
// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 1001;
typedef pair<int, int> ci;

int m, n; // col, row
int board[MAX][MAX];
int time[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<ci> ripe;

int ans = 0;

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs() {
	queue<ci> q;

	for (ci tomato: ripe) {
		q.push(tomato);
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int t = time[x][y];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isValid(nx, ny) && board[nx][ny] == 0) {
				q.push({nx, ny});
				time[nx][ny] = t + 1;
				board[nx][ny] = 1;
				ans = max(ans, time[nx][ny]);
			}
		}
	}
}

int main() {

	// 입력
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				ripe.push_back({i, j});
				time[i][j] = 0;
			}
		}
	}

	// 연산
	bfs();
	bool isRipe = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!board[i][j]) {
				isRipe = false;
				break;
			}
		}
	}

	if (!isRipe){
		cout << -1 << "\n";
	} else {
		cout << ans << "\n";
	}
}