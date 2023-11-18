//
// Created by KangMinji on 2023-01-13.
//

#include <iostream>
#include <stack>
using namespace std;

string checkIsVPS(string str){
    stack<char> s;
    for (int i=0; i<str.length(); i++){
        char c = str[i];
        if (c == '('){
            s.push(c);
        } else {
            if (s.empty()){
                return "NO";
            }
            s.pop();
        }
    }

    if (s.empty()){
        return "YES";
    }
    return "NO";
}

int main() {
    int T;
    string str;

    // 입력
    cin >> T;
    while(T--){
        cin >> str;
        cout << checkIsVPS(str) << "\n";
    }
}