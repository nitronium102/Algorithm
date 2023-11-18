// 골드5
// Created by KangMinji on 2023-10-07.
// https://www.acmicpc.net/problem/11000

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

int n;
vector<ci> lecture;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	int start, end;
	for (int i=0; i<n; i++){
		cin >> start >> end;
		lecture.push_back({start, end});
	}

	// 연산
	sort(lecture.begin(), lecture.end());

	pq.push(lecture[0].second);
	for (int i=1; i<lecture.size(); i++){
		int end_time = pq.top();
		pq.pop();

		int s = lecture[i].first;
		int e = lecture[i].second;

		// 강의실 새로 잡아야 하는 경우
		if (s < end_time){
			pq.push(end_time); // 원래 뺐던 강의 종료 다시 넣고
		}
		pq.push(e); // 현재 강의 종료 시간 다시 넣기
	}

	// 출력
	cout << pq.size() << "\n";
}