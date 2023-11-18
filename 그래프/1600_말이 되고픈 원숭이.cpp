// 골드3
// Created by KangMinji on 2023-06-25.
// https://www.acmicpc.net/problem/1600
// 벽 부수고 이동하기와 비슷한 기믹

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

int n, m, k;
int board[201][201];
int dist[201][201][31]; // {x, y}에 k번 능력을 사용함
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dgx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dgy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

void bfs() {
	queue<tp> q;

	q.push({0, 0, 0});
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y][z] - 1;
			return;
		}

		if (z < k) { // 말처럼 행동할 수 있는 경우
			for (int i = 0; i < 8; i++) {
				int nx = x + dgx[i];
				int ny = y + dgy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[nx][ny] || dist[nx][ny][z + 1]) continue;
				dist[nx][ny][z + 1] = dist[x][y][z] + 1;
				q.push({nx, ny, z + 1});
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] || dist[nx][ny][z]) continue;
			dist[nx][ny][z] = dist[x][y][z] + 1;
			q.push({nx, ny, z});
		}
	}
	cout << -1;
}

int main() {

	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> k >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}

	// 연산 & 출력
	bfs();
}
