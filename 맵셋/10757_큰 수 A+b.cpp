// 브론즈5
// Created by KangMinji on 2023-03-02.
// https://www.acmicpc.net/problem/10757

#include <iostream>
#include <stack>
using namespace std;

stack<int> calcPlus(string a, string b){
	int a_len = a.length();
	int b_len = b.length();

	if (a_len != b_len){
		for (int i=0; i<a_len - b_len; i++){
			b = '0' + b;
		}
	}

	bool carry = false;
	stack<int> s;
	for (int i=a.length() - 1; i>=0; i--){
		int num = a[i] - '0' + b[i] - '0';

		num += carry;
		carry = num / 10;
		s.push(num % 10);
	}
	if (carry){
		s.push(1);
	}
	return s;
}

int main() {
	string a, b;

	// 입력
	cin >> a >> b;

	// 연산
	if (a.length() < b.length()){
		swap(a, b);
	}
	stack<int> s = calcPlus(a, b);

	// 출력
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
}