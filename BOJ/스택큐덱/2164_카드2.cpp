// 실버4
// Created by KangMinji on 2023-03-03.
// https://www.acmicpc.net/problem/2164

#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n;

	// 입력
	cin >> n;
	deque<int> dq;
	for (int i=1; i<=n; i++){
		dq.push_back(i);
	}

	// 연산
	while(dq.size() > 1){
		dq.pop_front();
		int card = dq.front();
		dq.pop_front();
		dq.push_back(card);
	}

	// 출력
	cout << dq.front() << '\n';
}