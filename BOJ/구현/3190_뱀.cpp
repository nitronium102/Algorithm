// 골드4
// Created by KangMinji on 2023-03-07.
// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

int dx[4] = {0, 1, 0, -1}; // 반시계(우하좌상)
int dy[4] = {1, 0, -1, 0};

int snake(int n, vector<vector<int>> &board, map<int, char> &dir_info) {

	// 뱀 초기화
	deque<ci> snake;
	snake.push_front({1, 1});
	board[1][1] = 1;

	int time = 0, dir = 0;
	while (++time) {
		int nx = snake.front().first + dx[dir];
		int ny = snake.front().second + dy[dir];

		if (nx < 1 || ny < 1 || nx > n || ny > n || board[nx][ny] == 1) {
			break;
		}

		// 다음 칸에 사과가 없는 경우 : 꼬리 자르기
		if (board[nx][ny] != 2) {
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}

		// 머리 이동
		board[nx][ny] = 1;
		snake.push_front({nx, ny});

		// 방향 변환 확인
		if (dir_info[time] == 'L') {
			dir = (dir + 3) % 4;
		} else if (dir_info[time] == 'D') {
			dir = (dir + 1) % 4;
		}
	}

	return time;
}

int main() {
	int n, k, a, b, l, x;
	char dir;

	// 입력
	cin >> n >> k;
	vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		board[a][b] = 2; // 사과의 위치
	}
	cin >> l;
	map<int, char> dir_info;
	for (int i = 0; i < l; i++) {
		cin >> x >> dir;
		dir_info[x] = dir;
	}

	// 연산 & 출력
	cout << snake(n, board, dir_info);
}