// 네트워크
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 201
bool isVisited[MAX] = {0, };
using namespace std;

void dfs(int start, int n, vector<vector<int>> computers) { 
    isVisited[start] = 1; // 방문 표시
    for(int i=0; i<n; i++) { 
    	// 현재 컴퓨터와 연결된 컴퓨터 중 아직 방문하지 않은 컴퓨터가 있는 경우
        // dfs 돌면서 네트워크를 끊어준다. 
        if(isVisited[i] == 0 && computers[start][i] == 1) { 
            dfs(i, n, computers); 
        }
    } 
}

void bfs(int start, int n, vector<vector<int>> computers){
    queue<int> q;
    
    q.push(start);
    isVisited[start] = 1; // 방문 표시
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for (int i=0; i<n; i++){
           if (isVisited[i] == 0 && computers[front][i] == 1){
               isVisited[i] = true;
               q.push(i);
           }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer=0;
    for (int i=0; i<n; i++){
        if (isVisited[i] == false){
            bfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}