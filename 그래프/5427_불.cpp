// 골드4
// Created by KangMinji on 2023-05-30.
// https://www.acmicpc.net/problem/5427

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int w, h;
vector<vector<char>> board;
vector<vector<int>> fire_time;
vector<vector<int>> play_time;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isRange(int x, int y) {
	return x >= 0 && x < h && y >= 0 && y < w;
}

void spreadFire(queue<ci> &fire) {
	while (!fire.empty()) {
		int x = fire.front().first;
		int y = fire.front().second;
		fire.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 1) 범위에서 벗어난 경우
			if (!isRange(nx, ny)) {
				continue;
			}
			// 2) 이미 불이 붙은 칸이거나 벽인 경우
			if (fire_time[nx][ny] >= 0 || board[nx][ny] == '#') {
				continue;
			}
			fire_time[nx][ny] = fire_time[x][y] + 1;
			fire.push({nx, ny});
		}
	}
}

void playGame(ci start) {
	queue<ci> q;

	// 초기화
	q.push(start);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isRange(nx, ny)) { // 미로 탈출
				cout << play_time[x][y] + 1 << "\n";
				return;
			}

			// 이미 방문했거나 벽이 있는 경우
			if (play_time[nx][ny] >= 0 || board[nx][ny] == '#') {
				continue;
			}
			// 가려는 곳에 불이 있는 경우
			if (fire_time[nx][ny] >= 0 && play_time[x][y] + 1 >= fire_time[nx][ny]) {
				continue;
			}
			play_time[nx][ny] = play_time[x][y] + 1;
			q.push({nx, ny});
		}
	}

	cout << "IMPOSSIBLE\n";
}

int main() {
	int t;

	// 입려
	cin >> t;
	while (t--) {
		cin >> w >> h;

		board.assign(h, vector<char>(w, '.'));
		fire_time.assign(h, vector<int>(w, -1));
		play_time.assign(h, vector<int>(w, -1));

		ci start;
		queue<ci> fire;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
				if (board[i][j] == '@') {
					start = {i, j};
					play_time[i][j] = 0;
				}
				if (board[i][j] == '*') {
					fire.push({i, j});
					fire_time[i][j] = 0;
				}
			}
		}

		// 연산
		// 1) 먼저 불을 지르면서 방화 시간 저장
		spreadFire(fire);
		// 2) 지훈이가 돌면서 도달 시간 <= 전파 시간인지 확인
		playGame(start);
	}
}