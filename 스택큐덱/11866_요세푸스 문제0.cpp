// 실버5
// Created by KangMinji on 2023-03-03.
// https://www.acmicpc.net/problem/11866

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n, k;

	// 입력
	cin >> n >> k;

	queue<int> q;
	for (int i=1; i<=n; i++){
		q.push(i);
	}

	// 연산
	vector<int> v;
	int cnt = 0;
	while(!q.empty()){
		if (cnt == k - 1){
			v.push_back(q.front());
			q.pop();
			cnt = 0;
			continue;
		}
		q.push(q.front());
		q.pop();
		cnt++;
	}

	// 출력
	cout << '<';
	for (int i=0; i<v.size()-1; i++){
		cout << v[i] << ", ";
	}
	cout << v[v.size()-1] << '>';
}