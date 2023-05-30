// 골드4
// Created by KangMinji on 2023-04-03.
// https://www.acmicpc.net/problem/2580

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ci;

int board[9][9];
vector<ci> blank;
bool is_fill = false;

bool check(int row, int col, int num){
	// 1) 해당 행 & 열 확인
	for (int i=0; i<9; i++){
		if ((board[row][i] == num && i != col)
			|| (board[i][col] == num && i != row)){
			return false;
		}
	}

	// 3x3 박스 확인
	int r_box = (row/3)*3;
	int c_box = (col/3)*3;
	for (int i=r_box; i<r_box + 3; i++){
		for (int j=c_box; j<c_box + 3; j++){
			if (board[i][j] == num && i != row && j != col){
				return false;
			}
		}
	}
	return true;
}

void backtracking(int cnt, int n){
	if (cnt == n){
		is_fill = true;
		return;
	}

	int row = blank[cnt].first;
	int col = blank[cnt].second;

	for (int i=1; i<10; i++){
		board[row][col] = i;

		// 가능 여부 확인
		if (check(row, col, i)){
			backtracking(cnt+1, n);
		}

		// 백트래킹 이후 돌아왔을 때, 그것이 정답이면 board 수정 없이 바로 리턴
		if (is_fill){
			return;
		}

		board[row][col] = 0;
	}
}

int main() {
	// 입력
	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++){
			cin >> board[i][j];
			if (!board[i][j]){
				blank.push_back({i, j});
			}
		}
	}

	// 연산
	backtracking(0, blank.size());

	// 출력
	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++){
			cout << board[i][j] << ' ';
		}
		cout << "\n";
	}
}