// 🔥골드5
// Created by KangMinji on 2023-02-14.
// https://www.acmicpc.net/problem/22352

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int n, m;
int before[31][31];
int after[31][31];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int cx, int cy, int b_color, int a_color) {
	queue<ci> q;
	q.push({cx, cy});
	before[cx][cy] = a_color;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isValid(nx, ny) && before[nx][ny] == b_color) {
				before[nx][ny] = a_color;
				q.push({nx, ny});
			}
		}
	}
}

int main() {

	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> before[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> after[i][j];
		}
	}

	// 연산
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!flag && before[i][j] != after[i][j]) {
				bfs(i, j, before[i][j], after[i][j]);
				flag = true;
			}
		}
	}

	// 출력
	bool is_vaccine = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (before[i][j] != after[i][j]) {
				is_vaccine = false;
				break;
			}
		}
	}

	if (is_vaccine) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}