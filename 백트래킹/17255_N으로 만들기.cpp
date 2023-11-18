// 골드4
// Created by KangMinji on 2023-04-03.
// https://www.acmicpc.net/problem/17255

#include <iostream>
#include <set>
using namespace std;

string n;
set<string> s;

void makeNum(int left, int right, string path){
	if (left == 0 && right == n.length() - 1){
		s.insert(path);
		return;
	}

	// 범위 체크
	if (left > 0){
		makeNum(left-1, right,  path + n[left - 1] + path);
	} if (right < n.length() - 1){
		makeNum(left, right+1,  path + path + n[right+1]);
	}
}

int main() {
	// 입력
	cin >> n;

	// 연산
	for (int i=0; i<n.length(); i++){
		string tmp = "";
		makeNum(i, i, tmp + n[i]);
	}

	// 출력
	cout << s.size();
}