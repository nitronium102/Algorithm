// 골드5
// Created by KangMinji on 2023-01-19.
// https://www.acmicpc.net/problem/2493

#include <iostream>
#include <stack>
using namespace std;
typedef pair<int, int> ci;

int main() {
    int N, height;
    stack<ci> s;

    // 입력
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> height;
        while(!s.empty()){
            // 수신 가능한 경우
            if (height < s.top().second){
                cout << s.top().first << " ";
                break;
            }
            // 수신 불가능한 경우
            s.pop();
        }
        if (s.empty()){
            cout << "0 ";
        }
        s.push({i, height});
    }
}