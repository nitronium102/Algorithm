// 바이러스
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 101
vector<int> graph[MAX]; // 인접 노드 그래프
bool isVisited[MAX] = {false, }; // 방문 여부
queue<int> q;

int cnt = 0;

void BFS(int v){
  q.push(v);
  isVisited[v] = true;

  while(!q.empty()){
    int cur = q.front();
    q.pop();

    for (int i=0; i<graph[cur].size(); i++){
      int next = graph[cur][i];
      if (!isVisited[next]){
        q.push(next);
        isVisited[next] = true;
        cnt++;
      }
    }
  }
}

int main(){
  int N, M;
  cin >> N >> M;
  for (int i=0; i<M; i++){
    int u, v;
    cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i=0; i<MAX; i++){
    sort(graph[i].begin(), graph[i].end());
  } 

  BFS(1);
  cout << cnt;
}