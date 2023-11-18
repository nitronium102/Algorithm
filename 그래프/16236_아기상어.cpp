// 글도3
// Created by KangMinji on 2023-06-07.
// https://www.acmicpc.net/problem/16236

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int n, cnt = 0;
int shark_size = 2;
int board[21][21];
vector<vector<int>> dist;
queue<ci> q; // 상어의 위치
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct cmp {
	bool operator()(ci &a, ci &b) {
		// 1) 거리순
		if (dist[a.first][a.second] != dist[b.first][b.second]) {
			return dist[a.first][a.second] > dist[b.first][b.second];
		}
		// 2) 위쪽 먼저
		if (a.first != b.first) {
			return a.first > b.first;
		}
		// 3) 왼쪽 먼저
		if (a.second != b.second) {
			return a.second > b.second;
		}
	}
};

bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(priority_queue<ci, vector<ci>, cmp> &pq) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!check(nx, ny)) {
				continue;
			}
			if (dist[nx][ny] != -1) {
				continue;
			}
			// 물고기 크기에 따라 분류
			// 1) 더 큰 경우
			if (board[nx][ny] > shark_size) {
				continue;
			}
			// 2) 같은 경우
			if (board[nx][ny] == shark_size || board[nx][ny] == 0){
				q.push({nx, ny});
				dist[nx][ny] = dist[x][y] + 1;
			}
			// 3) 크기가 더 작은 경우
			else {
				q.push({nx, ny});
				dist[nx][ny] = dist[x][y] + 1;
				pq.push({nx, ny});
			}
		}
	}
}

int solve() {
	int time = 0;
	int cnt_ate = 0;
	while (cnt--) {
		// 1) 초기화
		priority_queue<ci, vector<ci>, cmp> pq; // 물고기
		dist.assign(n, vector<int>(n, -1));

		ci start = q.front();
		dist[start.first][start.second] = 0;

		// 2) 현재 board에 있는 물고기 {거리, 사이즈} 파악
		bfs(pq);

		// 2-1) 물고기 없으면 return
		if (pq.size() == 0) {
			break;
		}

		// 3) 물고기 하나 먹기
		ci fish = pq.top();
		board[start.first][start.second] = 0;
		board[fish.first][fish.second] = 9;
		time += dist[fish.first][fish.second]; // 거리 체크

		q.push(fish);
		cnt_ate++;

		// 4) 상어 사이즈 계산
		if (cnt_ate == shark_size) {
			shark_size++;
			cnt_ate = 0;
		}
	}
	return time;
}

int main() {
	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 6){
				cnt++;
			}
			if (board[i][j] == 9) { // 시작점
				q.push({i, j});
			}
		}
	}

	// 연산
	cout << solve();
}