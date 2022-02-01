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

	cout << "그래프의 정점과 간선의 개수를 입력하시오: " << endl;
	cout << "정점: ";
	cin >> vertex_num;
	cout << "간선: ";
	cin >> edge_num;

	for (int i = 0; i < edge_num; i++) {
		cout << "연결된 두 정점을 입력하시오: ";
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << "시작 정점의 번호를 입력하시오: ";
	cin >> here;
	cout << "찾고 싶은 정점의 번호: ";
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