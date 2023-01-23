// 골드2
// Created by KangMinji on 2023-01-23.
// https://www.acmicpc.net/problem/1918

#include <iostream>
#include <stack>
#include <map>
using namespace std;

map<char, int> m;
stack<char> op;

void init(){
	m['+'] = 1;
	m['-'] = 1;
	m['*'] = 2;
	m['/'] = 2;
}

// 우선순위가 낮은 연산자부터 큰 연산자 순으로 쌓인다
void findPostfix(string str){
	for (char c : str) {
		// 문자열인 경우 바로 출력
		if (isupper(c)){
			cout << c;
			continue;
		}

		switch (c) {
			case '(':
				op.push(c);
				break;
			case ')':
				while (op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.pop();
				break;
			default:
				while (!op.empty() && m[op.top()] >= m[c]){
					cout << op.top();
					op.pop();
				}
				op.push(c);
				break;
		}
	}
}

int main() {
	string str;

	init();
	// 입력
	cin >> str;

	// 연산 & 출력
	findPostfix(str);
	while(!op.empty()){
		cout << op.top();
		op.pop();
	}

}