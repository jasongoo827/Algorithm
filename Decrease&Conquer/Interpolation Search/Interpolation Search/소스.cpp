#include <bits/stdc++.h>

#define MAX_LEN 500
using namespace std;

int ip(int arr[], int len, int target)
{
	int low = 0, high = len - 1;
	int pos;

	while (low <= high) {
		pos = low + (target - arr[low]) * (high - low) / (arr[high] - arr[low]);

		if (target == arr[pos]) return pos;
		else if (target > arr[pos]) low = pos + 1;
		else high = pos - 1;
	}

	return -1;
}

int main()
{
	int target;
	int arr[MAX_LEN];

	for (int i = 0; i < MAX_LEN; i++) arr[i] = i + 1;

	cin >> target;

	cout << ip(arr, MAX_LEN, target) << endl;

	return 0;
}