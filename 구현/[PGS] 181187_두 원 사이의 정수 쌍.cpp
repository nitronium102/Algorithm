// LV2
// Created by KangMinji on 2023-04-29.
// https://school.programmers.co.kr/learn/courses/30/lessons/181187

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

long long solution(int r1, int r2) {
	ll answer = 0;

	ll r1_pow = pow(r1, 2);
	ll r2_pow = pow(r2, 2);

	// 축 위에 있는 점
	answer += (r2 - r1 + 1)*4;

	// 좌표평면 위에 있는 점
	int upper, lower;
	for(int i=1; i<r2; i++){
		upper = (int)floor(sqrt(r2_pow - pow(i, 2)));
		if (i < r1){
			lower = (int)ceil(sqrt(r1_pow - pow(i, 2)));
		} else {
			lower = 1; // 0으로 설정하면 축이랑 겹침
		}
		answer += (upper - lower + 1) * 4;
	}

	return answer;
}