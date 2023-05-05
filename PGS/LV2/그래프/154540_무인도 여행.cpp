// lv2
// Created by KangMinji on 2023-05-04.
// https://school.programmers.co.kr/learn/courses/30/lessons/154540

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool check(int x, int y){
	return x>=0 && y>=0 && x<n && y<m;
}

int bfs(int sx, int sy, vector<string> &maps){
	int total = 0;

	queue<pair<int, int>> q;

	// 시작 지점 표시
	q.push({sx, sy});
	visited[sx][sy] = true;
	total += maps[sx][sy] - '0';

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!check(nx, ny)){
				continue;
			}
			if (maps[nx][ny] == 'X' || visited[nx][ny]){
				continue;
			}
			q.push({nx, ny});
			visited[nx][ny] = true;
			total += maps[nx][ny] - '0';
		}
	}
	return total;
}

vector<int> solution(vector<string> maps) {
	vector<int> answer;

	n = maps.size();
	m = maps[0].size();

	visited.assign(n, vector<bool>(m, false));
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (maps[i][j] == 'X' || visited[i][j]){
				continue;
			}
			answer.push_back(bfs(i, j, maps));
		}
	}

	if (answer.size() == 0){
		answer.push_back(-1);
	}

	sort(answer.begin(), answer.end());
	return answer;
}