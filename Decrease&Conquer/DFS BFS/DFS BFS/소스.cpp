#include <bits/stdc++.h>

#define MAX_LEN 10

using namespace std;

// 11 10

vector<vector<int>> graph(MAX_LEN + 1);
vector<bool> visited(MAX_LEN + 1, false);
vector<bool> discovered(MAX_LEN + 1, false);
bool find_target = false;

void dfs(int here, int target);
void bfs(int here, int target);

int main()
{
	int a, b, here, target, vertex_num, edge_num;

	cout << "�׷����� ������ ������ ������ �Է��Ͻÿ�: " << endl;
	cout << "����: ";
	cin >> vertex_num;
	cout << "����: ";
	cin >> edge_num;

	for (int i = 0; i < edge_num; i++) {
		cout << "����� �� ������ �Է��Ͻÿ�: ";
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << "���� ������ ��ȣ�� �Է��Ͻÿ�: ";
	cin >> here;
	cout << "ã�� ���� ������ ��ȣ: ";
	cin >> target;
	cout << "DFS: ";
	dfs(here, target);
	cout << endl;
	cout << "BFS: ";
	bfs(here, target);

	return 0;
}

void dfs(int here, int target)
{
	if (here == target) {
		printf("%d", target);
		find_target = true;
		return;
	}
	visited[here] = true;
	printf("%d ", here);

	for (int i = 0; i < (int)graph[here].size(); i++) {
		int there = graph[here][i];
		if (!visited[there]) {
			dfs(there, target);
			if (find_target) return;
		}
	}
	return;
}

void bfs(int start, int target)
{
	queue<int> q;
	discovered[start] = true;
	vector<int> order;
	q.push(start);

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		order.push_back(here);

		if (here == target) break;

		for (int i = 0; i < (int)graph[here].size(); i++) {
			int there = graph[here][i];
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}

	for (int i = 0; i < order.size(); i++) {
		printf("%d ", order[i]);
	}
	return;
}