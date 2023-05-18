//
// Created by KangMinji on 2023-05-18.
// https://school.programmers.co.kr/learn/courses/30/lessons/150368

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int subscribe_cnt = 0;
int price_cnt = 0;
vector<int> discount;
int arr[4] = {10, 20, 30, 40};

void dfs(int cnt, vector<vector<int>> &users, vector<int> &emoticons){
	if (cnt == emoticons.size()){
		int tmp_subscribe = 0;
		int tmp_price = 0;

		// 톡서랍 플러스 가입자 & 이모티콘 가격 확인
		for (int i=0; i<users.size(); i++){
			int total_price = 0;

			for (int j=0; j<emoticons.size(); j++){
				if (discount[j] >= users[i][0]){
					total_price += (emoticons[j] * (100 - discount[j]) / 100);
				}
			}

			if (total_price >= users[i][1]){
				tmp_subscribe++;
			} else {
				tmp_price += total_price;
			}
		}


		if (tmp_subscribe > subscribe_cnt){
			subscribe_cnt = tmp_subscribe;
			price_cnt = tmp_price;
		} else if (tmp_subscribe == subscribe_cnt){
			price_cnt = max(price_cnt, tmp_price);
		}
		return;
	}

	for (int i=0; i<4; i++){
		discount.push_back(arr[i]);
		dfs(cnt+1, users, emoticons);
		discount.pop_back();
	}
}

/*
일정 비율 이상 할인하는 이모티콘을 모두 구매
이모티콘 구매 비용의 합 >= 일정 가격 => 모두 취소 후 이모티콘 플러스 서비스에 가입
*/
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;

	dfs(0, users, emoticons);
	answer = {subscribe_cnt, price_cnt};
	return answer;
}