// 실버4
// Created by KangMinji on 2023-02-01.
// https://www.acmicpc.net/problem/11399

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;

	// 입력
	cin >> n;
	vector<int> time(n, 0);
	for (int i=0; i<n; i++){
		cin >> time[i];
	}

	// 연산
	sort(time.begin(), time.end());
	int ans = 0;
	int sum = 0;
	for (int i=0; i<n; i++){
		sum += time[i];
		ans += sum;
	}

	// 출력
	cout << ans << "\n";
}