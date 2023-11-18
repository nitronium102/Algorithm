// 실버2
// Created by KangMinji on 2023-06-15.
// https://www.acmicpc.net/problem/1406

#include <iostream>
#include <list>

using namespace std;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	int m;
	char op, c;

	list<char> word;
	auto iter = word.end();

	// 입력
	cin >> str >> m;
	for (char s: str) {
		word.push_back(s);
	}

	// 연산
	while (m--) {
		cin >> op;
		switch (op) {
			case 'L':
				if (iter != word.begin())
					iter--;
				break;
			case 'D':
				if (iter != word.end())
					iter++;
				break;
			case 'B':
				if (iter != word.begin()) {
					iter--;
					iter = word.erase(iter);
				}
				break;
			case 'P':
				cin >> c;
				word.insert(iter, c);
				break;
		}
	}

	// 출력
	for (char w : word){
		cout << w;
	}
}