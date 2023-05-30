//
// Created by KangMinji on 2023-01-11.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> num_list(2, 0);
string N;
string answer;
string num;
bool is_small;

// a<=b인지 확인
bool cmp(const string a, const string b){
    // answer <= N
    if (a.length() > b.length()){
        return false;
    }
    else if (a.length() == b.length()){
        return a <= b;
    }
    return true;
}

void maxNum(){
//    if (num.length() > 0 && num[0] != '0' && cmp(num, N)){
////        answer = max(answer, stoi(num));
////        answer = to_string(max(stoi(answer), stoi(num)));
//        if (cmp(answer, num)){
//            answer = num;
//        }
//    }
    if (num.length() == N.length()){
        if (num[0] == '0'){
            return;
        }
        if (num <= N && cmp(answer, num)){
            answer = num;
        }
        return;
    }

    if (!is_small){
        num += to_string(num_list[1]);
        maxNum();
    } else {
        for (int i = 0; i < 2; i++) {
            num += to_string(num_list[i]);
            maxNum();
            num.pop_back();
        }
    }

    if (num[num.length()-1]
}

int main(){
    int T;

    // 입력
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        // 초기화
        answer = "-1";
        num = "";
        is_small = false;

        cin >> N >> num_list[0] >> num_list[1];
        maxNum();
        cout << "#" << test_case << " " << answer << "\n";
    }
}