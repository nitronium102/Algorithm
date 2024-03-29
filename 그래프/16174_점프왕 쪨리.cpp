// 실버1
// Created by KangMinji on 2023-03-20.
// https://www.acmicpc.net/problem/16174

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;

int dx[2] = {0, 1}; // {오른쪽, 아래}
int dy[2] = {1, 0};

bool playGame(int n, vector<vector<int>> &board){
	queue<ci> q;
	vector<vector<bool>> visited(n, vector<bool>(n, false));

	// 시작 정점
	visited[0][0] = true;
	q.push({0, 0});

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int move = board[x][y];
		for (int i=0; i<2; i++){
			int nx = x + dx[i] * move;
			int ny = y + dy[i] * move;

			if (nx < 0 || ny < 0 || nx >= n || ny >= n){
				continue;
			}

			if (!visited[nx][ny]) {
				if (board[nx][ny] == -1){
					return true;
				}
				q.push({nx, ny});
				visited[nx][ny] = true;
			}
		}
	}
	return false;
}

int main() {
	int n;

	// 입력
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n, 0));

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}

	// 연산 & 출력
	if (playGame(n, board)){
		cout << "HaruHaru\n";
	} else {
		cout << "Hing\n";
	}
}