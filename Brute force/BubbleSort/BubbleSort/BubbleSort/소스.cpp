#include <bits/stdc++.h>

using namespace std;

#define MAX_LEN 1000

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}


int main()
{
	int arr[MAX_LEN];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX_LEN; i++) {
		arr[i] = rand() % 1000 + 1;
	}

	clock_t start = clock();
	bubbleSort(arr, MAX_LEN);
	clock_t end = clock();
	printf("버블정렬에 걸린 시간: %lf 입니다.\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}