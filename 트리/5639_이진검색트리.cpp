// 골드5
// Created by KangMinji on 2023-04-06.
// https://www.acmicpc.net/problem/5639

#include <iostream>
#include <vector>
using namespace std;

void postOrder(int left, int right, vector<int> &tree){
	if (left > right){
		return;
	}
	// V
	int root = tree[left];

	// L과 R 사이 결정
	int tmp = left + 1;
	for (int i=left+1; i<right + 1; i++){
		if (tree[i] > root){
			tmp = i;
			break;
		}
	}

	// 출력
	postOrder(left + 1, tmp-1, tree);
	postOrder(tmp, right, tree);
	cout << root << '\n';
}

int main() {
	// 입력
	int node;
	vector<int> tree;
	while(cin >> node){
		tree.push_back(node);
	}

	// 연산
	postOrder(0, tree.size()-1, tree);
}