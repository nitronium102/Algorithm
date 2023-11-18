//
// Created by KangMinji on 2023-01-12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<int> num_list;

    // 입력
    cin >> N;
    num_list.assign(N, 0);
    for (int i=0; i<N; i++){
        cin >> num_list[i];
    }

    // 연산
    sort(num_list.begin(), num_list.end(), greater<>());

    // 출력
    for (int i=0; i<N; i++){
        cout << num_list[i] << "\n";
    }
}