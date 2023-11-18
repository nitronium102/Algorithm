// 골드4
// Created by KangMinji on 2023-04-03.
// https://www.acmicpc.net/problem/15685

#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 100;

int board[SIZE+1][SIZE+1];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int cntSquare() {
	int answer = 0;
	for (int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			if (board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]){
				answer++;
			}
		}
	}
	return answer;
}

void makeCurve(int &x, int &y, vector<int> &dir){
	// 1) 뒤집기
	for (int i=dir.size()-1; i>=0; i--){
		// 2) 각 방향 + 1
		int nd = (dir[i] + 1) % 4;
		x += dx[nd];
		y += dy[nd];
		board[x][y] = 1;
		dir.push_back(nd);
	}
}

int main() {
	int n, x, y, d, g;

	// 입력
	cin >> n;
	while(n--){
		cin >> x >> y >> d >> g;
		vector<int> dir; // 방향 저장

		// 0세대 드래곤 커브
		board[x][y] = 1; // 초기값
		x += dx[d];
		y += dy[d];
		board[x][y] = 1; // 끝값
		dir.push_back(d);

		// 1 ~ g세대 드래곤 커브
		while(g--) {
			makeCurve(x, y, dir);
		}
	}

	// 연산
	cout << cntSquare();

}