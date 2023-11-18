//
// Created by KangMinji on 2023-02-24.
// https://school.programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int &a, const int &b){
	string sa = to_string(a);
	string sb = to_string(b);
	return sa + sb > sb + sa;
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), cmp);

	for (int num : numbers){
		answer += to_string(num);
	}

	// answer가 0으로 시작하는 경우
	if (answer[0] == '0'){
		answer = '0';
	}

	return answer;
}