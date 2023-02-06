// 골드2 / 이분 탐색
// Created by KangMinji on 2023-02-06.
// https://www.acmicpc.net/problem/12015

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;

	// 입력
	cin >> n;
	vector<int> A(n, 0);
	for (int i=0; i<n; i++){
		cin >> A[i];
	}

	// 연산
	vector<int> v;
	v.push_back(A[0]);

	for (int i=1; i<n; i++){
		// 맨 뒷자리에 바로 넣는 경우(증가)
		if (v.back() < A[i]){
			v.push_back(A[i]);
		}
		// 이전 자리를 찾아서 넣어주는 경우
		else {
			auto it = lower_bound(v.begin(), v.end(), A[i]);
			*it = A[i]; // A[i] 이상의 값을 갖는 첫 번째 위치에 A[i] 삽입
		}
	}
	cout << v.size();
}