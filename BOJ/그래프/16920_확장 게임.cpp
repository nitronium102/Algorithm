// 골드2
// Created by KangMinji on 2023-07-13.
// https://www.acmicpc.net/problem/16920

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
const int MAX = 1001;
typedef tuple<int, int, int> tp;

int n, m, p;
string board[MAX];
int step[10];
int area[10];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++)
		cin >> step[i];

	vector<queue<tp>> vq(n + 1, queue<tp>());
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] != '.' && board[i][j] != '#') {
				int people = board[i][j] -'0';
				area[people]++;
				vq[people].push({i, j, step[people]});
			}
		}
	}

	// 연산
	while (true) {
		bool can_expand = false;

		for (int i = 1; i <= p; i++) {
			cout << i << "차례!\n";
			queue<tp> nextq;

			queue<tp> q = vq[i];
			while (!q.empty()) {
				int x, y, cnt;
				tie(x, y, cnt) = vq[i].front();
				q.pop();

				if (cnt == 0) {
					nextq.push({x, y, step[i]});
					continue;
				}
				cout << x << ' ' << y << '\n';
				for (int j = 0; j < 4; j++) {
					int nx = x + dx[j] * step[i];
					int ny = y + dy[j] * step[i];

					if (nx < 0 || nx >= n || ny < 0 || ny >= 0) continue;
					if (board[nx][ny] != '.') continue;
					board[nx][ny] = (char) (i + 48);
					area[i]++;
					q.push({nx, ny, cnt - 1});
					can_expand = true;
				}
			}
			vq[i] = nextq;
		}

		if (!can_expand) {
			cout << "종료합니당\n";
			break;
		}
	}

	// 출력
	for (int i = 1; i <= p; i++) {
		cout << area[i] << ' ';
	}
}