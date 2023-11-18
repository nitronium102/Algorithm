// LV3
// Created by KangMinji on 2023-11-14.
// https://school.programmers.co.kr/learn/courses/30/lessons/150365?language=cpp

#include <string>
using namespace std;

// 아래, 왼쪽, 오른쪽, 위쪽
bool visited[55][55][2505];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char ch[4] = {'d', 'l', 'r', 'u'};

int N, M, R, C, K;
bool is_finished = false;
string answer = "";
/*
크기 n * m
미로 출발 x * y
미로 도착 r * c
*/
void dfs(int x, int y, int cnt, string str) {
	if (is_finished) {
		return;
	}

	if (cnt == K) {
		if (x == R && y == C) {
			is_finished = true;
			answer = str;
		}
		return;
	}

	for (int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
		if (visited[nx][ny][cnt+1]) continue;
		visited[nx][ny][cnt+1] = true;
		dfs(nx, ny, cnt+1, str + ch[i]);

		if (is_finished) return;
	}
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
	N = n; M = m; R = r; C = c; K = k;
	dfs(x, y, 0, "");

	if (answer.empty()) {
		return "impossible";
	}
	return answer;
}
