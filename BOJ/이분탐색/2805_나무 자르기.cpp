// 실버2
// Created by KangMinji on 2023-07-25.
// https://www.acmicpc.net/problem/2805

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1e6 + 1;

int height[MAX];

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	// 입력
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> height[i];
	}

	// 연산
	int answer = 0;
	int start = 0, end = *max_element(height, height+MAX);

	while(start <= end) {
		long long total = 0;
		int mid = (start + end)/2;

		for (int i=0; i<n; i++){
			if (height[i] > mid) {
				total += height[i] - mid;
			}
		}

		if (total < m){
			end = mid-1;
		} else {
			answer = mid;
			start = mid+1;
		}
	}
	cout << answer << "\n";
}