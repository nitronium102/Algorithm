// 실버1
// Created by KangMinji on 2023-04-05.
// https://www.acmicpc.net/problem/20923

#include <iostream>
#include <deque>
using namespace std;

void combineCard(deque<int> &winner, deque<int> &ground){
	while(!ground.empty()){
		winner.push_back(ground.back());
		ground.pop_back();
	}
}

string playGame(int m, deque<int> &dodo, deque<int> &susu){
	deque<int> dodo_ground, susu_ground;

	bool flag = true;
	while(m--){
		if (flag) {
			// 1) 도도 - 수연 순으로 그라운드에 숫자가 보이도록 내려놓는다
			dodo_ground.push_front(dodo.front());
			dodo.pop_front();

			if (dodo.empty()){
				return "su";
			}
		} else {
			susu_ground.push_front(susu.front());
			susu.pop_front();

			if (susu.empty()){
				return "do";
			}
		}

		flag = !flag;

		// 2) 종을 칠 수 있는지 확인 & 그라운드 카드 가져가기
		if (!dodo_ground.empty() && !susu_ground.empty() && susu_ground.front() + dodo_ground.front() == 5){
			combineCard(susu, dodo_ground);
			combineCard(susu, susu_ground);
		} else if (!dodo_ground.empty() && dodo_ground.front() == 5 || !susu_ground.empty() && susu_ground.front() == 5){
			combineCard(dodo, susu_ground);
			combineCard(dodo, dodo_ground);
		}
	}

	if (dodo.size() < susu.size()){
		return "su";
	} else if (dodo.size() > susu.size()){
		return "do";
	}
	return "dosu";
}

int main() {
	int n, m, card1, card2;

	// 입력
	cin >> n >> m;
	deque<int> dodo, susu;

	while(n--){
		cin >> card1 >> card2;
		dodo.push_front(card1);
		susu.push_front(card2);
	}

	// 연산
	cout << playGame(m, dodo, susu);
}