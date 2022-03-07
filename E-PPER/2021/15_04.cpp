//
// EPPER 15-04. 100 만들기
// Created by Kang Minji on 2021-09-09.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num, sum = 0;
    vector<int> v;
    for (int i=0; i<9; i++){
        cin >> num;
        sum += num;
        v.push_back(num);
    }

    for (int i=0; i<8; i++){ // 숫자 7개
        for (int j=i+1; j<9; j++){
            if (sum - v[i] - v[j] == 100){
                // erase는 순차적으로 삭제하기 때문에 앞의 idx 먼저 삭제할 경우 순서 오류
                if (i < j){
                    v.erase(v.begin() + j);
                    v.erase(v.begin() + i);
                }
                else {
                    v.erase(v.begin() + i);
                    v.erase(v.begin() + j);
                }
            }
        }
    }

    // 출력
    for (int i=0; i<7; i++){
        cout << v[i] << " ";
    }
}