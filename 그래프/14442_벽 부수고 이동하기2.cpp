// 골드3
// Created by KangMinji on 2023-06-26.
// https://www.acmicpc.net/problem/14442

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

int n, m, k;
char board[1001][1001];
int dist[1001][1001][11];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
	queue<tp> q;

	dist[0][0][0] = 1;
	q.push({0, 0, 0});

	while (!q.empty()) {
		int x, y, cnt;
		tie(x, y, cnt) = q.front();
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y][cnt];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			// 1) 벽 부수는 경우
			if (cnt < k && board[nx][ny] == '1' && dist[nx][ny][cnt + 1] == 0) {
				dist[nx][ny][cnt + 1] = dist[x][y][cnt] + 1;
				q.push({nx, ny, cnt + 1});
			}
			// 2) 벽 안 부수는 경우
			if (board[nx][ny] == '0' && dist[nx][ny][cnt] == 0) {
				dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
				q.push({nx, ny, cnt});
			}
		}
	}
	cout << -1;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}

	bfs();

//	int ans = 1e9;
//	for (int i = 0; i <= k; i++) {
//		if (dist[n - 1][m - 1][i]) {
//			ans = min(ans, dist[n - 1][m - 1][i]);
//		}
//	}
//	if (ans == 1e9) cout << -1;
//	else cout << ans;
}