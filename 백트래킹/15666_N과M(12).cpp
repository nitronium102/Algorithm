// 실버2
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/15664

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

	// 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같은 경우
	int last = -1; // 따로 만들어주지 않고 ans[cnt] 값을 쓰면 계속 덮어씌워짐
	for (int i=idx; i<N; i++){
		if (last == num[i]){
			continue;
		}
		ans[cnt] = last = num[i];
		backtracking(cnt+1, i);
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
	backtracking(0, 0);
}
