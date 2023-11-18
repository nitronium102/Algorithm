// LV2
// Created by KangMinji on 2023-05-03.
// https://school.programmers.co.kr/learn/courses/30/lessons/159993

#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int MAX = 1e9;
const int SIZE = 101;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool check(int x, int y){
	return x>=0 && y>=0 && x<n && y<m;
}

int bfs(ci start, ci target, vector<string> &maps){
	queue<ci> q;
	vector<vector<int>> dist(SIZE, vector<int>(SIZE, MAX));
	vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, false));
	int min_dist = MAX;

	// 시작 지점 표시
	q.push(start);
	dist[start.first][start.second] = 0;
	visited[start.first][start.second] = true;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		int d = dist[x][y];
		q.pop();

		if (x == target.first && y == target.second){
			min_dist = min(min_dist, d);
			continue;
		}

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!check(nx, ny)){
				continue;
			}
			if (visited[nx][ny] || maps[nx][ny] == 'X'){
				continue;
			}
			q.push({nx, ny});
			dist[nx][ny] = min(dist[nx][ny], d + 1);
			visited[nx][ny] = true;
		}
	}
	return min_dist == MAX ? -1 : min_dist;
}

int solution(vector<string> maps) {

	n = maps.size();
	m = maps[0].size();

	ci lever, start, exit;
	int find_cnt = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (find_cnt == 3){
				break;
			}
			if (maps[i][j] == 'L'){ lever = {i, j}; find_cnt++; }
			if (maps[i][j] == 'E'){ exit = {i, j}; find_cnt++; }
			if (maps[i][j] == 'S'){ start = {i, j}; find_cnt++; }
		}
	}

	int answer = 0;
	int lever_dist = bfs(start, lever, maps);
	int exit_dist = bfs(lever, exit, maps);
	if (lever_dist == -1 || exit_dist == -1){
		return -1;
	}
	answer = lever_dist + exit_dist;
	return answer;
}