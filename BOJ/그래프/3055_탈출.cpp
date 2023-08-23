// 골드4
// Created by KangMinji on 2023-08-09.
// https://www.acmicpc.net/problem/3055

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ci;

int n, m;
char board[51][51];
int waterDist[51][51];
int dochiDist[51][51];;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<ci> water;
queue<ci> dochi;

void spreadWater() {
	while (!water.empty()) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 'X' || board[nx][ny] == 'D') continue;
			if (waterDist[nx][ny] >= 0) continue;
			water.push({nx, ny});
			waterDist[nx][ny] = waterDist[x][y] + 1;
		}
	}
}

void spreadDochi() {
	while (!dochi.empty()) {
		int x = dochi.front().first;
		int y = dochi.front().second;
		dochi.pop();

		if (board[x][y] == 'D') {
			cout << dochiDist[x][y];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dochiDist[nx][ny] >= 0 || board[nx][ny] == 'X' || board[nx][ny] == '*') continue;
			if (waterDist[nx][ny] != -1 && waterDist[nx][ny] <= dochiDist[x][y] + 1) continue;
			dochi.push({nx, ny});
			dochiDist[nx][ny] = dochiDist[x][y] + 1;
		}
	}
	cout << "KAKTUS";
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		fill(waterDist[i], waterDist[i] + m, -1);
		fill(dochiDist[i], dochiDist[i] + m, -1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == '*') {
				waterDist[i][j] = 0;
				water.push({i, j});
			}
			if (board[i][j] == 'S') {
				dochiDist[i][j] = 0;
				dochi.push({i, j});
			}
		}
	}

	// 연산
	spreadWater();
	spreadDochi();
}