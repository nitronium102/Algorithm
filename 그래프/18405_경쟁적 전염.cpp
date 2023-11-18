//
// Created by KangMinji on 2023-06-06.
// https://www.acmicpc.net/problem/18405

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool check(int x, int y, int n) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main() {
	int n, k, s, a, b;
	vector<tp> virus;
	vector<vector<int>> board;

	// 입력
	cin >> n >> k;
	board.assign(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				virus.push_back({board[i][j], i, j});
			}
		}
	}
	// 번호 오름차순 정렬
	sort(virus.begin(), virus.end());

	cin >> s >> a >> b;
	int time = 0;

	// 연산
	while (time < s) {

		int cnt = virus.size();
		for (int i = 0; i < cnt; i++) { // 여기에서 바로 virus.size() 쓰면 계속 추가돼서 돈다
			int num = get<0>(virus[i]);
			int x = get<1>(virus[i]);
			int y = get<2>(virus[i]);

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (!check(nx, ny, n)) {
					continue;
				}
				if (!board[nx][ny]) {
					board[nx][ny] = num;
					virus.push_back({board[nx][ny], nx, ny});
				}
			}
		}
		if (board[a][b]) { // 한 번 감염되면 재감염 X
			break;
		}
		time++;
	}

	// 출력
	cout << board[a][b] << '\n';

}