// 실버1 / BFS
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/7562

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
const int MAX = 301;
typedef pair<int, int> ci;

int l;
bool visited[MAX][MAX];
int dist[MAX][MAX];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, 2, 1, -1, -2};

bool isValid(int x, int y) {
	return x >= 0 && x < l && y >= 0 && y < l;
}

void bfs(int x, int y, int tx, int ty) {
	queue<ci> q;
	q.push({x, y});
	visited[x][y] = true;
	dist[x][y] = 0;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		int d = dist[cx][cy];
		q.pop();

		if (cx == tx && cy == ty) {
			cout << dist[cx][cy] << "\n";
			break;
		}

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (isValid(nx, ny) && !visited[nx][ny]) {
				q.push({nx, ny});
				dist[nx][ny] = d + 1;
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	int t, cx, cy, tx, ty;

	// 입력
	cin >> t;
	while (t--) {
		cin >> l >> cx >> cy >> tx >> ty;

		memset(visited, false, sizeof(visited));
		memset(dist, 0, sizeof(dist));

		bfs(cx, cy, tx, ty);
	}
}