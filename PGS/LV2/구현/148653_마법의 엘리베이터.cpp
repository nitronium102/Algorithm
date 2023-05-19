//
// Created by KangMinji on 2023-05-19.
// https://school.programmers.co.kr/learn/courses/300/lessons/148653

#include <string>
#include <vector>

using namespace std;

// 버튼 누르면 ( 현재 층 수 + 버튼에 적혀 있는 값 ) 층으로 이동
// 0보다 작으면 움직이지 않음
int solution(int storey) {
	int answer = 0;

	while(storey){
		int one_place = storey % 10;
		int ten_place = (storey / 10) % 10;
		// 1) 1의 자리가 5 초과인 경우
		if (one_place > 5){
			answer += 10 - one_place;
			storey += 10;
		}
			// 2) 1의 자리가 5인 경우
		else if (one_place == 5){
			answer += 5;
			storey += ten_place >= 5 ? 10 : 0; // 올림 / 내림
		}
			// 3) 1의 자리가 5 미만인 경우 : 내림
		else {
			answer += one_place;
		}
		storey /= 10;
	}
	return answer;
}