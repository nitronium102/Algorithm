// 실버2 / 이분탐색
// Created by KangMinji on 2023-02-06.
// https://www.acmicpc.net/problem/2630

#include <iostream>
using namespace std;

int board[128][128];
int white_cnt = 0;
int blue_cnt = 0;

void checkColor(int color){
	if (!color){
		white_cnt++;
	} else {
		blue_cnt++;
	}
}

// x,y : 사분면의 좌측 상단 좌표
// length : 해당 박스의 한 변의 길이
void findWhite(int x, int y, int length){
	int color = board[x][y];

	if (length == 1){
		checkColor(color);
		return;
	}

	// 해당 사분면이 모두 같은 색인지 확인
	bool isSame = true;
	for (int i=x; i<x+ length; i++){
		for (int j=y; j<y+length; j++){
			if (color != board[i][j]){
				isSame = false;
				break;
			}
		}
	}

	// 모두 같은 색이고 흰색 칸이라면
	if (isSame){
		checkColor(color);
		return;
	}

	// 모두 같은 색이 아니라면
	int half = length/2;
	findWhite(x, y, half);
	findWhite(x+half, y, half);
	findWhite(x, y+half, half);
	findWhite(x+half, y+half, half);
}

int main() {
	int n;

	// 입력
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}

	// 연산
	findWhite(0, 0, n);

	// 출력
	cout << white_cnt << "\n" << blue_cnt;
}