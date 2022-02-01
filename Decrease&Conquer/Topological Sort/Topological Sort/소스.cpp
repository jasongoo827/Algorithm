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

	cout << "������ ������ ������ ������ �Է��Ͻÿ�: " << endl;
	cout << "������ ����: ";
	cin >> vertex_num;
	cout << "������ ����: ";
	cin >> edge_num;

	char from, to;
	cout << "�������� ��� ����, ���� ������ �Է��Ͻÿ�" << endl;
	for (int i = 0; i < edge_num; i++) {
		cout << i + 1 << "��° vertex: ";
		cout << "���, ���� ";
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