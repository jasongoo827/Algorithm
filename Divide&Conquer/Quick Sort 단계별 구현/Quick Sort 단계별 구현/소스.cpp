#include <bits/stdc++.h>

using namespace std;

#define MAX_LEN 100
int sortLevel = 0;


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

	cout << "정렬 단계: " << ++sortLevel << endl;
	for (int i = start; i <= end; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);

	return;
}


int main()
{
	int unSorted[MAX_LEN];
	clock_t start_t, end_t;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX_LEN; i++) {
		unSorted[i] = rand() % MAX_LEN;
	}

	cout << "정렬 이전의 배열" << endl;
	cout << "[";
	for (int i = 0; i < MAX_LEN - 1; i++) cout << unSorted[i] << ", ";
	cout << unSorted[MAX_LEN - 1] << "]" << endl;

	start_t = clock();
	quick_sort(unSorted, 0, MAX_LEN - 1);
	end_t = clock();

	cout << "정렬 이후의 배열" << endl;
	cout << "[";
	for (int i = 0; i < MAX_LEN - 1; i++) cout << unSorted[i] << ", ";
	cout << unSorted[MAX_LEN - 1] << "]" << endl;

	printf("프로그램 실행 시간 %lf", (double)(end_t - start_t) / CLOCKS_PER_SEC);

	return 0;
}