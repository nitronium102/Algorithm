//
// Created by KangMinji on 2023-01-12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
    string name;
    int kor;
    int eng;
    int math;
};

// a가 b보다 먼저 나오는 게 맞아?
bool cmp(const student &a, const student &b){
    // 1) 국어 점수 감소하는 순서
    if (a.kor != b.kor){
        return a.kor > b.kor;
    }
    // 2) 영어 점수 증가하는 순서
    if (a.eng != b.eng){
        return a.eng < b.eng;
    }
    // 3) 수학 점수 감소하는 순서
    if (a.math != b.math){
        return a.math > b.math;
    }
    return a.name < b.name;
}

int main() {
    int N;
    vector<student> student_list;

    // 입력
    cin >> N;
    student_list.assign(N, {"#", 0, 0, 0});

    for (int i=0; i<N; i++){
        cin >> student_list[i].name >> student_list[i].kor >> student_list[i].eng >> student_list[i].math;
    }

    // 연산
    sort(student_list.begin(), student_list.end(), cmp);

    // 출력
    for (int i=0; i<N; i++){
        cout << student_list[i].name << "\n";
    }
}