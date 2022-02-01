#include <bits/stdc++.h>

using namespace std;

#define MAX_LEN 50
int sortedArr[MAX_LEN];
int sortLevel = 0;


void merge(int arr[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (arr[i] < arr[j]) {
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

	cout << "정렬 단계: " << ++sortLevel << endl;
	for (int i = m; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return;
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
	for (int i = 0; i < MAX_LEN-1; i++) cout << unSorted[i] << ", ";
	cout << unSorted[MAX_LEN - 1] << "]" << endl;

	start_t = clock();
	mergeSort(unSorted, 0, MAX_LEN - 1);
	end_t = clock();

	printf("프로그램 실행 시간 %lf", (double)(end_t - start_t) / CLOCKS_PER_SEC);

	return 0;
}