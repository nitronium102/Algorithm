// 골드3
// Created by KangMinji on 2023-06-30.
// https://www.acmicpc.net/problem/1941

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

string board[5];
bool mask[25];
int answer = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	for (int i = 0; i < 5; i++)
		cin >> board[i];

	// 조합 뽑기
	fill(mask + 7, mask + 25, true);
	do {
		queue<pair<int, int>> q;

		int dasom = 0, adj_cnt = 0;
		bool visited[5][5] = {}; // 지역 배열은 초기화 필요
		bool princess7[5][5] = {};

		// 1) 7공주 표시해놓기
		for (int i = 0; i < 25; i++) {
			if (mask[i]) continue;
			int x = i / 5;
			int y = i % 5; // board 좌표값 구하기
			princess7[x][y] = true;
			if (q.empty()) {
				q.push({x, y});
				visited[x][y] = true;
			}
		}

		// 2) 인접 & 개수 조건 확인
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			adj_cnt++;
			dasom += (board[x][y] == 'S');

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
				if (visited[nx][ny] || !princess7[nx][ny]) continue;
				q.push({nx, ny});
				visited[nx][ny] = true;
			}
		}
		answer += (adj_cnt >= 7 && dasom >= 4);
	} while (next_permutation(mask, mask + 25));

	cout << answer;
}