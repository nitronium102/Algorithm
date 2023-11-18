//
// Created by KangMinji on 2023-07-08.
//
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> ci;

int n, m;
char board[502][502];
int side[2][502][502]; // blue, (n-1, m-1)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int findDistToDestination(int a, int b, ci destination){
	queue<ci> q;

	int dist[502][502];
	for (int i=0; i<502; i++){
		fill(dist[i], dist[i]+502, -1);
	}

	q.push({a, b});
	dist[a][b] = 0;

	int answer = -1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (destination.first == x && destination.second == y){
			answer = dist[x][y];
			break;
		}

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 'X' || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({nx, ny});
		}
	}
	return answer;
}

void findDistToSide(ci start, int idx) {
	queue<ci> q;

	q.push(start);
	side[idx][start.first][start.second] = 0;

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 'X' || side[idx][nx][ny] >= 0) continue;
			side[idx][nx][ny] = side[idx][x][y] + 1;
			q.push({nx, ny});
		}
	}
}

int goToSide(ci start, ci destination, int idx) {
	queue<ci> q;
	int dist[502][502];
	for (int i=0; i<502; i++){
		fill(dist[i], dist[i]+502, -1);
	}

	q.push(start);
	dist[start.first][start.second] = 0;

	// 1) 시작점에서 사이드로 가는 거리 저장
	int answer = 1e9;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == 0 || x == n-1 || y == 0 || y == m-1) {
			if (side[idx][x][y] == -1) {
				continue;
			}
			answer = min(answer, dist[x][y] + side[idx][x][y]);
			continue;
		}

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 'X' || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({nx, ny});
		}
	}

	return answer == 1e9 ? -1 : answer;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int t;
	cin >> t;
	for (int idx = 1; idx <= t; idx++){
		ci red, blue;
		cin >> n >> m;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++){
				cin >> board[i][j];
				if (board[i][j] == 'R') red = {i, j};
				if (board[i][j] == 'B') blue = {i, j};
			}
		}

		// 연산
		int answer = 0;
		cout << "#" << idx << ' ';

		// 초기화
		for (int i=0; i<2; i++) {
			for (int j=0; j<502; j++) {
				fill(side[i][j], side[i][j]+502, -1);
			}
		}

		// 1) R까지 가는 최단거리
		int cnt1 = findDistToDestination(0, 0, red);
		if (cnt1 == -1) {
			cout <<  -1 << '\n';
			continue;
		}

		// 2) B에서 사이드 가는 거리 / 종착지에서 사이드 가는 거리
		findDistToSide(blue, 0);
		findDistToSide({n-1, m-1}, 1);

		// 2) R에서 풍선 버리고 B까지 가는 최단 거리
		int cnt2 = goToSide(red, blue, 0);
		if (cnt2 == -1) {
			cout << -1 << '\n';
			continue;
		}
		// 3) B에서 풍선 버리고 (N-1, M-1)까지 가는 최단거리
		int cnt3 = goToSide(blue, {n-1, m-1}, 1);
		if (cnt3 == -1) {
			cout <<  -1 << '\n';
			continue;
		}
		answer = cnt1 + cnt2 + cnt3;
		// 출력
		cout << answer << '\n';
	}
}
