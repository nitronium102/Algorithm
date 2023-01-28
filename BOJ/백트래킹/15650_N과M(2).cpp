// 실버3
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/15650

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num;
bool visited[9];
int ans[9];

void backtracking(int cnt, int idx){
	if (cnt == M){
		for (int i=0; i<M; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i<N; i++){
		if (visited[i]){
			continue;
		}
		ans[cnt] = num[i];
		visited[i] = true;
		// idx가 아니라 i값을 넘겨야 함
		backtracking(cnt+1, i+1);
		visited[i] = false;
	}
}

int main() {
	// 입력
	cin >> N >> M;
	for (int i=1; i<=N; i++){
		num.push_back(i);
	}
	sort(num.begin(), num.end());

	// 연산
	backtracking(0, 0);
}