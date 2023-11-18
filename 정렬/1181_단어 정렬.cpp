//
// Created by KangMinji on 2023-01-12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b){
    if (a.length() == b.length()){
        return a<b;
    }
    return a.length() < b.length();
}

int main() {
    int N;

    // 입력
    cin >> N;
    vector<string> alphabet(N, "");
    for (int i=0; i<N; i++){
        cin >> alphabet[i];
    }

    // 연산(중복 제거 https://scarlettb.tistory.com/70)
    sort(alphabet.begin(), alphabet.end(), cmp);
    alphabet.erase(unique(alphabet.begin(), alphabet.end()), alphabet.end());

    // 출력
    for (int i=0; i<alphabet.size(); i++){
        cout << alphabet[i] << "\n";
    }
}