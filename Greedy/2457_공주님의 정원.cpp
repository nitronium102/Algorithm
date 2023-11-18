// 골드3
// Created by KangMinji on 2023-10-06.
// https://www.acmicpc.net/problem/2457

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

int n;
int s1, e1, s2, e2;
vector<ci> flower;
int answer = 0;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> e1 >> s2 >> e2;
		flower.push_back({s1 * 100 + e1, s2 * 100 + e2});
	}

	/*
	 * 매번 현재 시점에서 피어있는 꽃 중에서 가장 마지막에 지는 꽃 선택하기
	 * 총 276일의 기간이므로 모든 꽃이 하루만에 지었다 펴도 O(276N) 가능
	 */
	int time = 301; // 3월 1일(시작 시간)
	while(time < 1201) {
		int next = time;
		for (int i=0; i<n; i++){
			if (flower[i].first <= time && flower[i].second > next){
				next = flower[i].second;
			}
		}

		if (next == time){ // 변경사항 없을 때 (더 늦게 안 질 때)
			cout << 0;
			return 0;
		}
		answer++;
		time = next;
	}

	// 출력
	cout << answer << "\n";
}