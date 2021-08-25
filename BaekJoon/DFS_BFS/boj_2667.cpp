// 단지 번호 붙이기
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 26
bool isVisited[MAX][MAX]; // 방문 여부
int map[MAX][MAX];
vector<int> house;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int N;
int house_cnt = 0;

void dfs(int x, int y){
  house_cnt++;
  isVisited[x][y] = true;
  
  for (int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx <= N && ny >= 0 && ny <= N){
      if (isVisited[nx][ny] == false && map[nx][ny] == 1)
        dfs(nx, ny);
    }
  }
}

int main(){
  cin >> N;
  for (int i=0; i<N; i++){
    string temp;
    cin >> temp;
    for (int j=0; j<N; j++){
      map[i][j] = temp[j]-'0';
    }
  }

  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      if (map[i][j] == 1 && isVisited[i][j] == false){
        house_cnt = 0;
        dfs(i, j);
        house.push_back(house_cnt);
      }
    }
  }

  sort(house.begin(), house.end());
  cout << house.size() << "\n";

  for (int i=0; i<house.size(); i++){
    cout << house[i] << "\n";
  }

}