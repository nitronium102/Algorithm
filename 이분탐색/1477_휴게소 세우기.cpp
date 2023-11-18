// 골드4 / 이분탐색
// Created by KangMinji on 2023-02-06.
// https://www.acmicpc.net/problem/1477

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rest;

int checkMid(int mid){
	int sum = 0;
	for (int i=1; i<rest.size(); i++){
		int dist = rest[i] - rest[i-1];
		int cnt = dist / mid;

		if (cnt > 0){
			if (dist % mid == 0){
				sum += cnt - 1;
			} else {
				sum += cnt;
			}
		}
	}
	return sum;
}

int main() {
	int n, m, l, dist;

	// 입력
	cin >> n >> m >> l;
	for (int i=0; i<n; i++){
		cin >> dist;
		rest.push_back(dist);
	}
	// 시작점과 끝 점에는 휴게소 세울 수 없음
	rest.push_back(0);
	rest.push_back(l);
	sort(rest.begin(), rest.end());

	// 연산
	int left = 1, right = l-1, mid, ans = 1000;

	while (left <= right){
		mid = (left + right)/2;
		int sum = checkMid(mid); // 휴게소의 개수

		if (sum > m){
			left = mid + 1;
		} else {
			right = mid - 1;
			ans = min(ans, mid);
		}
	}

	cout << ans;
}