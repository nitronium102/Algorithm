// 실버2
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/11279

#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	ll x;

	priority_queue<ll> pq;

	// 입력
	cin >> n;
	while(n--){
		cin >> x;
		if (x == 0){
			if (!pq.empty()){
				cout << pq.top() << "\n";
				pq.pop();
			} else {
				cout << "0\n";
			}
		} else {
			pq.push(x);
		}
	}
}