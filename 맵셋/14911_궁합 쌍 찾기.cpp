// 실버4
// Created by KangMinji on 2023-03-02.
// https://www.acmicpc.net/problem/14911

#include <iostream>
#include <map>

using namespace std;

int findPair(int goal, map<int, int> &m) {

	int answer = 0;

	for (auto i: m) {
		int num = i.first;
		int cp = goal - num;

		// 중간 이하의 값인 경우(중복 제거)
		if (cp < (goal + 1) / 2) {
			break;
		}

		m[num]--; // 일종의 인덱스 개념을 하는 듯??
		if (m[cp]) {
			cout << num << ' ' << cp << '\n';
			m[cp]--;
			answer++;
		}
	}
	return answer;
}

int main() {
	int num, goal;
	map<int, int> m;

	// 입력
	while (cin >> num) {
		m[num]++;
	}
	m[num]--;
	goal = num;

	// 연산
	cout << findPair(goal, m);

}