//
// Created by KangMinji on 2023-02-18.
// queue & 누적합을 통해 쉽게 풀 수 있다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, l;

	// 입력
	cin >> n >> l;

	vector<int> alcohol(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> alcohol[i];
	}

	// 연산
	queue<int> q;

	int total = 0, answer = 0;
	for (int i = 0; i < n; i++) {
		if (q.size() == l) {
			total -= q.front();
			q.pop();
		}
		q.push(alcohol[i]);
		total += alcohol[i];

		if (total >= 129 && total <= 138){
			answer++;
		}
	}

	// 출력
	cout << answer << "\n";

}