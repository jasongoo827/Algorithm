#include <bits/stdc++.h>

#define N 5
#define MAXN 26
using namespace std;

int INF = std::numeric_limits<int>::max();
int graph[MAXN][MAXN], d[MAXN] = { 0, };

void bellman_ford(int start)
{
	d[start] = 0;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				if (d[i] == INF) continue;
				if (d[j]!=-1 && d[j] > d[i] + graph[i][j]) d[j] = d[i] + graph[i][j];
			}
		}
	}
	return;
}

int main()
{
	int v_num, e_num, w;
	char v1, v2, start;

	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) graph[i][j] = INF;
		d[i] = -1;
	}
	//5 10
	cout << "정점과 간선의 개수를 입력: "; cin >> v_num >> e_num;

	for (int i = 0; i < e_num; i++) {
		cin >> v1 >> v2 >> w;
		graph[v1 - 'a'][v2 - 'a'] = w;
		d[v1 - 'a'] = INF, d[v2 - 'a'] = INF;
	}

	cin >> start;
	bellman_ford(start - 'a');
	for (int i = 0; i < MAXN; i++) {
		if(d[i]!=-1) cout << d[i] << endl;
	}
	return 0;
}