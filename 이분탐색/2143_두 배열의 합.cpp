// 골드3
// Created by KangMinji on 2023-07-25.
// https://www.acmicpc.net/problem/2143

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1005];
int b[1005];
vector<int> suba;
vector<int> subb;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int t, n, m;
	cin >> t;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];

	// 연산
	// 1) subA, subB 만들기
	for (int i = 0; i < n; i++) {
		int sum = a[i];
		suba.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += a[j];
			suba.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++) {
		int sum = b[i];
		subb.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += b[j];
			subb.push_back(sum);
		}
	}

	sort(subb.begin(), subb.end());

	// 2) 투포인터 적용
	long long answer = 0;
	for (int i = 0; i < suba.size(); i++) {
		int diff = t - suba[i];
		auto high = upper_bound(subb.begin(), subb.end(), diff); // diff값 초과하는 첫 번째 원소의 위치
		auto low = lower_bound(subb.begin(), subb.end(), diff); // diff보다 크거나 같은 첫 번째 원소의 위치
		answer += (high - low);

	}
	cout << answer << '\n';

}