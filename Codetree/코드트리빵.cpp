// 골드2
// Created by KangMinji on 2023-10-10.
// https://www.codetree.ai/training-field/frequent-problems/problems/codetree-mon-bread/description?page=1&pageSize=20

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> ci;
const int BASE_CAMP = 1;
const int BLOCK = 5;
const ci OUTSIDE = {-1, -1};

int n, m;
int board[16][16];
vector<ci> conv_list;
vector<ci> basecamp;
ci people[31];
int cur_time = 0;

// 행이 작은 것 먼저
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

// bfs용
int dist[16][16]; // 최단거리 결과
bool visited[16][16];

void bfs(ci start){
	// 초기화
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			visited[i][j] = false;
			dist[i][j] = 0;
		}
	}

	// 초기값 설정
	queue<ci> q;
	q.push(start);
	visited[start.first][start.second] = true;
	dist[start.first][start.second] = 0;

	// 연산
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int d = dist[x][y];
		q.pop();

		for (int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >=n || ny >= n) continue;
			if (board[nx][ny] == BLOCK || visited[nx][ny]) continue;

			visited[nx][ny] = true;
			dist[nx][ny] = d + 1;
			q.push({nx, ny});
		}
	}
}

void simulate() {
	/* 1단계 : 격자에 있는 사람들 모두가 본인이 가고 싶은 편의점 방향을 향해 움직임*/
	for (int i=0; i<m; i++){
		// 1) 격자에 있는지 확인
		if (people[i] == OUTSIDE || people[i] == conv_list[i]){
			continue;
		}

		// 2) 가고 싶은 편의점 방향 찾기
		// 2-1) 해당 편의점까지 가는 거리 찾기
		bfs(conv_list[i]);

		// 2-2) 최소 거리인 방향 찾기
		int x = people[i].first;
		int y = people[i].second;
		ci next;
		int min_dist = 1e9;

		for (int j=0; j<4; j++){
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (nx < 0 || ny < 0 || nx >=n || ny >= n) continue;
			if (!visited[nx][ny]) continue; // 방문이 불가능한 경우
			if (min_dist > dist[nx][ny]){
				min_dist = dist[nx][ny];
				next = {nx, ny};
			}
		}

		// 3) 해당 방향으로 이동하기
		people[i] = next;
	}

	for (int i=0; i<m; i++){
		/* 2단계 : 편의점에 도착한 경우 처리 */
		if (people[i] == conv_list[i]){
			board[people[i].first][people[i].second] = BLOCK;
			continue;
		}
	}

	if (cur_time > m) return;

	/* 3단계 : 베이스캠프 선택하기 */
	// 3-0) 해당 편의점으로 경로 선택
	int curr = cur_time - 1;
	bfs(conv_list[curr]);

	// 3-1) 베이스캠프 찾기
	int min_dist = 1e9;
	ci next;
	for (ci base : basecamp){
		int nx = base.first;
		int ny = base.second;
		if (visited[nx][ny] && board[nx][ny] == BASE_CAMP && min_dist > dist[nx][ny]){
			min_dist = dist[nx][ny];
			next = base;
		}
	}

	// 3-2) 베이스캠프로 이동
	people[curr] = next;
	board[next.first][next.second] = BLOCK;
}

/* 모든 사람이 편의점에 도착했는지 확인하는 함수*/
bool checkEnd() {
	for (int i=0; i<m; i++){
		if (people[i] != conv_list[i]){
			return false;
		}
	}
	return true;
}

int main() {

	// 입력
	cin >> n >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> board[i][j];
			if (board[i][j] == BASE_CAMP){
				basecamp.push_back({i, j});
			}
		}
	}

	int x, y;
	conv_list.assign(m, {});
	for (int i=0; i<m; i++){
		cin >> x >> y;
		conv_list[i] = {x-1, y-1};
	}

	for (int i=0; i<m; i++){
		people[i] = OUTSIDE;
	}

	// 연산
	while(true) {
		cur_time++;
		simulate();

		if (checkEnd()){
			break;
		}
	}

	// 출력
	cout << cur_time;

	return 0;
}