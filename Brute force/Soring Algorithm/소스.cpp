#include <bits/stdc++.h>

#define MAX_LEN 500
#define MAX_MIXING_COUNT 1000

using namespace std;

int sortedArr[MAX_LEN];
int unsortedArr[MAX_LEN];

clock_t start_time, end_time;

void merge(int arr[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (arr[i] > arr[j]) {
			sortedArr[k] = arr[i];
			i++;
		}
		else {
			sortedArr[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sortedArr[k] = arr[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sortedArr[k] = arr[t];
			k++;
		}
	}
	for (int t = m; t <= n; t++) {
		arr[t] = sortedArr[t];
	}
}

void mergeSort(int arr[], int m, int n)
{
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(arr, m, middle);
		mergeSort(arr, middle + 1, n);
		merge(arr, m, middle, n);
	}
}

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

void quick_sort(int arr[], int start, int end)
{
	if (start >= end) {
		return;
	}

	int pivot = start;
	int i = pivot + 1;
	int j = end;

	while (i <= j) {
		while (i <= end && arr[i] <= arr[pivot]) {
			i++;
		}
		while (j > start && arr[j] >= arr[pivot]) {
			j--;
		}
		if (i > j) {
			swap(arr[j], arr[pivot]);
		}
		else {
			swap(arr[i], arr[j]);
		}
	}

	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

void cal_Time()
{
	printf("걸린 시간: %lf\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
	return;
}

int main()
{
	int x, y;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX_LEN; i++) {
		unsortedArr[i] = i;
	}

	//배열을 무작위로 섞음
	for (int i = 0; i < MAX_MIXING_COUNT; i++) {
		x = rand() % MAX_LEN;
		y = rand() % MAX_LEN;
		if (x != y) {
			swap(unsortedArr[x], unsortedArr[y]);
		}
	}

	printf("BubbleSort\n");
	start_time = clock();
	bubbleSort(unsortedArr, MAX_LEN);
	end_time = clock();
	cal_Time();

	printf("QuickSort\n");
	start_time = clock();
	quick_sort(unsortedArr, 0, MAX_LEN - 1);
	end_time = clock();
	cal_Time();

	printf("MergeSort\n");
	start_time = clock();
	mergeSort(unsortedArr, 0, MAX_LEN - 1);
	end_time = clock();
	cal_Time();

}