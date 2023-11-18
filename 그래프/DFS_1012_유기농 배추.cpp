// 실버2 / DFS
// Created by KangMinji on 2023-02-13.
// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int MAX = 51;

int m, n;
int board[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isValid(nx, ny) && !visited[nx][ny] && board[nx][ny] == 1) {
			dfs(nx, ny);
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
		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(board));

		while (k--) {
			cin >> y >> x;
			board[x][y] = 1;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] && !visited[i][j]) {
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << "\n";
	}
}