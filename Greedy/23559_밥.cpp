// 실버1
// Created by KangMinji on 2023-02-01.
// https://www.acmicpc.net/problem/27277

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

bool cmp(const ci &a, const ci &b){
	int ta = abs(a.first - a.second);
	int tb = abs(b.first - b.second);
	if (ta != tb){
		return ta > tb;
	}
	return a.second > b.second;
}

/*
 *  1) 기본적으로 1000원짜리 택하고
 *  2) 5000원짜리가 1000원보다 나으면 그걸로 바꾸기
 */
int main() {
	int n, x;
	int ans = 0;

	// 입력
	cin >> n >> x;
	vector<ci> taste(n, {0, 0});
	for (int i=0; i<n; i++){
		cin >> taste[i].first >> taste[i].second;
		ans += taste[i].second;
		x -= 1000;
	}

	// 연산
	sort(taste.begin(), taste.end(), cmp);

	for (int i=0; i<n; i++){
		if (x <= 0){
			break;
		}
		// 5000원짜리 학식을 먹을 수 있는 경우
		if (taste[i].first > taste[i].second && x >= 4000){
			ans += taste[i].first - taste[i].second;
			x -= 4000;
		}
	}

	// 출력
	cout << ans << "\n";
}