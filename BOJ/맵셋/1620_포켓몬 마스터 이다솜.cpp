// 실버4
// Created by KangMinji on 2023-03-02.
// https://www.acmicpc.net/problem/1620

#include <iostream>
#include <map>
using namespace std;

int main() {
	// 시간초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	string input;
	map<string, int> pk_name;
	map<int, string> pk_no;

	// 입력
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> input;
		pk_name[input] = i;
		pk_no[i] = input;
	}

	// 연산
	while(m--){
		cin >> input;
		if (isdigit(input[0])){
			cout << pk_no[stoi(input)] << '\n';
		} else {
			cout << pk_name[input] << "\n";
		}
	}
}