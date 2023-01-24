// 실버2
// Created by KangMinji on 2023-01-24.
// https://www.acmicpc.net/problem/1182

#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> num;
int ans = 0;

void dfs(int cnt, int sum){
	if (cnt == N){
		if (sum == S){
			ans++;
		}
		return;
	}
	dfs(cnt+1, sum); // 현재 숫자 안 더하는 경우
	dfs(cnt+1, sum + num[cnt]); // 현재 숫자 더하는 경우
}

int main() {

	// 입력
	cin >> N >> S;
	num.assign(N, 0);
	for (int i=0; i<N; i++){
		cin >> num[i];
	}

	// 연산
	dfs(0, 0);

	// 출력
	// S가 0일 때는 공집합일 때를 고려해서 -1 (수열의 원소 개수가 양수여야 함)
	if (S == 0){
		ans--;
	}
	cout << ans << "\n";
}