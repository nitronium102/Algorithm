// LV2
// Created by KangMinji on 2023-05-02.
// https://school.programmers.co.kr/learn/courses/30/lessons/169199

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> ci;
const int MAX = 1e4 + 1;
const int SIZE = 101;

int n, m;
ci start, finish;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, false));
vector<vector<int>> dist(SIZE, vector<int>(SIZE, MAX));

bool check(int x, int y){
	return x>=0 && y>=0 && x<n && y<m;
}

void bfs(vector<string> &board){
	queue<ci> q;

	// 시작 지점 넣기
	q.push(start);
	dist[start.first][start.second] = 0;
	visited[start.first][start.second] = true;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i=0; i<4; i++){
			int nx = x, ny = y;
			while(check(nx, ny) && board[nx][ny] != 'D'){
				nx += dx[i];
				ny += dy[i];
			}
			nx -= dx[i];
			ny -= dy[i];

			if (!visited[nx][ny]){
				visited[nx][ny] = true;
				dist[nx][ny] = min(dist[nx][ny], dist[x][y] + 1);
				q.push({nx, ny});
			}
		}
	}
}

int solution(vector<string> board) {

	n = board.size();
	m = board[0].size();

	bool start_flag = false, end_flag = false;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (start_flag && end_flag){
				break;
			}
			if (board[i][j] == 'R'){
				start = {i, j};
				start_flag = true;
			}
			if (board[i][j] == 'G'){
				finish = {i, j};
				end_flag = true;
			}
		}
	}

	bfs(board);

	int answer = dist[finish.first][finish.second] == MAX ? -1 : dist[finish.first][finish.second];
	return answer;
}