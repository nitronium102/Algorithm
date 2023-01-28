// 실버3
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/15654

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 9;

int N, M;
vector<int> num;
bool visited[MAX];
int ans[MAX];

void backtracking(int cnt){
	if (cnt == M){
		for (int i=0; i<M; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i=0; i<N; i++){
		if (visited[i]){
			continue;
		}
		ans[cnt] = num[i];
		visited[i] = true;
		backtracking(cnt+1);
		ans[cnt] = 0;
		visited[i] = false;
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