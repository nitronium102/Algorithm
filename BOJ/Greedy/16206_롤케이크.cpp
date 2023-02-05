// 실버1
// Created by KangMinji on 2023-02-01.
// https://www.acmicpc.net/problem/16206

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int &a, const int &b) {
	if (a % 10 != b % 10) {
		return a % 10 < b % 10;
	}
	return a < b;
}

vector<int> ten;
vector<int> not_ten;
int n, m;
int ans = 0;
int cut_cnt = 0;

void cutCake(int length){
	if (cut_cnt >= m || length < 10){
		return;
	}

	length -= 10;
	ans++;
	cut_cnt++;

	if (length > 10){
		cutCake(length);
	} else if (length == 10){
		ans++;
	}
	return;
}

int main() {
	int cake;

	// 입력
	cin >> n >> m;
	ten.assign(n, 0);
	not_ten.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> cake;
		if (cake % 10 == 0){
			ten.push_back(cake);
		} else {
			not_ten.push_back(cake);
		}
	}

	// 연산
	sort(ten.begin(), ten.end());
	sort(not_ten.begin(), not_ten.end());

	for (int c : ten){
		if (c == 10) {
			ans++;
			continue;
		}
		cutCake(c);
	}

	for (int c : not_ten){
		cutCake(c);
	}

	cout << ans << "\n";
}