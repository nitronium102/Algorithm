// 플레5
// Created by KangMinji on 2023-08-10.
// https://www.acmicpc.net/problem/9202

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	TrieNode* children[26] = {}; // 26진 트리
	bool isEnd = false; // 단어의 끝인지
	bool isHit = false; // 이미 완성된 단어인지

	TrieNode() {
		isEnd = false;
		for (int i=0; i<26; i++) {
			children[i] = NULL;
		}
	}

	bool hasChild(char c) {
		return children[c-'A'] != NULL;
	}

	TrieNode* getChild(char c) {
		return children[c-'A'];
	}

	void clearHit() {
		isHit = false;
		for (TrieNode* child : children) {
			if (child != NULL) {
				child->clearHit();
			}
		}
	}
};

TrieNode root;
int w, b;
char board[4][4];
bool visited[4][4];
string answer;   // 현재 탐색 중인 단어
int sum;         // 현재 게임판에서 찾은 단어들의 점수 합
int wordCount;       // 현재 게임판에서 찾은 단어의 수
string longest;  // 현재 게임판에서 찾은 가장 긴 단어 (알파벳순으로 빠른 것)

int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0,-1, 1, -1, -1, 1, 1};
int score[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

void search(int x, int y, TrieNode* node) {
	// 1. 체크인
	visited[x][y] = true;
	answer += board[x][y];

	// 2. 목적지에 도달하였는가? : 트라이에 단어 끝, 새로운 단어
	if (node->isEnd && !node->isHit) {
		node->isHit = true;

		sum += score[answer.size()]; // 점수 합산
		wordCount++; // 단어 개수 증가
		if (answer.size() > longest.size() || (answer.size() == longest.size() && answer < longest)) {
			longest = answer; // 최장 단어 업데이트
		}
	}

	// 3. 연결된 곳을 순회(8)
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 4. 갈 수 있는가? : 맵 영역 체크, 방문하지 않은 곳, 트라이 노드 체크
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		if (!visited[nx][ny] && node->hasChild(board[nx][ny])) {
			// 5. 간다
			search(nx, ny, node->getChild(board[nx][ny]));
		}
	}

	// 6. 체크아웃
	visited[x][y] = false;
	answer.pop_back();
}


void insert(string word) {
	TrieNode* cur = &root;
	for (char ch : word) {
		int charIndex = ch - 'A';
		if (!cur->children[charIndex]){
			cur->children[charIndex] = new TrieNode();
		}
		cur = cur->children[charIndex]; // 밑으로 내려가기
	}
	cur->isEnd = true; // 단어의 제일 끝(종료)을 알림
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> w;
	string word;
	for (int i = 0; i < w; i++) {
		cin >> word;
		insert(word);
	}

	cin >> b;
	while (b--) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> board[i][j];
			}
		}

		longest = ""; // 최장 단어 초기화
		sum = 0; // 점수 합산 초기화
		wordCount = 0; // 단어 개수 초기화

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (root.hasChild(board[i][j])) { // 시작점에서 트라이에 존재하는 문자로 시작하는 경우에만 탐색 시작
					answer = "";
					search(i, j, root.getChild(board[i][j]));
				}
			}
		}

		cout << sum << " " << longest << " " << wordCount << '\n'; // 결과 출력
		root.clearHit(); // 단어 방문 상태 초기화
	}

	return 0;
}




