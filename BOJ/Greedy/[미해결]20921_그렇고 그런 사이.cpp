// 실버2
// Created by KangMinji on 2023-02-01.
// https://www.acmicpc.net/problem/20921

#include <iostream>
#include <vector>

using namespace std;
int n, k;
vector<int> a;

int main() {
	int n, k;
	vector<int> num;

	// 입력
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		num.push_back(i);
	}

	// 연산
	if (k == 0) {
		for (int n: num) {
			cout << n << ' ';
			return 0;
		}
	}

	for(int i=0; i<n; i++){
		for (int j=n-1; j>=0; j--){


		}
	}

}