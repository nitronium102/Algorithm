// 실버3
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/15652

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num;
int ans[9];

void backtracking(int cnt, int idx){
	if (cnt == M){
		for (int i=0; i<M; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i=idx; i<N; i++){
		ans[cnt] = num[i];
		backtracking(cnt+1, i);
	}
}

int main() {
	// 입력
	cin >> N >> M;

	// 초기화
	for (int i=1; i<=N; i++){
		num.push_back(i);
	}
	sort(num.begin(), num.end());

	// 연산
	backtracking(0, 0);
}