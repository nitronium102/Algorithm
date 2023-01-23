//
// Created by KangMinji on 2023-01-13.
//

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*
 * stack : 들어갔던 원소가 그대로 나온다!
 * -> queue로만 이루어진 리스트 생각해줘도 된다
 */
int main() {
    // 시간초과
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, num;

    // 입력
    cin >> n;
    vector<int> A(n);
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    deque<int> q;
    for (int i=0; i<n; i++){
        cin >> num;
        if (A[i] == 0){
            q.push_front(num);
        }
    }
    cin >> m;
    while(m--){
        cin >> num;
        q.push_back(num);

        // 출력
        cout << q.front() << " ";
        q.pop_front();
    }
}