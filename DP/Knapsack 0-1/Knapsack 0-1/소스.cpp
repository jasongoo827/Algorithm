#include <bits/stdc++.h>

#define W 55
#define N 5

using namespace std;

//weight, value
vector<pair<int, int>> item_list;
int bag[N + 1][W + 1];
int max_value = 0;

void knapsack()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= W; j++) {
			if (item_list[i - 1].first <= j) {
				bag[i][j] = max(bag[i][j], item_list[i - 1].second + bag[i - 1][j - item_list[i - 1].first]);
				max_value = bag[i][j];
			}
			else bag[i][j] = bag[i - 1][j];
		}
	}
	return;
}

int main()
{
	item_list.push_back(make_pair(20, 25));
	item_list.push_back(make_pair(15, 30));
	item_list.push_back(make_pair(30, 45));
	item_list.push_back(make_pair(20, 30));
	item_list.push_back(make_pair(15, 35));

	memset(bag[0], 0, sizeof(int));
	for (int i = 0; i < N; i++) {
		bag[i][0] = 0;
	}

	knapsack();

	cout << "[";
	for (int i = 0; i <= N; i++) {
		cout << "[";
		for (int j = 0; j < W; j++) {
			cout << bag[i][j] << ", ";
		}
		cout << bag[i][W] << "]" << endl;
	}
	cout << "]" << endl;
	cout << "가장 최대의 가치: " << max_value << endl;

	return 0;
}