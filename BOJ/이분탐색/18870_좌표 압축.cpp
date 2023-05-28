// 실버2 / 이분탐색
// Created by KangMinji on 2023-02-06.
// https://www.acmicpc.net/problem/18870

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;

	// 입력
	cin >> n;
	vector<int> num(n, 0);
	for (int i=0; i<n; i++){
		cin >> num[i];
	}
	vector<int> arr = num;

	// 연산
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	// 출력
	for (int i=0; i<n; i++){
		cout << lower_bound(arr.begin(), arr.end(), num[i]) - arr.begin() << " ";
	}
}