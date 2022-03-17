//
// Created by KangMinji on 2022-03-16.
//

/*
 * 뱀 : 길이 1
 * 1) 머리를 다음 칸에 위치
 * 2) 해당 칸에 사과가 있다 -> 사과가 없어지고 꼬리 위치 그대로(몸 길이 +1)
 * 3) 해당 칸에 사과가 있다 -> 꼬리 위치한 칸 비움
 * 게임이 몇 초안에 끝나는지?
 */

#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;
typedef pair<int, int> ci;
ci dir[4] = { // 시계방향
        {0, 1}, // 우
        {1, 0}, // 하
        {0, -1}, // 좌
        {-1, 0}}; // 상

int solution(int n, vector<vector<int>> &board, map<int, char> &rotate_info){
    // 초기 설정
    deque<ci> snake;
    snake.push_front(ci(0, 0));
    board[0][0] = 1;

    int time = 0, head = 0;
    while(true){
        time++;
        // 1) 뱀의 머리 이동
        int nr = snake.front().first + dir[head].first;
        int nc = snake.front().second + dir[head].second;

        // 종료조건 확인 : 벽에 부딪히거나 자기 자신과 부딪힘
        if (nr < 0 || nr >= n || nc < 0 || nc >=n || board[nr][nc] == 1)
            break;

        // 2) 사과가 있는지 확인
        // 2-1) 없다면 꼬리 삭제
        if (board[nr][nc] != 2) { // == 0도 된다!
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        snake.push_front(ci(nr, nc));
        board[nr][nc] = 1;

        // 3) 방향 바뀌는지 확인
        if (rotate_info[time] == 'D')
            head = (head + 1)%4;
        if (rotate_info[time] == 'L')
            head = (head + 3)%4;
    }
    return time;
}

/*
 * 문제와는 달리 (0, 0)부터 시작
 * 뱀은 1, 사과는 2로 표시
 */
int main() {
    // n : 보드의 크기, k : 사과의 개수, l : 방향 변환 횟수수
   int n, k, l, row, col, time;
   char c;

    // 입력
    cin >> n >> k;
    vector<vector<int>> board(n, vector<int>(n));

    for (int i=0; i<k; i++){
        cin >> row >> col;
        board[row-1][col-1] = 2;
    }
    cin >> l;

    map<int, char> rotate_info;
    for (int i=0; i<l; i++){
        cin >> time >> c;
        rotate_info[time] = c;
    }

    // 연산 & 출력
    cout << solution(n, board, rotate_info);
}