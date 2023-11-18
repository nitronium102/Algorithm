// 골드2
// Created by KangMinji on 2023-07-15.
// https://www.acmicpc.net/problem/11967

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

int n, m;
vector<ci> adj[101][101];
bool light[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool canVisit(ci next) {
	for (int i = 0; i < 4; i++) {
		int nx = next.first + dx[i];
		int ny = next.second + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
		if (visited[nx][ny]) return true;
	}
	return false;
}

void bfs() {
	queue<ci> q;

	q.push({1, 1});
	light[1][1] = true;
	visited[1][1] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 불 켤 수 있는 경우 -> 켜준다
		for (ci next: adj[x][y]) {
			if (visited[next.first][next.second]) continue;
			if (canVisit(next)) { // 현재 위치에서 방문 가능한지
				q.push(next);
				visited[next.first][next.second] = true;
			}
			light[next.first][next.second] = true; // 불은 켜기
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (visited[nx][ny] || !light[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m;

	int x, y, a, b;
	while (m--) {
		cin >> x >> y >> a >> b;
		adj[x][y].push_back({a, b});
	}

	// 연산
	bfs();

	// 출력
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			answer += light[i][j];
		}
	}
	cout << answer;
}