// 골드5
// Created by KangMinji on 2023-03-29.
// https://www.acmicpc.net/problem/14503

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ci;

int n, m;
int dr[4] = {-1, 0, 1, 0}; // 북 동 남 서
int dc[4] = {0, 1, 0, -1};
vector<vector<int>> board;
int answer = 0;

bool isValid(int x, int y){
	if (x < 0 || y < 0 || x >= n || y >= m){
		return false;
	}
	return true;
}

void dfs(int r, int c, int dir){

	if (!board[r][c]){
		board[r][c] = 5;
		answer++;
	}

	// 1. 주변 4칸 청소 여부 확인
	for (int i=0; i<4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!isValid(nr, nc) || board[nr][nc] == 1){
			continue;
		}
		// 청소하지 않은 칸이 존재한다면
		if (!board[nr][nc]){
			board[nr][nc] = 5;
			answer++;
			dir = (dir + 3) % 4;
			dfs(nr, nc, dir);
		}
	}

	// 2. 청소되지 않은 칸이 없는 경우
	int nr = r - dr[dir];
	int nc = c - dc[dir];

	// 2-2. 후진할 수 없는 경우
	if (!isValid(nr, nc) || board[nr][nc] == 1){
		cout << answer << "\n";
		exit(0);
	}
	// 2-3. 후진할 수 있는 경우
	dfs(nr, nc, dir);
}

int main() {
	int r, c, dir;

	// 입력
	cin >> n >> m >> r >> c >> dir;
	board.assign(n, vector<int>(m, 0));
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}

	// 연산
	dfs(r, c, dir);
}