//
// Created by KangMinji on 2023-05-03.
// https://school.programmers.co.kr/learn/courses/30/lessons/155651

#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<string>> book_time) {
	int answer = 0;

	int time[25][61] = {0, }; // 분, 시간

	for (int i=0; i<book_time.size(); i++){
		int sh = stoi(book_time[i][0].substr(0, 2));
		int sm = stoi(book_time[i][0].substr(3, 2));
		int eh = stoi(book_time[i][1].substr(0, 2));
		int em = stoi(book_time[i][1].substr(3, 2)) + 10;

		eh += em / 60;
		em = em % 60;

		for (int h=sh; h<=eh; h++){
			for (int m=0; m<60; m++){
				// 시작 시간 이전인 경우
				if (h== sh && m < sm){
					continue;
				}
				// 종료 시간 이후인 경우
				if (h == eh && m >= em){
					break;
				}
				time[h][m]++;
			}
		}
	}

	for (int i=0; i<24; i++){
		for (int j=0; j<60; j++){
			answer = max(answer, time[i][j]);
		}
	}
	return answer;
}