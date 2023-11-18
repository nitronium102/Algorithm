//
// Created by KangMinji on 2022-03-14.
//

/*  2580 스도쿠
    1.각각의 가로줄과 세로줄에는 1 부터 9 까지의 숫자가 한 번씩만 나타나야 한다
    2.굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1 부터 9 까지의 숫자가 한 번씩만 나타나야 한다
    최종적으로 모든 빈 칸이 채워진 스도쿠 판을 2 차원 배열 벡터로 작성해 리턴한다
*/

#include <iostream>
#include <vector>
using namespace std;

// 세 가지 조건 만족 필요
// 1. 가로줄에서 숫자 중복 X
// 2. 세로줄에서 숫자 중복 X
// 3. 3X3에서 숫자 중복 X

bool rows[9][10] = {0, };
bool cols[9][10] = {0, };
bool checkArea[9][10] = {0, };
vector<pair<int, int>> blank_cord;

//좌표를 영역으로 바꿔주는 함수
int find_area(int x, int y){
    return 3*(x/3)+(y/3);
}

bool backtracking(int full_num, int black_num, vector<vector<int>> *answer) {
    if(full_num==black_num) return true; //마지막까지 다 채웠으면 리턴
    int x = blank_cord[full_num].first;
    int y = blank_cord[full_num].second;
    int a = find_area(x, y);

    for(int num=1; num<10; num++) {
        if(!rows[x][num] && !cols[y][num] && !checkArea[a][num]) {
            // 시도
            rows[x][num] = 1;
            cols[y][num] = 1;
            checkArea[a][num] = 1;

            // 저장
            (*answer)[x][y] = num;

            // 실행
            if(backtracking(full_num+1, black_num, answer))
                return true;

            // 복구
            rows[x][num] = 0;
            cols[y][num] = 0;
            checkArea[a][num] = 0;
        }
    }
    return false;
}

vector<vector<int>> solution(vector<vector<int>> sudoku) {
    vector<vector<int>> answer(9, vector<int>(9,0));
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(sudoku[i][j] == 0) {
                blank_cord.push_back({i, j});
                continue;
            }
            rows[i][sudoku[i][j]] = 1;
            cols[j][sudoku[i][j]] = 1;
            checkArea[find_area(i, j)][sudoku[i][j]] = 1;
            answer[i][j] = sudoku[i][j];
        }
    }
    int black_num = blank_cord.size();
    backtracking(0, black_num, &answer);
    return answer;
}

int main() {
    vector<vector<int>> sudoku(9, vector<int>(9));
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) cin >> sudoku[i][j];
    }
    auto output = solution(sudoku);
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) cout << output[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}