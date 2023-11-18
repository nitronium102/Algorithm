// 골드4
// Created by KangMinji on 2023-06-26.
// https://www.acmicpc.net/problem/15683

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

int n, m;
int ans = 0;
int board[9][9];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 반시계방향
vector<ci> camera;

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}

int count() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void check(int x, int y, int dir) {
	dir %= 4;

	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) || board[x][y] == 6) return;
		if (board[x][y] != 0) continue;
		board[x][y] = 7;
	}
}

void solve(int idx, int limit) {
	if (idx == limit) {
		int cnt = count();
		ans = min(ans, cnt);
		return;
	}

	int backup[9][9];
	int x = camera[idx].first;
	int y = camera[idx].second;

	for (int dir = 0; dir < 4; dir++) {
		// 1) board를 변경하기 전에 backup
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				backup[i][j] = board[i][j];

		// 2) cctv 종류별 조치
		int type = board[x][y];
		if (type == 1) {
			check(x, y, dir);
		} else if (type == 2) {
			check(x, y, dir);
			check(x, y, dir + 2);
		} else if (type == 3) {
			check(x, y, dir);
			check(x, y, dir + 1);
		} else if (type == 4) {
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
		} else {
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
			check(x, y, dir + 3);
		}

		// 3) 수행
		solve(idx + 1, limit);

		// 종료 후 초기화
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				board[i][j] = backup[i][j];
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6)
				camera.push_back({i, j});
			if (board[i][j] == 0)
				ans++;
		}
	}

	// 연산
	solve(0, camera.size());

	// 출력
	cout << ans;
}