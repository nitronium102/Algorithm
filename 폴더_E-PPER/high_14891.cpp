//
// Created by KangMinji on 2022-03-18.
//

/*
 * 톱니바퀴
 * 1) 맞닿은 톱니의 극이 다르면 반대방향으로 회전
 * 2) 맞닿은 톱니의 극이 같으면 회전하지 않음
 * 톱니바퀴의 초기 상태와 회전시킨 방법이 주어졌을 때, 최종 톱니바퀴의 상태 구하기
 */

#include <iostream>
#include <deque>
#include <math.h>
using namespace std;

deque<char> wheel[4];

void move_wheel(int num, int dir){
    if (dir == -1) { // 반시계
        wheel[num].push_back(wheel[num][0]);
        wheel[num].pop_front();
    }
    else {
        wheel[num].push_front(wheel[num][7]);
        wheel[num].pop_back();
    }
}

// 1 : 시계방향 / -1 : 반시계 방향
// a[i][2] & a[i+1][6]
void play(int num, int dir){

    char prev_pole = wheel[num][6]; // 움직이기 전의 극
    int temp_dir = dir;

    // 움직일 톱니의 왼쪽 톱니 움직이기
   for (int i=num-1; i>=0; i--){
        temp_dir *= (-1);
        if (wheel[i][2] == prev_pole) // 극 같으면 패스
            break;
        prev_pole = wheel[i][6];
        move_wheel(i, temp_dir);
    }
   prev_pole = wheel[num][2];
   temp_dir = dir;

   // 움직일 톱니의 오른쪽 톱니 움직이기
   for (int i= num+1; i<4; i++){
       temp_dir *= (-1);
       if (wheel[i][6] == prev_pole) // 극 같으면 패스
           break;
       prev_pole = wheel[i][2];
       move_wheel(i, temp_dir);
   }
    move_wheel(num, dir); // 해당 톱니 움직이기
}

int main(){
    string str;
    int k, num, dir;
    int total = 0;

    // 입력(12시 방향부터 시계 방향)
    for (int i=0; i<4; i++){
        cin >> str;
        for (int j=0; j<str.size(); j++)
            wheel[i].push_back(str[j]);
    }
    cin >> k;
    for (int i=0; i<k; i++){
        cin >> num >> dir;
        play(num-1, dir);
    }

    // 12시 방향이 N극이면 0점, S극이면 2^(n번)
    for (int i=0; i<4; i++){
        if (wheel[i][0] == '1')
            total += pow(2, i);
    }

    // 출력
    cout << total;
}