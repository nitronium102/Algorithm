// 골드5
// Created by KangMinji on 2023-06-20.
// https://www.acmicpc.net/problem/7569

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> tp;
const int MAX = 101;

int board[MAX][MAX][MAX]; // 가로 세로 높이
int dist[MAX][MAX][MAX];
int n, m, h;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<tp> q;

void bfs(){
	while(!q.empty()){
		auto [x, y, z] = q.front();
		q.pop();

		for (int i=0; i<6; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m|| nz < 0 || nz >= h) continue;
			if (dist[nx][ny][nz] >= 0) continue;
			dist[nx][ny][nz] = dist[x][y][z] + 1;
			q.push({nx, ny, nz});
		}
	}
}

int main() {
	// 시간초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;

	for (int i=0; i<h; i++){
		for (int j=0; j<n; j++){
			for (int k=0; k<m; k++) {
				cin >> board[j][k][i];
				if (board[j][k][i] == 1)
					q.push({j, k, i});
				if (board[j][k][i] == 0)
					dist[j][k][i] = -1;
			}
		}
	}

	// 연산
	bfs();

	// 출력
	int answer = 0;
	for (int i=0; i<h; i++){
		for (int j=0; j<n; j++){
			for (int k=0; k<m; k++) {
				if (dist[j][k][i] == -1){
					cout << -1;
					return 0;
				}
				answer = max(answer, dist[j][k][i]);
			}
		}
	}
	cout << answer;
}