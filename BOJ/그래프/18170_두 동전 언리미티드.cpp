// 골드3
// Created by KangMinji on 2023-06-08.
// https://www.acmicpc.net/problem/18170

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
typedef pair<ci, ci> pi;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char board[21][21];
int visited[21][21][21][21];

bool checkRange(ci coord){
	int x = coord.first;
	int y = coord.second;
	return x>=1 && x<=n && y>=1 && y<=m;
}

int calcMinBtnPush(vector<ci> &coin){
	queue<pi> q;

	q.push({coin[0], coin[1]});
	visited[coin[0].first][coin[0].second][coin[1].first][coin[1].second] = 1;

	while(!q.empty()){
		ci coin1 = q.front().first; ci coin2 = q.front().second;
		q.pop();

		for (int i=0; i<4; i++){
			ci next1 = {coin1.first + dx[i], coin1.second + dy[i]};
			ci next2 = {coin2.first + dx[i], coin2.second + dy[i]};

			// 벽을 먼저 세워야 함
			if (board[next1.first][next1.second] == '#'){
				next1 = coin1;
			}
			if (board[next2.first][next2.second] == '#'){
				next2 = coin2;
			}

			// 1) 이동하려는 칸이 없는 경우
			bool coin1_flag = checkRange(next1);
			bool coin2_flag = checkRange(next2);

			// 1-1) 둘 다 떨어지는 경우
			if (!coin1_flag && !coin2_flag){
				continue;
			}
			// 1-2) 이미 방문한 경우
			if (visited[next1.first][next1.second][next2.first][next2.second]){
				continue;
			}
			// EXIT) 하나만 떨어지는 경우
			if (coin1_flag + coin2_flag == 1){
				return visited[coin1.first][coin1.second][coin2.first][coin2.second];
			}

			// 이동하는 경우
			pi next = {next1, next2};
			visited[next1.first][next1.second][next2.first][next2.second] = visited[coin1.first][coin1.second][coin2.first][coin2.second] + 1;
//			printf("%d %d | %d %d\n", next1.first, next1.second, next2.first, next2.second);
			q.push(next);
		}
	}
	return -1;
}

int main() {
	char c;

	// 입력
	cin >> n >> m;

	vector<ci> coin;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> board[i][j];

			if (board[i][j] == 'o'){
				coin.push_back({i, j});
			}
		}
	}

	// 연산 & 출력
	cout << calcMinBtnPush(coin);

}