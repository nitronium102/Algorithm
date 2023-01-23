//
// Created by KangMinji on 2023-01-18.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N, h;
    stack<int> s;

    // 입력
    cin >> N;
    while(N--){
        cin >> h;
        s.push(h);
    }

    // 연산
    int answer = 0;
    int num = -1;

    while(!s.empty()){
        if (num < s.top()){
            answer++;
            num = s.top();
        }
        s.pop();
    }

    // 출력
    cout << answer << "\n";
}