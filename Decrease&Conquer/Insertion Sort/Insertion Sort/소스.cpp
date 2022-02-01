#include <bits/stdc++.h>

using namespace std;

void print_arr(int data[], int len)
{
	for (int i = 0; i < len; i++) {
		printf("%d ", data[i]);
	}
	return;
}

void insertion_sort(int arr[], int n, int target)
{
	int i, j, key;

	for (i = 1; i < n; i++) {
		key = arr[i];

		if (key == target) {
			print_arr(arr, n);
		}

		for (j = i - 1; j >= 0 && key < arr[j]; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}

}

int main()
{
	int data[] = { 2, 3, 4, 5, 8, 9, 12, 13, 14, 15, 16, 17, 18, 20, 21, 23, 25, 27, 28, 29, 30,
		33, 35, 36, 37, 38, 42, 45, 46, 47, 48, 49, 50, 51, 52, 55, 56, 57, 58, 59, 60, 61, 65, 67,
		72, 73, 74, 75, 77, 78, 80, 81, 83, 84, 86, 87, 89, 91, 92, 93, 94, 97, 98, 100, 30, 99, 59,
		70, 34, 49, 94, 67, 41, 57, 65, 60, 60, 36, 15, 53, 14, 9, 26, 47, 1, 95, 53, 43, 22, 2, 16, 
		21, 41, 98, 76, 3, 26, 63, 76, 60, 67, 29, 4, 41, 20, 42, 64, 86, 10, 12, 43, 70, 39, 58, 57, 
		9, 9, 49, 98, 84, 36, 58, 26, 24, 82, 27, 34, 19, 84, 51, 94, 39, 22, 86, 81, 35, 6, 57, 1, 44,
		16, 89, 79, 10, 47, 88, 90, 14, 14, 57, 60, 87, 13, 26, 14, 58, 50, 96, 32, 68, 8, 84, 74, 82 };

	int len = sizeof(data) / sizeof(data[0]);
	int target = 68;

	printf("68을 삽입정렬하기 전 정렬 상태\n");
	insertion_sort(data, len, target);
	printf("\n\n");

	printf("68을 삽입정렬한 후 정렬 상태\n");
	print_arr(data, len);

	return 0;
}