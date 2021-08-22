// 1260번 DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 10001

int N, M, V; // 정점 개수, 간선 개수, 시작 정점
vector<int> graph[MAX]; // 인접 행렬 그래프
bool isVisited[MAX] = {false, }; // 정점 방문 여부
queue<int> q;

// DFS : 방문한 노드에서 아직 방문하지 않은 인접한 노드로 옮겨가는 식
void DFS(int v){
  isVisited[v] = true; // 방문 표시
  cout << v << " ";

  for (int i=0; i<graph[v].size(); i++){
    int next = graph[v][i];
    // 방문하지 않은 경우
    if (isVisited[next] == false)
      DFS(next); // 재귀함수 호출
  }
}

// BFS : 방문한 노드로부터 아직 방문하지 않은 인접한 모든 노드를 큐에 추가하는 방식
void BFS(int v){
  q.push(v); // 루트 노드 삽입
  isVisited[v] = true;

  while(!q.empty()){
    int cur = q.front();
    q.pop();

    isVisited[cur] = true;
    cout << cur << " ";

    for (int i=0; i<graph[cur].size(); i++){
      int next = graph[cur][i];
      // 방문하지 않은 경우
      if (isVisited[next] == false){
        // 큐에 넣어주고 방문했음을 표시
        q.push(next);
        isVisited[next] = true;
      }
    }
  }
}

int main(){
  queue<int> q; // BFS용
  cin >> N >> M >> V;

  for (int i=0; i<M; i++){
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // sort : 하나의 정점에서 다음을 탐색할 떄 node에 순차적으로 접근해야 함
  for (int i=0; i<MAX; i++){
    sort(graph[i].begin(), graph[i].end());
  }

  DFS(V);
  cout << "\n";

  fill_n(isVisited, MAX, false); // 방문 여부 초기화
  BFS(V);
}
