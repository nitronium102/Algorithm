// 실버1
// Created by KangMinji on 2023-06-20.
// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int MAX = 26;

string board[MAX];
bool visited[MAX][MAX];
int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int a, int b){
	queue<ci> q;

	visited[a][b] = true;
	q.push({a, b});

	int width = 0;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		width++;

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >=n ) continue;
			if (board[nx][ny] == '0' || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	return width;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> board[i];

	int answer = 0;
	vector<int> area;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '1' && !visited[i][j]){
				answer++;
				area.push_back(bfs(i, j));
			}
		}
	}

	sort(area.begin(), area.end());

	// 출력
	cout << answer << '\n';
	for (int width : area){
		cout << width << '\n';
	}
}