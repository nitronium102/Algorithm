// 골드4
// Created by KangMinji on 2023-04-05.
// https://www.acmicpc.net/problem/11559

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int ROW = 6, COL = 12;
typedef pair<int, int> ci;

vector<vector<char>> board(ROW, vector<char>(COL, '.'));
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool bfs(int x, int y){
	queue<ci> q;
	queue<ci> puyo;
	vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

	// 초기화
	q.push({x, y});
	puyo.push({x, y});
	visited[x][y] = true;
	int cnt = 1;

	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		char color = board[cx][cy];
		q.pop();

		for (int i=0; i<4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= ROW || ny < 0 || ny >= COL || visited[nx][ny]){
				continue;
			}
			if (board[nx][ny] == color){
				q.push({nx, ny});
				puyo.push({nx, ny});
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}

	if (cnt < 4){
		return false;
	}
	while(!puyo.empty()){
		int cx = puyo.front().first;
		int cy = puyo.front().second;
		puyo.pop();

		board[cx][cy] = '.';
	}
	return true;
}

vector<vector<char>> makeNewBoard() {
	vector<vector<char>> new_board(ROW, vector<char>(COL, '.'));
	for (int i=0; i<ROW; i++){
		queue<char> puyo;
		for (int j=0; j<COL; j++) {
			if (board[i][j] != '.'){
				puyo.push(board[i][j]);
			}
		}
		int idx = 0;
		while(!puyo.empty()){
			new_board[i][idx++] = puyo.front();
			puyo.pop();
		}
	}
	return new_board;
}

int playGame() {
	int answer = 0;

	while(true){
		bool is_pop = false;

		for (int i=0; i<ROW; i++){
			for (int j=0; j<COL; j++){
				if (board[i][j] == '.'){
					continue;
				}
				if (bfs(i, j)){ // 연쇄 발생 여부
					is_pop = true;
				}
			}
		}

		if (!is_pop){
			break;
		}
		board = makeNewBoard();
		answer++;
	}
	return answer;
}

int main() {
	// 입력
	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < ROW; j++) {
			cin >> board[j][COL - i - 1];
		}
	}

	// 연산 & 출력
	cout << playGame();
}