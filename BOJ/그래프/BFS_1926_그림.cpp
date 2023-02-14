// 실버1 / BFS
// Created by KangMinji on 2023-02-12.
// https://www.acmicpc.net/problem/1926

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int n, m;
int board[501][501];
bool visited[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt = 0, max_area = 0;

bool isValid(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs(int x, int y) {
	queue<ci> q;
	q.push({x, y});
	visited[x][y] = true;

	int area = 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!isValid(nx, ny)){
				continue;
			}
			if (board[nx][ny] == 1 && !visited[nx][ny]){
				q.push({nx, ny});
				visited[nx][ny] = true;
				area++;
			}
		}
	}
	max_area = max(max_area, area);
}

int main() {

	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 연산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && !visited[i][j]){
				cnt++;
				bfs(i, j);
			}
		}
	}


	// 출력
	cout << cnt << "\n" << max_area;
}