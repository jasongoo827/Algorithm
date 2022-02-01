#include <bits/stdc++.h>

#define MAX_LEN 500

using namespace std;

int sp(vector<int>& v, int k)
{
	int s = 0, e = v.size() - 1;

	while (true) {
		int piv = s, i = piv + 1, j = e;

		while (i <= j) {
			while (i < e && v[i] <= v[piv]) i++;
			while (j > s && v[j] >= v[piv]) j--;

			if (i >= j) {
				swap(v[piv], v[j]);
				piv = j;
			}
			else {
				swap(v[i], v[j]);
			}
		}
		if (k > piv) s = piv + 1;
		else if (k < piv) e = piv - 1;
		else return v[piv];
	}
}

int main()
{
	vector<int> num;

	srand(time(NULL));

	for (int i = 0; i < MAX_LEN; i++) {
		num.push_back(rand() % 5000);
	}
	for (int i = 0; i < MAX_LEN; i++) {
		cout << num[i] << " ";
	}
	cout << endl;

	int k;
	cin >> k;
	int ret = sp(num, k);

	cout << ret << endl;

	return 0;
}