// 실버2
// Created by KangMinji on 2023-04-06.
// https://www.acmicpc.net/problem/18111

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ci;
const int MAX = 1e9;

int n, m, b;

int simulate(int block, int height, vector<vector<int>> board){
	int time = 0;

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			int diff = board[i][j] - height;
			block += diff;
			if (diff > 0) { // 블록 제거
				time += diff * 2;
			} else if (diff < 0){ // 블록 추가
				time -= diff;
			}
		}
	}
	if (block < 0){
		return MAX;
	}
	return time;
}

int main() {

	// 입력
	cin >> n >> m >> b;
	vector<vector<int>> board(n, vector<int>(m, 0));

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}

	// 연산 & 출력
	int min_time = 6.4 * 1e7;
	int max_height = 0;
	for (int height = 256; height >= 0; height--){
		int time = simulate(b, height, board);
		if (time < min_time){
			min_time = time;
			max_height = height;
		}
	}
	cout << min_time << " " << max_height;
}