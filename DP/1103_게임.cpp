// 골드2
// Created by KangMinji on 2023-05-30.
// https://www.acmicpc.net/problem/1103

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<int>> dp;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isRange(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}

int dfs(int x, int y){
	// 1) 구멍이거나 탈출하는 경우
	if (!isRange(x, y) || board[x][y] == 0){
		return 0;
	}

	// 2) 사이클이 발생한 경우
	if (visited[x][y]){
		cout << -1 << "\n";
		exit(0);
	}

	// 3) 이미 방문한 경우 -> 근데 2)에서 안 걸리고 여기로 올 수가 있나???
	// 제일 처음 (0, 0)을 위한 것 같기도 하고..
	if (dp[x][y] != -1){
		return dp[x][y];
	}

	visited[x][y] = true;
	dp[x][y] = 0;

	for (int i=0; i<4; i++){
		int nx = x + (dx[i] * board[x][y]);
		int ny = y + (dy[i] * board[x][y]);

		dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}

	visited[x][y] = false;
	return dp[x][y];
}

int main() {
	string input;

	// 입력
	cin >> n >> m;
	board.assign(n, vector<int>(m, 0));
	dp.assign(n, vector<int>(m, -1));
	visited.assign(n, vector<bool>(m, false));

	for (int i=0; i<n; i++){
		cin >> input;
		for (int j=0; j<m; j++){
			if (input[j] == 'H'){
				board[i][j] = 0;
			} else {
				board[i][j] = input[j] - '0';
			}
		}
	}

	// 연산 & 출력
	cout << dfs(0, 0);
}