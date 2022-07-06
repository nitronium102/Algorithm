//
// Created by KangMinji on 2022-03-13.
//

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    int area; // 영역의 넓이
    int color; // 영역의 색깔
    int x, y;

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (picture[i][j] == 0) // 방문했다면 넘기기
                continue;

            // 영역 초기화
            area = 0;
            color = picture[i][j];

            // 방문 표시
            q.push(make_pair(i, j));
            number_of_area++;
            picture[i][j] = 0;

            // bfs
            while(!q.empty()){
                area++;
                x = q.front().first;
                y = q.front().second;
                q.pop();
                for (int k=0; k<4; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >=0 && nx < m && ny >=0 && ny < n && picture[nx][ny] == color){
                        q.push(make_pair(nx, ny));
                        picture[nx][ny] = 0;
                    }
                }
            }
            max_size_of_one_area = max(max_size_of_one_area, area);
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}