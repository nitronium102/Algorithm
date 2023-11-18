// 실버3
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/2108

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef pair<int, int> ci;
const int MAX = 4000;

bool cmp(const ci &a, const ci &b){
	if (a.second != b.second){
		return a.second > b.second;
	}
	return a.first < b.first;
}

int findMode(int n, vector<ci> &freq) {
	sort(freq.begin(), freq.end(), cmp);

	if (freq[0].second == freq[1].second){
		return freq[1].first;
	}
	return freq[0].first;
}

int main() {
	int n;
	double sum = 0;

	// 입력
	cin >> n;
	vector<int> v(n, 0);
	vector<ci> freq(MAX * 2 + 1);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		freq[v[i] + MAX].first = v[i];
		freq[v[i] + MAX].second++;
	}

	// 연산
	sort(v.begin(), v.end());
	cout << (int) round(sum / n) << '\n';
	cout << v[n / 2] << '\n';
	cout << findMode(n, freq) << '\n';
	cout << v[n - 1] - v[0];
}