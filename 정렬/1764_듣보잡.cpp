//
// Created by KangMinji on 2023-01-12.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, M;
    string name;
    set<string> never_heard, answer;

    // 입력 & 연산
    cin >> N >> M;
    while(N--){
        cin >> name;
        never_heard.insert(name);
    }
    while(M--){
        cin >> name;
        if (never_heard.find(name) != never_heard.end()){
            answer.insert(name);
        }
    }

    // 출력
    cout << answer.size() << "\n";
    for (auto iter : answer){
        cout << iter << "\n";
    }
}