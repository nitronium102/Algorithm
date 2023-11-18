// 실버1
// Created by KangMinji on 2023-02-27.
// https://www.acmicpc.net/problem/1991

#include <iostream>
using namespace std;
pair<char, char> graph[26];

void postOrder(char root){
	if (root == '.'){
		return;
	}
	postOrder(graph[root-'A'].first);
	postOrder(graph[root-'A'].second);
	cout << root;
}

void inOrder(char root){
	if (root == '.'){
		return;
	}
	inOrder(graph[root-'A'].first);
	cout << root;
	inOrder(graph[root-'A'].second);
}

void preOrder(char root){
	if (root == '.'){
		return;
	}
	cout << root;
	preOrder(graph[root-'A'].first);
	preOrder(graph[root-'A'].second);
}

int main() {
	int n;
	char node, left, right;

	// 입력
	cin >> n;
	while(n--){
		cin >> node >> left >> right;
		graph[node-'A'].first = left;
		graph[node-'A'].second = right;
	}

	// 연산
	preOrder('A');
	cout << "\n";
	inOrder('A');
	cout << "\n";
	postOrder('A');
	cout << "\n";
}
