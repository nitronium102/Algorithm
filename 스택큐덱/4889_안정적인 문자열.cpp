// 실버1
// Created by KangMinji on 2023-03-03.
// https://www.acmicpc.net/problem/4889

#include <iostream>
#include <stack>
#include <map>
using namespace std;

int countChange(string input){
	map<char, char> mp;
	mp['}'] = '{';

	stack<int> s;
	for (int i=0; i<input.length(); i++){
		switch(input[i]){
			case '{':
				s.push(input[i]);
				break;
			case '}':
				if (!s.empty() && s.top() == mp[input[i]]){
					s.pop();
				} else {
					s.push(input[i]);
				}
				break;
		}
	}

	int answer = 0;
	while(!s.empty()){
		char n1 = s.top();
		s.pop();
		char n2 = s.top();
		s.pop();

		if (n1 == n2){
			answer++;
		} else {
			answer+=2;
		}
	}

	return answer;
}

int main() {
	int cnt = 1;
	string input;

	while(getline(cin, input)){
		if (input.find("-") != string::npos){
			break;
		}
		cout << cnt << ". " << countChange(input) << '\n';
		cnt++;
	}
}