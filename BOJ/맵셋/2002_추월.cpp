// 실버1
// Created by KangMinji on 2023-03-02.
// https://www.acmicpc.net/problem/2002

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int n;
	string input;

	// 입력
	cin >> n;
	map<string, int> order;
	for (int i=0; i<n; i++){
		cin >> input;
		order[input] = i;
	}

	vector<int> seq;
	for (int i=0; i<n; i++){
		cin >> input;
		seq.push_back(order[input]);
	}

	// 연산
	int answer = 0;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if (seq[i] > seq[j]){
				answer++;
				break;
			}
		}
	}

	// 출력
	cout << answer << '\n';
}