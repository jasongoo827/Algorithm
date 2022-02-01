#include <bits/stdc++.h>

using namespace std;

#define MAX_LEN 1000

void selection_sort(int arr[], int n)
{
	int min;

	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		swap(arr[i], arr[min]);
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
	selection_sort(arr, MAX_LEN);
	clock_t end = clock();
	printf("선택정렬에 걸린 시간: %lf 입니다.\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}