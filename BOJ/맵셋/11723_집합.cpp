// 실버5
// Created by KangMinji on 2023-03-02.
// https://www.acmicpc.net/problem/11723

#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 21;

int main() {
	// 시간 초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, x;
	string input;

	// 입력
	cin >> m;

	vector<bool> v(SIZE, false);
	while(m--){
		cin >> input;

		if (input == "all"){
			for (int i=1; i<=20; i++){
				v[i] = i;
			}
		} else if (input == "empty"){
			v.assign(SIZE, false);
		}

		else {
			cin >> x;
			if (input == "add") {
				v[x] = true;
			} else if (input == "remove") {
				v[x] = false;
			} else if (input == "check") {
				cout << v[x] << '\n';
			} else if (input == "toggle") {
				v[x] = !v[x];
			}
		}
	}
}