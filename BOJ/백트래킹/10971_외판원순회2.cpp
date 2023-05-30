// 실버2
// Created by KangMinji on 2023-04-03.
// https://www.acmicpc.net/problem/10971

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> cost;
vector<bool> visited;
int answer = 1e7 + 1;

void backtracking(int start, int cnt, int sum){
	if (cnt == n){
		if (cost[start][0]) {
			// 도착지에서 시작 정점으로 돌아가는 cost 포함해야 함
			answer = min(answer, sum + cost[start][0]);
		}
		return;
	}
	for (int i=0; i<n; i++){
		if (visited[i] || !cost[start][i]){
			continue;
		}
		visited[i] = true;
		backtracking(i, cnt+1, sum + cost[start][i]);
		visited[i] = false;
	}
}

int main() {

	// 입력
	cin >> n;
	cost.assign(n, vector<int>(n, 0));
	visited.assign(n, false);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> cost[i][j];
		}
	}

	// 연산
	visited[0] = true; // 시작 지점 표시
	backtracking(0, 1, 0);

	// 출력
	cout << answer << "\n";
}