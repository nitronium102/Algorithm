// 실버2
// Created by KangMinji on 2023-02-01.
// https://www.acmicpc.net/problem/27112
// 참고 : https://measurezero.tistory.com/m/1687

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

bool cmp(const ci &a, const ci &b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	int n;

	// 입력
	cin >> n;
	vector<ci> task(n + 1, {0, 0});

	for (int i = 1; i <= n; i++) {
		cin >> task[i].first >> task[i].second;
	}

	// 연산
	sort(task.begin(), task.end(), cmp);


	int answer = 0;
	int day, dwork, ework; // 요일, 평시 근무, 시간 외 근무
	day = dwork = ework = 0;
	for (int i=1; i<=n; i++){
		while(day < task[i].first){
			// 평일인 경우 평시 근무도 가능
			if (day % 7 < 5) {
				dwork++;
			}
			ework++;
			day++;
		}
		// 1) 평시 근무 만으로 해결되는 경우
		if (dwork >= task[i].second){
			dwork -= task[i].second;
		}
		// 2) 추가 근무로 해결되는 경우
		else if (dwork + ework >= task[i].second){
			int remain = task[i].second - dwork;
			dwork = 0;
			ework -= remain;
			answer += remain;
		}
		// 3) 추가 근무해도 해결 불가
		else {
			cout << -1 << "\n";
			return 0;
		}
	}
	cout << answer << "\n";
}