// 실버1
// Created by KangMinji on 2023-06-20.
// https://www.acmicpc.net/problem/2583

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 101;
typedef pair<int, int> ci;

int board[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
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

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == 1 || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	return width;
}

int main() {
	// 입력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k, x1, x2, y1, y2;

	cin >> m >> n >> k;
	while(k--){
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i=y1; i<y2; i++){
			for (int j=x1; j<x2; j++)
				board[i][j] = 1;
		}
	}

	// 연산
	int cnt = 0;
	vector<int> area;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if (board[i][j] == 0 && !visited[i][j]){
				cnt++;
				area.push_back(bfs(i, j));
			}
		}
	}

	sort(area.begin(), area.end());

	// 출력
	cout << cnt << "\n";
	for (int a : area){
		cout << a << ' ';
	}
}