//
// Created by KangMinji on 2023-01-08.
//

/*
 * 1) 구조체 원소로 '가입한 순서'도 추가하기
 * 2) stable_sort 함수 사용하기기 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
    int age;
    string name;
    int order;
};

bool cmp(const person &a, const person &b){
    if (a.age != b.age){
        return a.age < b.age;
    }
    return a.order < b.order;
}

int main() {
    int N;

    // 입력
    cin >> N;
    vector<person> people(N, {0, ""});

    for (int i=0; i<N; i++){
        cin >> people[i].age >> people[i].name;
        people[i].order = i;
    }

    // 연산
    stable_sort(people.begin(), people.end(), cmp);

    // 출력
    for (int i=0; i<N; i++){
        cout << people[i].age << " " << people[i].name << "\n";
    }
}