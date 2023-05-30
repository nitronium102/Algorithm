//
// Created by KangMinji on 2023-01-10.
//

#include <iostream>

using namespace std;

string maxNum(string n, int x, int y) {
    string answer = "";
    char c;
    bool is_small = false;

    // 2) 주어진 x, y로 만들 수 있는지 확인
    for (int i = 0; i < n.length(); i++) {
        int num = n[i] - '0';

        // 종료조건
        // 1) num < x인 경우 만들 수 없음
        // 2) str이 0을 포함하지 않고, x가 0이고, num < y인 경우
        if (!is_small && (num < x )) {
            answer = "-1";
            break;
        }

        if (is_small) {
            answer += (char) (y + 48);
            continue;
        }

        if (num >= x && num < y) {
            c = (char) (x + 48);
        } else {
            c = (char) (y + 48);
        }
        answer += c;

        if (answer.length() ==1 && answer == "0"){
            answer = "-1";
            break;
        }

        if (num - (c - '0') > 0) {
            is_small = true;
        }
    }
    return answer;
}

/*
    0<= x < y <= 9
    1) x와 y를 모두 사용하는 경우
    2) x와 y 중 하나만 사용하는 경우
 */
int main() {
    int T, x, y;
    string N;

    // 입력
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> N >> x >> y;
        cout << "#" << test_case << " " << maxNum(N, x, y) << "\n";
    }

}