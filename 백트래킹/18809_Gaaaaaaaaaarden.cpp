// 골드1
// Created by KangMinji on 2023-07-06.
// https://www.acmicpc.net/problem/18809

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;
const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int n, m, g, r;
int board[51][51];
vector<ci> candidate;
int mask[11];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int backtracking(int csize) {
	ci state[51][51]; // {도착 시간, 색상}

	queue<ci> q;
	for (int i = 0; i < csize; i++) {
		if (mask[i] == GREEN || mask[i] == RED) {
			state[candidate[i].first][candidate[i].second] = {0, mask[i]};
			q.push(candidate[i]);
		}
	}

	int flower_cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int time = state[x][y].first;
		int color = state[x][y].second;

		if (color == FLOWER) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 0) continue; // 호수인 경우
			if (state[nx][ny].second == EMPTY) {
				// 1) 해당 칸이 비어있는 경우
				state[nx][ny] = {time+1, color};
				q.push({nx, ny});
			} else if (state[nx][ny].second == RED) {
				// 2) 해당 칸이 빨간색인 경우
				if (color == GREEN && state[nx][ny].first == time + 1){
					state[nx][ny].second = FLOWER;
					flower_cnt++;
				}
			} else if (state[nx][ny].second == GREEN) {
				// 3) 해당 칸이 초록색인 경우
				if (color == RED && state[nx][ny].first == time + 1) {
					state[nx][ny].second = FLOWER;
					flower_cnt++;
				}
			}
		}
	}
	return flower_cnt;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				candidate.push_back({i, j});
		}
	}

	// 배양액 뿌릴 수 있는 곳 중 배양액 개수만큼 돌리기
	int csize = candidate.size();
	fill(mask + csize - g - r, mask + csize - r, GREEN);
	fill(mask + csize - r, mask + csize, RED);

	int answer = 0;
	do {
		answer = max(answer, backtracking(csize));
	} while (next_permutation(mask, mask + csize));

	// 출력
	cout << answer;
}