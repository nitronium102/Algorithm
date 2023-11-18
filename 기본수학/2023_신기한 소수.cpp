// 골드5
// Created by KangMinji on 2023-05-22.
// https://www.acmicpc.net/problem/2023

#include <iostream>
#include <vector>
using namespace std;

bool checkPrime(int num){
	for (int i=2; i*i<=num; i++){
		if (num % i == 0){
			return false;
		}
	}
	return true;
}

void backtracking(int num, int cnt, int n){
	if (!checkPrime(num)){ // 소수가 아닌 경우
		return;
	}
	if (cnt == n){
		cout << num << "\n";
		return;
	}
	for (int i=1; i<10; i++){
		backtracking(num*10 + i, cnt+1, n);
	}
}

int main() {
	int n;

	// 입력
	cin >> n;

	// 연산
	vector<int> prime = {2, 3, 5, 7};
	for (int i=0; i<prime.size(); i++){
		backtracking(prime[i], 1, n);
	}
}