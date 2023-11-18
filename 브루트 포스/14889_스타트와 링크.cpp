// 실버2
// Created by KangMinji on 2023-03-21.
// https://www.acmicpc.net/problem/14889

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e4; // 최대 99*99 - 1*1

vector<vector<int>> board;
vector<bool> visited;
int answer = MAX;

int calcSum(vector<int> &team){
	int size = team.size();

	int sum = 0;
	for (int i=0; i<size; i++){
		for (int j=i+1; j<size; j++){
			sum += board[team[i]][team[j]] + board[team[j]][team[i]];
		}
	}
	return sum;
}

void calcDiff(int n) {
	vector<int> teamA;
	vector<int> teamB;

	for (int i=0; i<n; i++){
		if (visited[i]){
			teamA.push_back(i);
		} else {
			teamB.push_back(i);
		}
	}

	int diff = abs(calcSum(teamA) - calcSum(teamB));
	answer = min(answer, diff);
}

void findMinDiff(int cnt, int idx, int n){
	if (cnt == n/2){
		calcDiff(n);
		return;
	}
	for (int i=idx; i<n; i++){
		if (visited[i]){
			continue;
		}
		visited[i] = true;
		findMinDiff(cnt+1, i+1, n); // 🔥 idx가 아니라 i 넣어야 함
		visited[i] = false;
	}
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;

	// 입력
	cin >> n;
	board.assign(n, vector<int>(n, 0));
	visited.assign(n, false);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}

	// 연산
	findMinDiff(0, 0, n);

	// 출력
	cout << answer << "\n";
}