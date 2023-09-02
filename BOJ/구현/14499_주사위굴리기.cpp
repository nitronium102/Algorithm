// 골드4
// Created by KangMinji on 2023-09-02.
// https://www.acmicpc.net/problem/14499

#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 21;

int n, m, x, y, k;
int board[MAX][MAX];
// 🔥동서북남 방향 조심
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dice[7]; // 위 : 0, 사이드 : 1, 2, 3, 4. 바닥 : 5
int tmp[7];

void rollDice(int dir) {
	memcpy(&tmp, &dice, sizeof(dice));

	if (dir == 1) { // 동쪽
		dice[1] = tmp[4];
		dice[4] = tmp[6];
		dice[6] = tmp[3];
		dice[3] = tmp[1];
	} else if (dir == 2) { // 서쪽
		dice[4] = tmp[1];
		dice[6] = tmp[4];
		dice[3] = tmp[6];;
		dice[1] = tmp[3];;
	} else if (dir == 3) { // 북쪽
		dice[1] = tmp[5];;
		dice[2] = tmp[1];;
		dice[6] = tmp[2];;
		dice[5] = tmp[6];;
	} else if (dir == 4) { // 남쪽
		dice[5] = tmp[1];;
		dice[1] = tmp[2];;
		dice[2] = tmp[6];;
		dice[6] = tmp[5];;
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 1) 칸이 0인 경우 : 칸 = 주사위의 바닥면
	// 2) 칸이 0이 아닌 경우 : 주사위바닥 = 칸, 칸 = 0
	// 주사위가 이동했을 때마다 상단에 쓰여있는 값
	// 범위에서 벗어나는 경우에는 명령 무시, 출력 X
	int dir;
	while (k--) {
		cin >> dir;

		int nx = x + dx[dir - 1];
		int ny = y + dy[dir - 1];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		rollDice(dir);
		if (board[nx][ny] == 0) {
			board[nx][ny] = dice[6];
		} else {
			dice[6] = board[nx][ny];
			board[nx][ny] = 0;
		}

		cout << dice[1] << '\n';

		x = nx;
		y = ny;
	}
}