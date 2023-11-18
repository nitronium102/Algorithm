// https://www.acmicpc.net/problem/17135
// 골드3

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> ci;

struct Enemy {
	int r, c, d;
};

int N, M, D;
int origin_board[20][20];
int board[20][20]; // tmp
int origin_enemy_cnt;

bool cmp(const Enemy &a, const Enemy &b){
	if (a.d != b.d){
		return a.d < b.d;
	}
	return a.c < b.c;
}

int calcDist(int x1, int y1, int x2, int y2){
	return abs(x1-x2) + abs(y1-y2);
}

int simulate(vector<int> archers){
	// 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = origin_board[i][j];
		}
	}

	// 연산
	int kill_cnt = 0;
	int archer_row = N;

	while(archer_row >= 1) {
		if (kill_cnt == origin_enemy_cnt){
			break;
		}

		vector<ci> target;
		for (int archer : archers) {
			vector<Enemy> candidate;
			for (int i=0; i<archer_row; i++){
				for (int j=0; j<M; j++){
					if (board[i][j] == 0) continue;
					int dist = calcDist(i, j, archer_row, archer);
					if (dist > D) continue;
					candidate.push_back({i, j, dist});
				}
			}

			if (candidate.empty()) continue;
			sort(candidate.begin(), candidate.end(), cmp);
			target.push_back({candidate[0].r, candidate[0].c});
		}

		for (ci t : target){
			if (board[t.first][t.second]){
				board[t.first][t.second] = 0;
				kill_cnt++;
			}
		}
		archer_row--;
	}
	return kill_cnt;
}

int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> origin_board[i][j];
			if (origin_board[i][j]) {
				origin_enemy_cnt++;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			for (int k = j + 1; k < M; k++) {
				vector<int> archers = {i, j, k};
				answer = max(answer, simulate(archers));
			}
		}
	}

	cout << answer << '\n';
}