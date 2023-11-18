// 골드1
// Created by KangMinji on 2023-07-11.
// https://www.acmicpc.net/problem/16933

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;
string board[1002];
int dist[1002][1002][12][2]; // 낮 = 0, 밤 = 1
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
	queue<tuple<int, int, int, int>> q;

	// 초기화
	q.push({0, 0, 0, 0});
	dist[0][0][0][0] = 1; // 시작하는 칸도 포함

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int c = get<2>(q.front());
		int d = get<3>(q.front());
		q.pop();

		if (x == n - 1 && y == m - 1) { // 끝나는 칸도 포함
			cout << dist[x][y][c][d] << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// 1) 이동할 수 있는 경우 -> 그냥 가기
			if (board[nx][ny] == '0') {
				int nd = 1 - d;
				if (dist[nx][ny][c][nd] > 0) continue;
				dist[nx][ny][c][nd] = dist[x][y][c][d] + 1;
				q.push({nx, ny, c, nd});
			} else {
				// 2) 벽을 부수는 경우
				// 2-1) 벽 못 부수는 경우
				if (c == k) continue;
				// 2-2) 낮인 경우
				if (d == 0) {
					int nc = c + 1;
					int nd = 1 - d;
					if (dist[nx][ny][nc][nd] > 0) continue;
					dist[nx][ny][nc][nd] = dist[x][y][c][d] + 1;
					q.push({nx, ny, nc, nd});
				} else {
					// 2-3) 밤인 경우 -> day만 바꾸어야 한다
					int nd = 1 - d;
					if (dist[x][y][c][nd] > 0) continue;
					dist[x][y][c][nd] = dist[x][y][c][d] + 1;
					q.push({x, y, c, nd});
				}
			}
		}
	}
	cout << -1 << '\n';
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	// 연산
	bfs();
}
