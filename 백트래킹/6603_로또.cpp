// 실버2
// Created by KangMinji on 2023-06-29.
// https://www.acmicpc.net/problem/6603

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void countPermutation(int k, int cnt, vector<int> &arr){
	vector<bool> v(k, true);
	fill(v.begin(), v.begin() + k - cnt, false);

	do {
		for (int i=0; i<k; i++){
			if (v[i] == 0) continue;
			cout << arr[i] << ' ';
		}
		cout << '\n';
	} while(next_permutation(arr.begin(), arr.end()));
}

int main() {
	// 시간 초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;

	while(cin >> k){
		if (k == 0){
			break;
		}
		vector<int> arr(k, 0);
		for (int i=0; i<k; i++){
			cin >> arr[i];
		}

		// 기본 false로 설정하기 -> false인 애들만 출력
		vector<bool> v(k, false);
		for (int i=6; i<k; i++)
			v[i] = true;

		do {
			for (int i=0; i<k; i++){
				if (v[i]) continue;
				cout << arr[i] << ' ';
			}
			cout << '\n';
		} while(next_permutation(v.begin(), v.end()));

		cout << '\n';
	}
}