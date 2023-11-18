// 브론즈1
// Created by KangMinji on 2023-03-30.
// https://www.acmicpc.net/problem/3226

#include <iostream>
#include <string>
using namespace std;

int calcCharge(int start_hour, int start_min, int time){
	int end_hour = (start_hour + (start_min + time) / 60) % 24;
	int end_min = (start_min + time) % 60;

	// 시간대 다른 경우
	if (start_hour == 6 && end_hour == 7){
		return 5 * (time - end_min) + 10 * end_min;
	} else if (start_hour == 18 && end_hour == 19){
		return 10 * (time - end_min) + 5 * end_min;
	}

		// 시간대 같은 경우
	else if (start_hour > 6 && start_hour < 19){
		return 10 * time;
	}
	return 5 * time;
}

int main() {
	int n, start_hour, start_min, time;
	string input;

	// 입력
	cin >> n;

	int answer = 0;
	while(n--){
		getline(cin, input, ':');
		cin >> start_min >> time;
		start_hour = stoi(input);

		answer += calcCharge(start_hour, start_min, time);
	}

	// 출력
	cout << answer << '\n';
}