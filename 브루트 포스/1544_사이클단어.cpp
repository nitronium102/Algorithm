// 실버4
// Created by KangMinji on 2023-03-29.
// https://www.acmicpc.net/problem/1544

#include <iostream>
#include <set>
using namespace std;

bool isCycle(string word, set<string> &s){
	for (int i=0; i<word.size(); i++){
		word += word[0];
		word.erase(0, 1);

		if (s.find(word) != s.end()){
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	string str;

	// 입력
	cin >> n;
	set<string> s;
	while (n--){
		cin >> str;

		if (!isCycle(str, s)){
			s.insert(str);
		}
	}

	// 출력
	cout << s.size() << '\n';
}