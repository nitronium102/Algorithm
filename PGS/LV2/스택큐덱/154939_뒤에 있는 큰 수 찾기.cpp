// LV2
// Created by KangMinji on 2023-05-04.
// https://school.programmers.co.kr/learn/courses/30/lessons/154539

#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer(numbers.size(), -1);
	stack<int> st;

	for (int i=0; i<numbers.size(); i++){
		int num = numbers[i];
		while(!st.empty() && numbers[st.top()] < num){
			answer[st.top()] = num;
			st.pop();
		}
		st.push(i);
	}
	return answer;
}