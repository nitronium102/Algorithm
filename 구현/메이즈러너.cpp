//
// Created by KangMinji on 2023-09-29.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
const int MAX = 11;
using namespace std;
typedef pair<int, int> ci;

struct runner {
	int x, y;
	bool is_escape;
};

int n, m, k;
int board[MAX][MAX];
int tmp[MAX][MAX];
runner runners[MAX];
ci exits;
int answer = 0;
// 상하 우선
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int sx, sy, ssize;

int findDist(int x, int y){
	return abs(exits.first - x) + abs(exits.second - y);
}

void rotateRunnersAndExit() { // 모든 참가자와 출구 회전
	// 참가자 회전
	for (int i=1; i<=m; i++) {
		runner iter = runners[i];
		// 해당 참가자가 정사각형 안에 포함되어 있지 않으면 pass
		if (!(sx <= iter.x && iter.x < sx + ssize && sy <= iter.y && iter.y < sy + ssize)) continue;
		// (x, y) -> (y, ssize - x - 1)
		cout << "정사각형 안에 포함 " << iter.x << "  " << iter.y << "\n";
		int ox = iter.x - sx;
		int oy = iter.y - sy;
		runners[i] = {oy + sx, ssize - ox - 1 + sy};
	}

	// 출구 회전
	if (sx <= exits.first && exits.first < sx + ssize && sy <= exits.second && exits.second < sy + ssize) {
		int ox = exits.first - sx;
		int oy = exits.second - sy;
		exits = {oy + sx, ssize - ox - 1 + sy};
	}

	cout << "=========회전 후 참가자와 출구 정보===========\n";
	for (int i=1; i<=m; i++) {
		runner iter = runners[i];
		cout << iter.x << " " << iter.y << ' ' << iter.is_escape << '\n';
	}
	cout << exits.first << ' ' <<exits.second << "\n\n";
}

void rotateSquare() { // 벽 회전
	// 1) 정사각형 안에 있는 벽들 내구도 감소
	for (int x = sx; x < sx + ssize; x++){
		for (int y = sy; y < sy + ssize; y++){
			if (board[x][y]) {
				board[x][y]--;
			}
		}
	}

	// 2) 시계방향 90도 회전
	for (int x = sx; x < sx + ssize; x++) {
		for (int y = sy; y < sy + ssize; y++) {
			tmp[x][y] = board[x][y];
		}
	}

	for (int x = 0; x < ssize; x++) {
		for (int y = 0; y < ssize; y++) {
			board[x + sx][y + sy] = tmp[sx + ssize - y - 1][sy + x];
		}
	}

	cout << "=========내구도 정보===========\n";
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cout << board[i][j] << ' ';
		}
		cout << "\n";
	}
}

void findMinimumSquare() {
	for (int sz = 2; sz <= n; sz++) { // 사이즈
		for (int x1 = 1; x1 <= n - sz + 1; x1++){ // 행
			for (int y1= 1; y1<= n - sz + 1; y1++) { // 열
				int x2 = x1 + sz - 1;
				int y2 = y1 + sz - 1;

				// 출구가 해당 정사각형 안에 없는 경우
				if (!(x1 <= exits.first && exits.first <= x2 && y1 <= exits.second && exits.second <= y2)) continue;

				// 해당 정사각형 안에 참가자가 없는 경우
				bool is_included = false;
				for (int i=1; i<=m; i++) {
					runner iter = runners[i];
					// 이미 탈출한 참가자는 제외
					if (iter.is_escape) continue;
					// 참가자가 없는 경우
					if (!(x1 <= iter.x && iter.x <= x2 && y1 <= iter.y && iter.y <= y2)) continue;
					is_included = true;
				}

				if (is_included) {
					sx = x1;
					sy = y1;
					ssize = sz;
					cout << "========= 갱신된 사각형 정보===========\n";
					cout << sx << ' ' << sy << ' ' << ssize << "\n";
					return;
				}
			}
		}
	}

	cout << "=========사각형 정보===========\n";
	cout << sx << ' ' << sy << ' ' << ssize << "\n";
}

void moveAllRunners() {
	for (int i=1; i<=m; i++) {
		runner &iter = runners[i];
		// 이미 탈출한 경우는 제외
		if (iter.is_escape)
			continue;

		// 탈출 좌표와 동일하다면
		if (iter.x == exits.first && iter.y == exits.second){
			iter.is_escape = true;
			continue;
		}

		int dist = findDist(iter.x, iter.y);

		for (int j=0; j<4; j++){
			int nx = iter.x + dx[j];
			int ny = iter.y + dy[j];

			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (board[nx][ny]) continue;

			// 현재 거리보다 1 작은 경우 움직인다
			int ndist = findDist(nx, ny);
			if (dist <= ndist) {
				cout << "거리 더 멀어\n";
				cout << iter.x << " " << iter.y << " " << nx << ' ' << ny << ' '<< dist << ' ' << ndist << '\n';
				continue;
			}
			cout << "이동 " << iter.x << ' ' << iter.y << ' ' << nx << ' ' << ny << "\n";
			iter.x = nx;
			iter.y = ny;
			answer++;
			break;
		}
	}

	cout << "=========참가자 이동===========\n";
	for (int i=1; i<=m; i++) {
		runner iter = runners[i];
		cout << iter.x << " " << iter.y << ' ' << iter.is_escape << '\n';
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin >> board[i][j];
		}
	}

	for (int i=1; i<=m; i++){
		cin >> runners[i].x >> runners[i].y;
		runners[i].is_escape = false;
	}

	cin >> exits.first >> exits.second;

	int cnt = 0;
	while(k--){
		cout << "&&&&&& " << ++cnt << "번쨰 &&&&&&&&&&&&\n";
		// 1. 모든 참가자 이동
		moveAllRunners();

		// 2. 모든 참가자가 출구로 탈출했는지 판단
		bool is_all_escape = true;
		for (int i=1; i<=m; i++) {
			if (!runners[i].is_escape){
				is_all_escape = false;
			}
		}

		// 3. 모든 참가자가 탈출했다면 종료
		if (is_all_escape){
			break;
		}

		// 4. 한 명 이상의 참가자와 출구를 포함한 가장 작은 정사각형 찾기
		findMinimumSquare();

		// 5. 정사각형 내부의 벽 회전
		rotateSquare();

		// 6. 모든 참가자들 및 출구 회전
		rotateRunnersAndExit();
	}

	cout << answer << '\n';
	cout << exits.first << " " << exits.second << '\n';
	return 0;
}