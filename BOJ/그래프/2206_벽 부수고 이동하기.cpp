// 골드3
// Created by KangMinji on 2023-06-20.
// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> tp;

char board[1001][1001];
int dist[1001][1001][2];
// dist[x][y][0] : 벽을 안 부수고 (x, y)까지 가는 데 걸리는 비용
// dist[x][y][1] : 벽을 하나만 부수고 (x, y)까지 오는 데 걸리는 비용 & (x, y)가 벽이라 부수는 비용
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(){
	queue<tp> q;

	dist[0][0][0] = dist[0][0][1] = 1;
	q.push({0, 0, 0});

	while(!q.empty()){
		int x, y, broke;
		tie(x, y, broke) = q.front();
		q.pop();

		if (x == n-1 && y == m-1)
			return dist[x][y][broke];

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// 1) (nx, ny)를 안 부수는 경우
			if (board[nx][ny] == '0' && dist[nx][ny][broke] == -1){
				dist[nx][ny][broke] = dist[x][y][broke] + 1;
				q.push({nx, ny, broke});
			}
			// 2) (nx, ny)를 부수는 경우
			if (broke == 0 && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
				dist[nx][ny][1] = dist[x][y][broke] + 1;
				q.push({nx, ny, 1});
			}
		}
	}
	return -1;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	// 초기화
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++)
			dist[i][j][0] = dist[i][j][1] = -1;
	}

	for (int i=0;i<n;i++){
		for (int j=0; j<m; j++)
			cin >> board[i][j];
	}

	cout << bfs();
	return 0;
}