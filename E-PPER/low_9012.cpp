//
// Created by KangMinji on 2022-03-14.
//

/*
 * 괄호 : (와 )개수가 동일하면 VPS
 * (와 )의 개수를 확인
 * 1) '('가 들어올 때마다 stack에 넣어놓는다
 * 2) ')'가 들어오면
 *      (1) stack에 '('가 들어있으면 pop
 *      (2) stack에 아무것도 없으면 isVPS = false;
 * 3) 마지막 문자열까지 검사했을 때 stack에 남은 게 없다면 성공!
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> solution(int T, vector<string> data){
    vector<string> answer;

    bool isVPS;
    for (int i=0; i<T; i++){
        isVPS = true;
        stack<char> parenthesis;

        for (int j=0; j<data[i].size(); j++){
            if (data[i][j] == '(')
                parenthesis.push('(');
            else {
                if (!parenthesis.empty())
                    parenthesis.pop();
                else {
                    isVPS = false;
                    break;
                }
            }
        }
        if (isVPS && parenthesis.empty())
            answer.push_back("YES");
        else
            answer.push_back("NO");
    }
    return answer;

}

int main() {
    int T;
    string str;
    vector<string> data;

    // 입력
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> str;
        data.push_back(str);
    }

    // 연산
    auto answer = solution(T, data);

    // 출력
    for (int i=0; i<T; i++){
        cout << answer[i] << "\n";
    }

}

/*

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool solution(int T, string data){
    bool answer;
    stack<char> parenthesis;

    for (int i=0; i<T; i++){
        for (int j=0; j<data.size(); j++){
            if (data[j] == '(')
                parenthesis.push('(');
            else {
                if (!parenthesis.empty())
                    parenthesis.pop();
                else {
                    return false;
                }
            }
        }
    }
    return parenthesis.empty();

}

int main() {
    int T;
    string str;
    vector<string> data;

    // 입력
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> str;
        data.push_back(str);
    }

    // 출력
    for (int i=0; i<T; i++){
        bool isVPS = solution(T, data[i]);
        if (isVPS)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

}

*/