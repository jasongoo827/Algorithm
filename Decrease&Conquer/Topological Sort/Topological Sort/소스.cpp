#include <bits/stdc++.h>

#define MAX_LEN 7

using namespace std;

int vertex_num, edge_num;
int indegree[MAX_LEN] = { 0, };
vector<vector<int>> graph(MAX_LEN);
vector<int> ret;

void topological_sort()
{
	queue<int> order;

	for (int i = 0; i < MAX_LEN; i++) {
		if (indegree[i] == 0) order.push(i);
	}

	while (!order.empty()) {
		int here = order.front();
		for (int i = 0; i < (int)graph[here].size(); i++) {
			int there = graph[here][i];
			indegree[there]--;
			if (indegree[there] == 0) order.push(there);
		}
		ret.push_back(here);
		order.pop();
	}
	return;
}


int main()
{

	cout << "정점의 개수와 간선의 개수를 입력하시오: " << endl;
	cout << "정점의 개수: ";
	cin >> vertex_num;
	cout << "간선의 개수: ";
	cin >> edge_num;

	char from, to;
	cout << "간선에서 출발 정점, 도착 정점을 입력하시오" << endl;
	for (int i = 0; i < edge_num; i++) {
		cout << i + 1 << "번째 vertex: ";
		cout << "출발, 도착 ";
		cin >> from >> to;
		graph[from - 'a'].push_back(to - 'a');
		indegree[to - 'a']++;
	}

	topological_sort();

	for (int i = 0; i < (int)ret.size(); i++) {
		cout << (char)(ret[i]+'a') << " ";
	}

	return 0;
}