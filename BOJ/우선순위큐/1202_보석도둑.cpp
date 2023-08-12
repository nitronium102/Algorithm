// 골드2
// Created by KangMinji on 2023-08-10.
// https://www.acmicpc.net/problem/1202

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ci;

int n, k;
ci jewel[300001]; // {무게, 가격}
int bag[300001];
priority_queue<int, vector<int>> pq;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> jewel[i].first >> jewel[i].second;

	for (int i = 0; i < k; i++)
		cin >> bag[i];

	sort(jewel, jewel + n); // 보석 무게 오름차순
	sort(bag, bag + k); // 가방 오름차순

	int idx = 0;
	long long sum = 0;
	// 1. 남은 가방 중 제일 작은 가방을 선택
	for (int i = 0; i < k; i++) {
		while (idx < n && bag[i] >= jewel[idx].first) {
			pq.push(jewel[idx].second);
			idx++;
		}
		// 2. 선택된 가방에 넣을 수 있는 남은 보석 중 가장 비싼 보석을 선택
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;
}