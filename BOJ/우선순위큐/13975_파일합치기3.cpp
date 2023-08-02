// 골드4
// Created by KangMinji on 2023-07-28.
// https://www.acmicpc.net/problem/13975

#include <iostream>
#include <queue>
using namespace std;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, k, file;

	// 입력
	cin >> t;
	while(t--){
		priority_queue<long long, vector<long long>, greater<>> pq;

		cin >> k;
		while(k--){
			cin >> file;
			pq.push(file);
		}

		long long answer = 0;
		while(!pq.empty()){
			if (pq.size() == 1){
				break;
			}
			long long f1 = pq.top(); pq.pop();
			long long f2 = pq.top(); pq.pop();
			answer += f1+f2;
			pq.push(f1+f2);
		}

		// 출력
		cout << answer << '\n';
	}
}