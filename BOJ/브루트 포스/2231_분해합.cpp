// 브론즈2
// Created by KangMinji on 2023-01-24.
// https://www.acmicpc.net/problem/2231

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, sum, temp;

	// 입력
	cin >> N;

	// 연산
	for (int num=N/2; num<N; num++){
		sum = num;
		temp = num;
		while(temp > 0){
			sum += temp%10;
			temp /= 10;
		}
		if (sum == N){
			cout << num << "\n";
			return 0;
		}
	}
	cout << "0" << "\n";
	return 0;
}