#include <bits/stdc++.h>
#include <random>

#define MAX_LEN 500

using namespace std;

int num[MAX_LEN];

int binarySearch(int arr[], int target)
{
	int low = 0;
	int high = MAX_LEN - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] > target) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return -1;
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < MAX_LEN; i++) {
		num[i] = rand() % 10000;
	}

	sort(num, num + MAX_LEN);
	for (int i = 0; i < MAX_LEN; i++) cout << num[i] << " ";
	cout << endl;

	int target = 0, index;

	while (1) {
		cout << "찾고자 하는 값을 입력하시오: ";
		cin >> target;
		if (target == 0) break;

		index = binarySearch(num, target);
		
		if (index != -1) {
			cout << "target값의 위치: " << index << endl;
		}
		else cout << "target값이 존재하지 않습니다." << endl;
	}

	return 0;
}