#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int V_MAX = 1111111;
const int P_MAX = 21; // 2^20 > 10^6, 즉 노드가 10^6개 주어지면, parent[a][k]에서 k는 최대 20으로 최악의 경우라도 부모 찾을 수 있음

int n;
vector<int> adj[V_MAX];
int parent[V_MAX][P_MAX]; // parent[a][k] : a의 2^k번째 부모
int depth[111111]; // depth[a] : a노드의 깊이(root = 0)

void makeTreeDFS(int cur) {
	// 주어진 정보를 바탕으로 트리 그림
	// 각 노드의 depth와 0번째 부모 만들어 놓음
	for (int next: adj[cur]) {
		if (depth[next] == -1) { // 방문되지 않은 경우(부모가 아닌 경우)
			parent[next][0] = cur;
			depth[next] = depth[cur] + 1; // depth는 root의 depth + 1;
			makeTreeDFS(next);
		}
	}
}

void findLCA(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);

	int diff = depth[u] - depth[v]; // u가 더 깊이 있도록

	// u와 v를 같은 높이로 맞춰주기 (이진법)
	int idx = 0;
	while (diff) {
		if (diff % 2) {
			u = parent[u][idx];
		}
		idx++;
		diff /= 2; // diff/2
	}

	if (u != v) {
		// 2^17, 2^16, ...., 2, 1번째 부모를 비교

		// 제일 먼 조상에서부터 본다
		for (int i = P_MAX - 1; i >= 0; i--) {
			// i번째 조상이 다른 게 나오면 u, v를 각각의 2^i번째 조상으로 위치 변경
			if (parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		// 최종 u, v는 같은 부모 아래 있음
		// LCA는 u또는 v의 0번째 조상임
		u = parent[u][0];
	}
	cout << u << '\n';
}

int main() {
	// 시간초과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> n;

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// parent, depth 초기화
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));

	depth[1] = 0;
	makeTreeDFS(1); // root 노드는 1이라 가정

	// i의 2^j번째 부모 k가 있으면 i의 2^j번째 부모는 k의 2^j번째 부모
	for (int j = 0; j < P_MAX - 1; j++) {
		for (int i = 1; i <= n; i++) {
			int k = parent[i][j];
			if (k != -1) { // k가 -1인 경우는 루트 범위를 넘어간 것!
				parent[i][j + 1] = parent[k][j];
			}
		}
	}

	// u, v의 LCA 구하기
	int m, u, v;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		findLCA(u, v);
	}

	return 0;
}
