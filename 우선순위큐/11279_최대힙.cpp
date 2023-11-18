// 실버2
// Created by KangMinji on 2023-04-06.
// https://www.acmicpc.net/problem/11279

#include <iostream>
#include <queue>
using namespace std;

int main() {
	// 시간초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, x;
	priority_queue<int, vector<int>> pq;

	// 입력
	cin >> n;
	while(n--){
		cin >> x;
		if (x){
			pq.push(x);
		} else {
			if (!pq.empty()){
				cout << pq.top() << "\n";
				pq.pop();
			} else {
				cout << "0\n";
			}
		}
	}
}