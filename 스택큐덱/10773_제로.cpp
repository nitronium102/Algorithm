// 실버4
// Created by KangMinji on 2023-06-17.
// https://www.acmicpc.net/problem/10773

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int k, num;
	stack<int> st;

	// 입력
	cin >> k;
	while(k--){
		cin >> num;
		if (num == 0){ // 지울 수가 있음을 보장 가능
			st.pop();
		} else {
			st.push(num);
		}
	}

	// 연산
	long long total = 0;
	while(!st.empty()){
		total += st.top();
		st.pop();
	}

	// 출력
	cout << total;
}