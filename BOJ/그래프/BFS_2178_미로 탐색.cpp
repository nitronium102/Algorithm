// 실버1 / BFS
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int n, m;
int board[101][101];
bool visited[101][101];
int dist[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y) {
	return x >= 0 && x <n && y >= 0 && y < m && board[x][y] == 1;
}

void bfs(int x, int y) {
	queue<ci> q;
	q.push({x, y});
	visited[x][y] = true;
	dist[x][y] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		int d = dist[cx][cy];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (isValid(nx, ny) && !visited[nx][ny]) {
				dist[nx][ny] = d + 1;
				q.push({nx, ny});
				visited[nx][ny] = true;
			}
		}
	}

}

int main() {
	string row;

	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> row;
		for (int j = 0; j < m; j++) {
			board[i][j] = row[j] - '0';
		}
	}

	// 연산
	bfs(0, 0);

	// 출력
	cout << dist[n-1][m-1];
}