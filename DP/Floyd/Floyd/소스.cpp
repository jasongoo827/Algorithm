#include <bits/stdc++.h>

#define LEN 9
using namespace std;

int INF = std::numeric_limits<int>::max();

int graph[9][9] = {
	{0, 8, 3, INF, INF, 13, INF, INF, INF},
	{INF, 0, 2, 1, INF, INF, INF, INF, INF},
	{INF, 3, 0, 9, 2, INF, INF, INF, INF},
	{INF, INF, INF, 0, 4, INF, 6, 2, INF},
	{5, INF, INF, 6, 0, 5, INF, INF, 4},
	{INF, INF, INF, INF, INF, 0, 1, INF, 7},
	{INF, INF, INF, INF, 3, INF, 0, 4, INF},
	{INF, INF, INF, INF, INF, INF, INF, 0, 1},
	{INF, INF, INF, INF, INF, INF, 5, INF, 0},
};

void floyd()
{
	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			for (int k = 0; k < LEN; k++) {
				if (graph[k][i] != INF && graph[i][j] != INF) {
					graph[k][j] = min(graph[k][j], graph[k][i] + graph[i][j]);
				}
			}
		}
	}

	return;
}

int main()
{
	floyd();

	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}