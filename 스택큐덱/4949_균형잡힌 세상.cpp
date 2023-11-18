// 실버4
// Created by KangMinji on 2023-03-03.
// https://www.acmicpc.net/problem/4949

#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool isBalanced(string input) {
	map<char, char> mp;
	mp[')'] = '(';
	mp[']'] = '[';

	stack<int> s;
	for (int i = 0; i < input.length(); i++) {
		switch(input[i]){
			case '(': case '[':
				s.push(input[i]);
				break;
			case ')': case ']':
				if (!s.empty() && s.top() == mp[input[i]]){
					s.pop();
					break;
				}
				return false;
		}
	}
	return s.empty();
}

int main() {
	string input;

	while(getline(cin, input)){
		if (input == "."){
			break;
		}
		// 연산 & 출력
		if (isBalanced(input)){
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
}