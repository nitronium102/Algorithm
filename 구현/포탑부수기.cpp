#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int MAX = 11;

int n, m, k;
int dx[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[4] = {1, 0, -1, 0};
int dx2[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy2[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int turn[MAX][MAX]; // 공격한 턴 저장
int board[MAX][MAX]; // 포탑들의 공격력 저장
bool isAttacked[MAX][MAX]; // 공격 당한 포탑
bool visited[MAX][MAX];
ci parent[MAX][MAX];

bool cmp(const ci &a, const ci &b){
	int ax = a.first;
	int ay = a.second;
	int bx = b.first;
	int by = b.second;

	// 공격력이 약한 순으로
	if (board[ax][ay] != board[bx][by]){
		return board[ax][ay] < board[bx][by];
	}
	// 가장 최근에 공격한 순
	if (turn[ax][ay] != turn[bx][by]){
		return turn[ax][ay] > turn[bx][by];
	}
	// 행과 열의 합이 가장 큰 포탑
	if (ax + ay != bx + by){
		return ax + ay > bx + by;
	}
	// 열 값이 가장 큰 포탑
	return ay > by;
}

void prepareNextAttack() {
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (board[i][j] == 0 || isAttacked[i][j]) continue;
			board[i][j] += 1;
		}
	}
}

void fireAttack(ci attacker, ci target){
	int attackpoint = board[attacker.first][attacker.second];

	int x = target.first;
	int y = target.second;

	board[x][y] -= attackpoint;
	isAttacked[x][y] = true;
	if (board[x][y] < 0) board[x][y] = 0;

	attackpoint /= 2;
	for (int i=0; i<8; i++){
		int nx = (x + dx2[i] + n) % n;
		int ny = (y + dy2[i] + m) % m;

		if (nx == attacker.first && ny == attacker.second) continue;
		if (board[nx][ny] == 0) continue;

		board[nx][ny] -= attackpoint;
		isAttacked[nx][ny] = true;
		if (board[nx][ny] < 0) board[nx][ny] = 0;
	}
}

bool lazerAttack(ci attacker, ci target) {
	// 1) bfs 수행하면서 최단경로 찾기
	queue<ci> q;

	q.push(attacker);
	visited[attacker.first][attacker.second] = true;
	bool flag = false;

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 타겟 발견하면 공격 수행
		if (x == target.first && y == target.second){
			flag = true;
			break;
		}

		for (int i=0; i<4; i++){
			int nx = (x + dx[i] + n) % n;
			int ny = (y + dy[i] + m) % m;

			if (board[nx][ny] == 0) continue;
			if (visited[nx][ny]) continue;
			parent[nx][ny] = {x, y};
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}

	if (flag) {
		// 타겟에세는 공격력 전체로 공격
		int attackpoint = board[attacker.first][attacker.second];
		int x = target.first;
		int y = target.second;

		isAttacked[x][y] = true;
		board[x][y] -= attackpoint;
		if (board[x][y] < 0) board[x][y] = 0;

		ci prev = parent[x][y];
		x = prev.first;
		y = prev.second;

		// 경로에 있는 포탑의 경우는 공격력/2로 받음
		attackpoint /= 2;
		while(!(x == attacker.first && y == attacker.second )){
			board[x][y] -= attackpoint;
			if (board[x][y] < 0) board[x][y] = 0;
			isAttacked[x][y] = true;

			prev = parent[x][y];
			x = prev.first;
			y = prev.second;
		}
	}

	return flag;
}

void findAttackerAndTarget(vector<ci> &towers) {
	sort(towers.begin(), towers.end(), cmp);
}

int main() {
	// 입력
	cin >> n >> m >> k;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}

	// k번 동안 턴 반복
	ci attacker, target;
	int curr_turn = 1;
	vector<ci> towers;
	while(k--){
		// 0) 초기화
		towers.clear();
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				isAttacked[i][j] = false;
				visited[i][j] = false;
				parent[i][j] = {-1, -1};
				if (board[i][j]){ // 파괴되지 않은 포탑이라면
					towers.push_back({i, j});
				}
			}
		}

		if ((int)towers.size() <= 1){
			break;
		}

		// 1) 가장 약한 포탑과 가장 강한 포탑 선택
		findAttackerAndTarget(towers);
		attacker = towers[0];
		target = towers[towers.size() -1];
		//	 cout << "공격자와 대상 " << attacker.first << ' ' << attacker.second << ' ' << target.first << ' ' << target.second << "\n";

		isAttacked[attacker.first][attacker.second] = true; // 공격과 관련 있음
		board[attacker.first][attacker.second] += (n + m); // 가장 약한 포탑 공격력 증가
		turn[attacker.first][attacker.second] = curr_turn++;

		// 2) 레이저, 포탑 공격 수행
		bool flag = lazerAttack(attacker, target);
		if (!flag) {
			fireAttack(attacker, target);
		}
		// 3) 포탑 정비
		prepareNextAttack();// 공격과 무관했던 포탑
	}

	// 출력
	int answer = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			answer = max(answer, board[i][j]);
		}
	}
	cout << answer << "\n";

	return 0;
}