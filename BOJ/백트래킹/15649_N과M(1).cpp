// 실버3
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/15649

#include <iostream>
using namespace std;

int N, M;
int num[9];
int ans[9];
bool visited[9];

void backtracking(int cnt){
	if (cnt == M) {
		for (int i=0; i<M; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}

	for (int i=0; i<N; i++){
		if (visited[i]){
			continue;
		}
		ans[cnt] = num[i];
		visited[i] = true;
		backtracking(cnt+1);
		visited[i] = false;
	}
}

int main() {
	// 입력
	cin >> N >> M;
	for (int i=0; i<N; i++){
		num[i] = i+1;
	}

	// 연산
	backtracking(0);
}
