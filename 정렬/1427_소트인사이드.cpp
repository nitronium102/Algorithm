//
// Created by KangMinji on 2023-01-12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* int형 범위 안에 있음*/
int main() {
    int N;
    vector<int> num_list;

    // 입력
    cin >> N;
    string str = to_string(N);
    num_list.assign(str.length(), 0);

    for (int i=0; i<str.length(); i++){
        num_list[i] = str[i]-'0';
    }

    // 연산
    sort(num_list.begin(), num_list.end(), greater<>());

    // 출ㄺ
    for (int i=0; i<str.length(); i++){
        cout << num_list[i];
    }
}