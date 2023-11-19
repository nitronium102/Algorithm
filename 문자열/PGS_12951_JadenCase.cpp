// LV2
// Created by KangMinji on 2023-11-19.
// https://school.programmers.co.kr/learn/courses/30/lessons/12951

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	string answer = "";

	// 0) 기본적으로 모두 소문자로 변경
	for (int i=0; i<s.size(); i++){
		if (s[i] != ' ' && isupper(s[i])){
			s[i] = tolower(s[i]);
		}
	}

	// 1) 첫 문자를 대분자로 변경
	if (islower(s[0])){
		s[0] = toupper(s[0]);
	}

	// 2) 공백 뒤 첫 단어를 모두 대문자로 변경
	for (int i=0; i<s.size(); i++) {
		if (s[i] == ' '){
			s[i+1] = toupper(s[i+1]);
		}
	}

	answer = s;
	return answer;
}