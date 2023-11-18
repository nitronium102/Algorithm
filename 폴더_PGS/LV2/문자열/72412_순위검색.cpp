// LV2
// Created by KangMinji on 2023-09-11.
// https://school.programmers.co.kr/learn/courses/30/lessons/72412

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> data_parse(string data) {
	vector<string> key;
	string tmp = "";

	for(auto c: data) {
		if(c == ' ') {
			if(tmp != "and") key.push_back(tmp);
			tmp = "";
		}
		else tmp += c;
	}

	key.push_back(tmp);

	return key;
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	unordered_map<string, vector<int>> db;
	for(auto inf: info) {
		vector<string> key = data_parse(inf);

		for(int i=0; i<16; ++i) {
			string tmp = "";
			for(int j=0; j<4; ++j) {
				tmp += (i & (1 << j)) ? key[j] : "-";
			}
			db[tmp].push_back(stoi(key[4]));
		}
	}

	// lower_bound 사용 위해 sort
	for(auto &iter: db) sort(iter.second.begin(), iter.second.end());

	for(auto q: query) {
		vector<string> key = data_parse(q);

		string k = key[0] + key[1] + key[2] + key[3];
		vector<int> res = db[k];

		int cnt = res.end() - lower_bound(res.begin(), res.end(), stoi(key[4]));
		answer.push_back(cnt);
	}

	return answer;
}