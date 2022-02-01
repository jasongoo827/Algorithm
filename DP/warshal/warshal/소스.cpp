#include <bits/stdc++.h>

#define LEN 7
using namespace std;

int graph[7][7] = {
	{0, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 1, 0},
	{0, 0, 1, 0, 0, 1, 1},
	{0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0},
};

void warshal()
{
	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			for (int k = 0; k < LEN; k++) {
				if (graph[k][i] == 1 && graph[i][j] == 1) graph[k][j] = 1;
			}
		}
	}

	return;
}

int main()
{
	warshal();

	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}