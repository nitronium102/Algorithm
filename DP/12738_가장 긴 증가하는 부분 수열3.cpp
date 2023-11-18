// 골드2
// Created by KangMinji on 2023-08-09.
// https://www.acmicpc.net/problem/12738

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
vector<int> v;

void binarySearch(int left, int right, int num) {
	int mid;
	while(left < right) { // 🔥🔥🔥🔥
		mid = (left + right) / 2;
		if (num > v[mid]) {
			left = mid+1;
		} else {
			right = mid; // 🔥🔥🔥🔥
		}
	}
	v[right] = num;
	return;
}

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}

	// 리스트의 마지막보다 큰 값이 들어오는 경우 리스트의 뒤에 추가
	// 리스트의 마지막보다 작은 값이 들어오는 경우 이분탐색을 이용하여 리스트 안의 값을 update
	for (int i=0; i<n; i++) {
		if (v.empty() || arr[i] > v[v.size()-1]){
			v.push_back(arr[i]);
		} else {
			binarySearch(0, v.size()-1, arr[i]);
		}
	}

	// 출력
	cout << v.size();
}