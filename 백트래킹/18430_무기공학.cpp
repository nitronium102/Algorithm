// 골드4
// Created by KangMinji on 2023-06-05.
// https://www.acmicpc.net/problem/18430

#include <iostream>
#include <vector>

using namespace std;

int n, m, answer = 0;
int board[6][6];
bool visited[6][6];
vector<vector<int>> shape = {{0,  -1, 1,  0},
							 {0,  -1, -1, 0},
							 {-1, 0,  0,  1},
							 {1,  0,  0,  1}};

bool check(int x1, int y1, int x2, int y2){
	return x1>= 0 && x1 < n && y1 >= 0 && y1 < m
		&& x2>= 0 && x2 < n && y2 >= 0 && y2 < m;
}

// (0, 0), (0, 1), (0, 2), ... (1, 0) ,,, (n-1, m-1)
void backtracking(int x, int y, int sum) {

	if (y == m) {
		x++;
		y = 0;
	}

	if (x == n) {
		answer = max(answer, sum);
		return;
	}

	if (!visited[x][y]) { // 현재 자리 방문할 수 있다면 부메랑 생성
		for (int i = 0; i < 4; i++) {
			int ax = x + shape[i][0];
			int ay = y + shape[i][1];
			int bx = x + shape[i][2];
			int by = y + shape[i][3];

			if (check(ax, ay, bx, by) && !visited[ax][ay] && !visited[bx][by]){
				visited[x][y] = visited[ax][ay] = visited[bx][by] = true;
				backtracking(x, y+1, sum + board[x][y] * 2 + board[ax][ay] + board[bx][by]);
				visited[x][y] = visited[ax][ay] = visited[bx][by] = false;
			}
		}
	}
	// 방문할 수 없는 경우
	backtracking(x, y+1, sum);
}

int main() {
	// 입력
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 연산
	backtracking(0, 0, 0);

	// 출력
	cout << answer;
}