// 골드3
// Created by KangMinji on 2023-08-16.
// https://www.acmicpc.net/problem/2252

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 32005;

int n, m;
vector<int> arr[MAX];
int indegree[MAX]; // 학생 앞에 와야 하는 학생이ㅡ 수
queue<int> q;
vector<int> answer;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> m;
	int pre, next;
	for (int i = 0; i < m; i++) {
		cin >> pre >> next;
		indegree[next]++; // 뒤 학생의 indegree++;
		arr[pre].push_back(next); // 앞 학생의 자식 추가
	}

	// 연산
	for (int i=1; i<=n; i++){
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		answer.push_back(cur);

		for (auto iter : arr[cur]){
			indegree[iter]--;
			if (indegree[iter] == 0){
				q.push(iter);
			}
		}
	}

	for (int ans : answer){
		cout << ans << ' ';
	}
}