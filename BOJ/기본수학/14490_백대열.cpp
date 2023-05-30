// 실버4
// Created by KangMinji on 2023-03-06.
// https://www.acmicpc.net/problem/14490

#include <iostream>
using namespace std;

int findGCD(int a, int b){
	if (b == 0){
		return a;
	}
	return findGCD(b, a%b);
}

int main() {
	string input;

	// 입력
	cin >> input;

	int idx = input.find(":");
	int n = stoi(input.substr(0, idx));
	int m = stoi(input.substr(idx+1, input.length()));

	// 연산
	int gcd = findGCD(max(n, m), min(n, m));

	// 출력
	cout << n / gcd << ':' << m / gcd;
}