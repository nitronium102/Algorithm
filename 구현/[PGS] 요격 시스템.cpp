// LV2
// Created by KangMinji on 2023-04-29.
// https://school.programmers.co.kr/learn/courses/30/lessons/181188

#include <vector>
#include <algorithm>
using namespace std;

// 종료 시간 기준으로 정렬
bool cmp(const vector<int> &a, const vector<int> &b){
    if (a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {

    sort(targets.begin(), targets.end(), cmp);

    int end = targets[0][1]; // 종료 시간
    int answer = 1;
    for (int i=0; i<targets.size(); i++){
        if (end <= targets[i][0]){
            end = targets[i][1];
            answer++;
        }
    }
    return answer;
}