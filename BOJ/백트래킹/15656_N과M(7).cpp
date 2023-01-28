// 실버3
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/15656

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num;
int ans[9];

void backtracking(int cnt){
	if (cnt == M){
		for (int i=0; i<M; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i=0; i<N; i++){
		ans[cnt] = num[i];
		backtracking(cnt+1);
	}
}

int main() {
	// 입력
	cin >> N >> M;
	num.assign(N, 0);
	for (int i=0; i<N; i++){
		cin >> num[i];
	}
	sort(num.begin(), num.end());

	// 연산 & 출력
	backtracking(0);
}
