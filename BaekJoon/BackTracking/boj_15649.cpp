// 백트래킹 N과 M(1)
#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX]; // 선택에 쓰일 배열
bool visited[MAX] = {false, }; // 정점 방문 여부 그래프

void dfs(int cnt){ // 현재 cnt만큼 수를 택함
  if (cnt == m){ // 만약 m개를 모두 택했다면(끝)
    for(int i=0; i<m; i++){
      cout << arr[i] << " "; // arr에 있는 수를 출력
    }
    cout << "\n";
    return;
  }
  for (int i=1; i<=n; i++){ // 1~n까지의 수에 대해(루트 노드 제외)
    if (!visited[i]){ // 만약 i를 방문하지 않았다면
      visited[i] = true; // 방문하고
      arr[cnt] = i; // cnt번째 수를 i로 정함
      dfs(cnt+1); // 다음 수를 찾으러 한 단계 더 들어감
      visited[i] = false; // cnt번째 수를 i로 정한 모든 경우의 수에 대해 탐색 완료 -> i를 사용되지 않았다고 표시함
    }
  }

}

int main(){
  cin >> n >> m;
  dfs(0);
}