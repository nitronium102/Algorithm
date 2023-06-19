// 실버1
// Created by KangMinji on 2023-06-18.
// https://www.acmicpc.net/problem/2504

#include <iostream>
#include <stack>
using namespace std;

int main() {
	// 시간
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	string str;
	cin >> str;

	stack<char> st;
	int answer = 0, num = 1;
	for (int i=0; i<str.length(); i++){
		char c = str[i];
		if (c == '('){
			num *= 2;
			st.push(c);
		} else if (c == '['){
			num *= 3;
			st.push(c);
		} else if (c == ')'){
			if (st.empty() || st.top() != '('){
				cout << 0;
				return 0;
			}
			if (str[i-1] == '(') // 그냥 st.top()으로 하면 연쇄작용 발생
				answer += num;
			st.pop();
			num /= 2;
		} else if (c == ']'){
			if (st.empty() || st.top() != '['){
				cout << 0;
				return 0;
			}
			if (str[i-1] == '[')
				answer += num;
			st.pop();
			num /= 3;
		}
	}

	// 출력
	if (st.empty())
		cout << answer;
	else
		cout << 0;
}