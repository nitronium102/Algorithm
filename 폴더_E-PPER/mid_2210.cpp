//
// Created by KangMinji on 2022-03-14.
//

/*
 * 숫자판 점프
 */

#include <iostream>
#include <set>
#define SIZE 5
using namespace std;

int board[5][5];
set<int> s; // 중복 허용 X

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// i : x좌표, j : y좌표
// num : 만들어진 숫자
// len : 만들어진 숫자의 자리수
void find_num(int x, int y, int num, int len){
    if (len == 6){
        s.insert(num);
        return;
    }
    for (int i=0; i<4; i++){ // 방향
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >=0 && nx < SIZE && ny >= 0 && ny < SIZE)
        find_num(nx, ny, num*10 + board[nx][ny], len+1);
    }

}

void solution(){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            find_num(i, j, board[i][j], 1);
        }
    }
}

int main() {
    int num, result;

    // 입력
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cin >> num;
            board[i][j] = num;
        }
    }

    // 연산
    solution();

    // 출력
    cout << s.size();

}