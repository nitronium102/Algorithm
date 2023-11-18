// 실버3
// Created by KangMinji on 2023-01-18.
// https://www.acmicpc.net/problem/18115

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*
 * 1) 카드 front를 push_front
 * 2) 카드 front를 pop_front -> push_ front 2회
 * 3) 카드 front를 push_back
 */
int main() {
    int N, num;
    vector<int> bottom;
    deque<int> original;
    vector<int> game;

    // 입력
    cin >> N;
    game.assign(N, 0);
    for (int i=1; i<=N; i++){
        bottom.push_back(i);
    }

    for (int i=N-1; i>=0; i--){
        cin >> num;
        game[i] = num;
    }

    // 연산
    for (int i=0; i<N; i++){
        switch (game[i]) {
            case 1:
                original.push_front(bottom[i]);
                break;
            case 2:
                if (!original.empty()){
                    int temp = original.front();
                    original.pop_front();
                    original.push_front(bottom[i]);
                    original.push_front(temp);
                }
                break;
            case 3:
                original.push_back(bottom[i]);
                break;
        }
    }

    // 출력
    while(!original.empty()){
        cout << original.front() << " ";
        original.pop_front();
    }
}