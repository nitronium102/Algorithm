//
// Created by KangMinji on 2023-07-08.
//

#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> ci;

int n, m;
char board[502][502];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int findDistToRed(int a, int b, ci destination){
	queue<ci> q;

	int dist[502][502];
	for (int i=0; i<502; i++)
		fill(dist[i], dist[i]+502, -1);

	// 초기화
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
	// cout << answer << '\n';
	return answer;
}

int findDistToSideAndDest(int a, int b, ci destination) {
	queue<ci> redq;
	queue<ci> blueq;

	int rdist[502][502];
	int bdist[502][502];
	for (int i=0; i<502; i++){
		fill(rdist[i], rdist[i]+502, -1);
		fill(bdist[i], bdist[i]+502, -1);
	}

	redq.push({a, b});
	rdist[a][b] = 0;

	// cout << "시작점 " << a << ' ' << b << '\n';
	// 1) 시작점에서 사이드로 가는 거리 저장
	while(!redq.empty()) {
		int x = redq.front().first;
		int y = redq.front().second;
		redq.pop();

		// cout << "redq에서 나온 값 : " << x  << ' ' << y << '\n';
		if (x == 0 || x == n-1 || y == 0 || y == m-1) {
			blueq.push({x, y});
			bdist[x][y] = rdist[x][y];
			continue;
		}

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 'X' || rdist[nx][ny] >= 0) continue;
			rdist[nx][ny] = rdist[x][y] + 1;
			redq.push({nx, ny});
		}
	}

	// while(!blueq.empty()){
	//     cout << blueq.front().first << ' ' << blueq.front().second << "\n";
	//     blueq.pop();
	// }

	// 2) 해당 사이드에서 b로 가는 거리 저장
	int answer = -1;
	while(!blueq.empty()) {
		int x = blueq.front().first;
		int y = blueq.front().second;
		blueq.pop();

		if (x == destination.first && y == destination.second) {
			answer = bdist[x][y];
			break;
		}

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 'X' || bdist[nx][ny] >= 0) continue;
			bdist[nx][ny] = bdist[x][y] + 1;
			blueq.push({nx, ny});
		}

	}
	// cout << answer << '\n';
	return answer;
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
		// 1) R까지 가는 최단거리
		int cnt1 = findDistToRed(0, 0, red);
		if (cnt1 == -1) {
			cout <<  -1 << '\n';
			continue;
		}
		// 2) R에서 풍선 버리고 B까지 가는 최단 거리
		int cnt2 = findDistToSideAndDest(red.first, red.second, blue);
		if (cnt2 == -1) {
			cout << -1 << '\n';
			continue;
		}
		// 3) B에서 풍선 버리고 (N-1, M-1)까지 가는 최단거리
		int cnt3 = findDistToSideAndDest(blue.first, blue.second, {n-1, m-1});
		if (cnt3 == -1) {
			cout <<  -1 << '\n';
			continue;
		}
		answer = cnt1 + cnt2 + cnt3;
		// 출력
		cout << answer << '\n';
	}
}
