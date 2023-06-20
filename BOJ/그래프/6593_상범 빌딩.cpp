// 골드5
// Created by KangMinji on 2023-06-20.
// https://www.acmicpc.net/problem/6593

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> tp;

char board[31][31][31]; // 가로, 세로, 높이
int dist[31][31][31];
int n, m, l;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<tp> q;

void bfs(){
	while(!q.empty()){
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		q.pop();

		for (int i=0; i<6; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || nx >= n || ny <0 || ny >= m || nz < 0 || nz >= l) continue;
			if (board[nx][ny][nz] == '#' || dist[nx][ny][nz] > 0) continue;
			dist[nx][ny][nz] = dist[x][y][z] + 1;

			if (board[nx][ny][nz] == 'E'){
				cout << "Escaped in " << dist[nx][ny][nz] << " minute(s).\n";
				return;
			}
			q.push({nx, ny, nz});
		}
	}
	cout << "Trapped!\n";
	return;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> l >> n >> m){
		if (l == 0 && n == 0 && m == 0)
			break;

		// 초기화
		for (int i=0; i<l; i++){
			for (int j=0; j<n; j++) {
				fill(dist[i][j], dist[i][j] + m, 0);
			}
		}
		while(!q.empty()) q.pop();

		for (int k=0; k<l; k++){
			for (int i=0; i<n; i++){
				for (int j=0; j<m; j++){
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') q.push({i, j, k});
					if (board[i][j][k] == '.') dist[i][j][k] = -1;
				}
			}
		}

		// 연산
		bfs();
	}
}