// 실버2 / BFS
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <queue>

using namespace std;
const int MAX = 51;
typedef pair<int, int> ci;

int m, n;
vector<vector<int>> board;
vector<vector<int>> visited;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y) {
	queue<ci> q;
	q.push({x, y});
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (isValid(nx, ny) && !visited[nx][ny] && board[nx][ny] == 1) {
				q.push({nx, ny});
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	int t, k, x, y;

	// 입력
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;

		// 초기화
		board.assign(MAX, vector<int>(MAX, 0));
		visited.assign(MAX, vector<int>(MAX, 0));

		while (k--) {
			cin >> y >> x;
			board[x][y] = 1;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] && !visited[i][j]) {
					ans++;
					bfs(i, j);
				}
			}
		}
		cout << ans << "\n";
	}
}