// 실버3
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/15651

#include <iostream>
#include <vector>
using namespace std;

int N, M;
int num[9] = {0, };

void backtracking(int cnt){
	if (cnt == M){
		for (int i=0; i<M; i++){
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i=1; i<=N; i++){
		num[cnt] = i;
		backtracking(cnt+1);
	}
}

int main() {

	// 입력
	cin >> N >> M;
	for (int i=1; i<=N; i++){
		num[i] = i;
	}

	// 연산 & 출력
	backtracking(0);
}