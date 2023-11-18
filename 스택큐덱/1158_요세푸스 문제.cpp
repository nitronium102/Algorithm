// 실버4
// Created by KangMinji on 2023-01-18.
// https://www.acmicpc.net/problem/1158

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int N, K;
    deque<int> dq;
    vector<int> yosepus;

    // 입력
    cin >> N >> K;
    for (int i=1; i<=N; i++){
        dq.push_back(i);
    }

    // 연산
    while(!dq.empty()){
        for (int i=0; i<K-1; i++){
            dq.push_back(dq.front());
            dq.pop_front();
        }
        yosepus.push_back(dq.front());
        dq.pop_front();
    }

    // 출력
    cout << "<";
    for (int i=0; i<N-1; i++){
        cout << yosepus[i] << ", ";
    }
    cout << yosepus[yosepus.size()-1] << ">";

}