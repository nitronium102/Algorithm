// 실버4
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/2960

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;

	// 입력
	cin >> n >> k;

	// 연산
	int cnt = 0;
	vector<bool> v(n+1, true);
	for (int i=2; i<=n; i++){
		if (!v[i]){
			continue;
		}
		for (int j=i; j<=n; j+=i){
			if (!v[j]){
				continue;
			}
			cnt++;
			v[j] = false;
			if (cnt == k){
				cout << j << '\n';
				return 0;
			}
		}
	}
}