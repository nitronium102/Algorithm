// 골드4
// Created by KangMinji on 2023-09-03.
// https://www.acmicpc.net/problem/20056

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct fireball {
	int x;
	int y;
	int weight;
	int speed;
	int dir;
};

vector<fireball> board[51][51];
vector<fireball> fireballList;
int n, m, k;
int r, c, weight, speed, dir;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1,};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void move() {
	// 초기화
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			board[i][j].clear();
		}
	}

	for (fireball cur : fireballList) {
		int nx = cur.x + dx[cur.dir] * cur.speed;
		int ny = cur.y + dy[cur.dir] * cur.speed;
		// 맵 밖으로 벗어날 경우 다시 돌아와야 함
		while(nx < 1) nx += n;
		while(ny < 1) ny += n;
		while(nx > n) nx -= n;
		while(ny > n) ny -= n;
		board[nx][ny].push_back({nx, ny, cur.weight, cur.speed, cur.dir});
	}
}

bool checkDirIsSame(int x, int y) {
	bool isEven = false, isOdd = false;
	for (auto ball : board[x][y]) {
		if (ball.dir % 2) isOdd = true;
		else isEven = true;
	}

	if (isEven && isOdd) return false;
	return true;
}

void split() {
	vector<fireball> tmp;

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (board[i][j].size() == 0) continue;
			// 1개인 경우 -> 그냥 넣어줌
			if (board[i][j].size() == 1) {
				tmp.push_back(board[i][j][0]);
			} else {
				int total_weight = 0;
				int total_speed = 0;
				// 1) 파이어볼 합치기
				for (auto ball : board[i][j]){
					total_weight += ball.weight;
					total_speed += ball.speed;
				}
				int w = total_weight / 5;
				int s = total_speed / board[i][j].size();
				// 질량이 0인 파이어볼은 사라진다
				if (w == 0) continue;

				// 방향 확인
				if (checkDirIsSame(i, j)) {
					tmp.push_back({i, j, w, s, 0});
					tmp.push_back({i, j, w, s, 2});
					tmp.push_back({i, j, w, s, 4});
					tmp.push_back({i, j, w, s, 6});
				} else {
					tmp.push_back({i, j, w, s, 1});
					tmp.push_back({i, j, w, s, 3});
					tmp.push_back({i, j, w, s, 5});
					tmp.push_back({i, j, w, s, 7});
				}
			}
		}
	}
	fireballList = tmp;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m >> k;
	for (int i=0; i<m; i++){
		cin >> r >> c >> weight >> speed >> dir;
		fireballList.push_back({r, c, weight, speed, dir});
	}

	while (k--){
		move();
		split();
	}

	int answer = 0;
	for (auto fb : fireballList) {
		answer += fb.weight;
	}
	cout << answer << "\n";
}