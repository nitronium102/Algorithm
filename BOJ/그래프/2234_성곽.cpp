// 골드3
// Created by KangMinji on 2023-02-17.
// https://www.acmicpc.net/problem/2234

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> ci;

int n, m;
int board[50][50];
bool visited[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y){

}

int main() {

	// 입력
	cin >> n >> m;

	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}

	// 1번 : cnt / 2번 : max1 / 3번 : max1+max2
	int cnt = 0, max1 = 0, max2 = 0;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if (!visited[i][j]){
				bfs(i, j);

			}
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			for (int k=1; k<=8; k*=2){

			}
		}
	}
}