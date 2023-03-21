// 실버5
// Created by KangMinji on 2023-03-21.
// https://www.acmicpc.net/problem/1436

#include <iostream>
using namespace std;

int main() {
	int n;

	// 입력
	cin >> n;

	// 연산
	int cnt = 0;
	for (long long i=666; ; i++){
		if (to_string(i).find("666") != string::npos){
			cnt++;
		}

		if (cnt == n){
			cout << i << "\n";
			return 0;
		}
	}
}