// LV2
// Created by KangMinji on 2023-05-04.
// https://school.programmers.co.kr/learn/courses/30/lessons/152996

#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int SIZE = 1001;

vector<ll> cnt(SIZE, 0);

long long solution(vector<int> weights) {
	long long answer = 0;

	for (int weight : weights){
		cnt[weight]++;
	}

	// 비율 2:3, 3:4, 1:2
	ll partner;
	for (int weight : weights){
		if (weight%2 == 0){ // 2:3
			partner = (weight/2) * 3;
			if (partner < SIZE) {
				answer += cnt[partner];
			}
		} if (weight%3 == 0){ // 3:4
			partner = (weight/3) * 4;
			if (partner < SIZE){
				answer += cnt[partner];
			}
		}
		// 1:2
		partner = weight * 2;
		if (partner < SIZE){
			answer += cnt[partner];
		}
	}

	// 몸무게 같은 사람끼리
	for (int i=100; i<SIZE; i++){
		if (cnt[i] >=2){
			answer += (ll)(cnt[i] * (cnt[i]-1)) / 2;
		}
	}
	return answer;
}