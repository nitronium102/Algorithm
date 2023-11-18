//
// Created by KangMinji on 2023-02-18.
//

#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main() {
	int n, btn;
	char c;

	// 입력
	cin >> n;

	// 연산
	deque<char> dq;
	stack<bool> order; // true : 앞, false : 뒤
	while(n--){
		cin >> btn;
		switch(btn) {
			case 1:
				cin >> c;
				dq.push_back(c);
				order.push(false);
				break;
			case 2:
				cin >> c;
				dq.push_front(c);;
				order.push(true);
				break;
			case 3:
				if (!dq.empty() && !order.empty()){
					bool is_front = order.top();
					order.pop();
					if (is_front){
						dq.pop_front();
					} else {
						dq.pop_back();
					}
				}
				break;
		}
	}

	// 출력
	string answer = "";
	while(!dq.empty()){
		answer += dq.front();
		dq.pop_front();
	}

	if (answer.length() == 0){
		cout << 0;
	} else {
		cout << answer << "\n";
	}
}