// 골드5
// Created by KangMinji on 2023-01-19.
// https://www.acmicpc.net/problem/5430

#include <iostream>
#include <deque>

using namespace std;

void printResult(bool isReversed, bool isError, deque<int> &dq) {
    if (isError) {
        cout << "error\n";
        return;
    }
    cout << "[";
    while (!dq.empty()) {
        if (isReversed) {
            cout << dq.back();
            dq.pop_back();
        } else {
            cout << dq.front();
            dq.pop_front();
        }
        if (!dq.empty()) {
            cout << ",";
        }
    }
    cout << "]\n";
}

void playAC(string p, deque<int> &dq) {
    bool isReversed = false, isError = false;

    for (auto c: p) {
        // 1) Reverse하는 경우
        if (c == 'R') {
            isReversed = !isReversed;
        }
            // 2) 첫 번째 수를 버리는 경우
        else if (c == 'D') {
            if (dq.empty()) {
                isError = true;
                break;
            }
            if (!isReversed) {
                dq.pop_front();
            } else {
                dq.pop_back();
            }
        }
    }

    // 출력
    printResult(isReversed, isError, dq);
}

int main() {
    int T, n;
    string p, data;

    // 입력
    cin >> T;
    while (T--) {
        cin >> p >> n >> data;

        string str = "";
        deque<int> dq;

        for (auto c: data) {
            if (isdigit(c)) {
                str += c;
            } else if (str != "") {
                dq.push_back(stoi(str));
                str = "";
            }
        }

        // 연산 & 출력
        playAC(p, dq);
    }
}