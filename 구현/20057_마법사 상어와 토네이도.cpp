// 골드3
// Created by KangMinji on 2023-09-11.
// https://www.acmicpc.net/problem/20057

#include <iostream>
using namespace std;
const int MAX = 1005;

int n, r, c;
int direction = 0, cnt = 1; // cnt : 해당 방향으로 이동한 칸 횟수
int answer = 0;

int board[MAX][MAX];
int dx[4] = {-1, 0, 1, 0}; // 서남동북
int dy[4] = {0, 1, 0, -1};

double sandP[9] = {0.01, 0.01, 0.07, 0.07, 0.02, 0.02, 0.1, 0.1, 0.05};
// sand[dir][percent cnt]
// a는 제일 마지막
int sandX[4][10] = {{0, 0, -1, -1, -1, -1, -2, -2, -3, -2},
					{1, -1, 1, -1, 2, -2, 1, -1, 0, 0},
					{0, 0, 1, 1, 1, 1, 2, 2, 3, 2},
					{1, -1, 1, -1, 2, -2, 1, -1, 0, 0}};
int sandY[4][10] = {{1, -1, 1, -1, 2, -2, 2, -2, 0, 0},
					{0, 0, -1, -1, -1, -1, -2, -2, -3, -2},
					{1, -1, 1, -1, 2, -2, 1, -1, 0, 0},
					{0, 0, 1, 1, 1, 1, 2, 2, 3, 2}};

void sand(int x, int y, int dir) {
	// y좌표
	int yx = x + dx[dir];
	int yy = y + dy[dir];
	int ysand = board[yx][yy];

	// y좌표에 모래가 없으면 그냥 리턴
	if (ysand == 0){
		return;
	}

	// 모래 날리기
	for (int i=0; i<9; i++) {
		int nx = x + sandX[dir][i];
		int ny = y + sandY[dir][i];
		double percent = sandP[i];
		int sand = ysand * percent;

		// 격자 바깥으로 나간 모래의 양 구하기
		if (nx < 0 || ny < 0 || nx >= n || ny >= n){
			answer += sand;
		} else {
			// 새로운 좌표로 모래 이동
			board[nx][ny] += sand;
		}
		// 기존 좌표에서는 모래 빼주기
		board[yx][yy] -= sand;
	}

	// a로 이동하는 모래의 양
	int nx = x + sandX[dir][9];
	int ny = y + sandY[dir][9];
	// 격자 바깥으로 나간 모래의 양 구하기
	if (nx < 0 || ny < 0 || nx >= n || ny >= n){
		answer += board[yx][yy];
	} else {
		// 새로운 좌표로 모래 이동
		board[nx][ny] += board[yx][yy];
	}
	// 기존 좌표에서는 모래 빼주기
	board[yx][yy] = 0;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}

	// 시작 지점
	r = (n+1)/2;
	c = (n+1)/2;

	// 토네이도 소멸할 때까지
	while(r && c) {
		// 방향당 2번씩 이동
		for (int i=0; i<2; i++){
			for (int j=0; j<cnt; j++){
				// 토네이도 한 칸 이동
				sand(r, c, direction);
				r += dx[direction];
				c += dy[direction];
			}
			direction = (direction + 1) % 4;
		}
		cnt++;
	}

	// 출력
	cout << answer << "\n";
}