// 골드4
// Created by KangMinji on 2023-06-18.
// https://www.acmicpc.net/problem/4179

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int MAX = 1001;

char board[MAX][MAX];
int fire_dist[MAX][MAX];
int jihun_dist[MAX][MAX];
queue<ci> q_fire; // 불이 하나라는 조건 X
queue<ci> q_jihun;
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void spreadFire() {
	while (!q_fire.empty()) {
		int x = q_fire.front().first;
		int y = q_fire.front().second;
		q_fire.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (fire_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			fire_dist[nx][ny] = fire_dist[x][y] + 1;
			q_fire.push({nx, ny});
		}
	}
}

void spreadJihun() {
	while (!q_jihun.empty()) {
		int x = q_jihun.front().first;
		int y = q_jihun.front().second;
		q_jihun.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << jihun_dist[x][y] + 1;
				return;
			}
			if (jihun_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= jihun_dist[x][y] + 1) continue;
			jihun_dist[nx][ny] = jihun_dist[x][y] + 1;
			q_jihun.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE";
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		fill(fire_dist[i], fire_dist[i] + m, -1);
		fill(jihun_dist[i], jihun_dist[i] + m, -1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'J') {
				jihun_dist[i][j] = 0;
				q_jihun.push({i, j});
			}
			if (board[i][j] == 'F') {
				fire_dist[i][j] = 0;
				q_fire.push({i, j});
			}
		}
	}

	// 연산
	spreadFire();
	spreadJihun();
}
