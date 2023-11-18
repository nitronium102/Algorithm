// 골드4
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/3078

#include <iostream>
#include <queue>
using namespace std;
/*
 *  좋은 친구는 등수의 차이가 K보다 작거나 같으면서 이름의 길이가 같은 친구이다.
 */


int main() {
	int N, K;
	string name;
	queue<int> q[21]; // 이름별로 저장

	// 입력
	cin >> N >> K;

	long long answer = 0;
	for (int i=1; i<=N; i++){
		cin >> name;
		int len = name.length();

		while (!q[len].empty() && i-q[len].front() > K){
			q[len].pop();
		}
		answer += q[len].size();
		q[len].push(i);
	}

	// 출력
	cout << answer << "\n";
}