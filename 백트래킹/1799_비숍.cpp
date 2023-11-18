// 골드1
// Created by KangMinji on 2023-07-07.
// https://www.acmicpc.net/problem/1799

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;

int n;
// board[color][j] -> 해당 색상 & 우하향 대각선에 포함되는 좌표들
// j : 우하향 대각선의 인덱스
vector<ci> board[2][20];
bool visited[2][20];
int ans[2];

void bishop(int idx, int cnt, int color) {
	if (idx == 2*n){
		ans[color] = max(ans[color], cnt);
		return;
	}

	// 1) 해당 대각선에서 비숍을 놓을 수 있는 경우
	for (ci v : board[color][idx]) {
		int x = v.first;
		int y = v.second;
		if (visited[color][x+y]) continue;
		visited[color][x+y] = true;
		bishop(idx+1, cnt+1, color);
		visited[color][x+y] = false;
	}
	// 2) 해당 대각선에서 비숍을 놓을 수 없는 경우 -> cnt 증가없이 바로 다음 idx로!
	bishop(idx+1, cnt, color);
}

// 비숍은 대각선 방향으로 움직인다
int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	int input;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> input;
			if (input == 1)
				board[(i+j)%2][n+i-j-1].push_back({i, j});
		}
	}

	// 연산
	bishop(0, 0, 0);
	bishop(0, 0, 1);

	// 출력
	cout << ans[0] + ans[1];
}