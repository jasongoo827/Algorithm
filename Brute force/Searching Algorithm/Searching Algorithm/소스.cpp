#include <bits/stdc++.h>

#define MAX_LEN 20000
#define MAX_MIXING_COUNT 400000

using namespace std;

//���� Ž��
int linearSearch(int arr[], int target)
{
	for (int i = 0; i < MAX_LEN; i++) {
		if (arr[i] == target) return i;
	}
	return -1;
}

//���� Ž��
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
	int sortedArr[MAX_LEN];
	int unsortedArr[MAX_LEN];
	int key, x, y, temp;
	int num1, num2, num3, num4;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX_LEN; i++) {
		sortedArr[i] = i;
		unsortedArr[i] = i;
	}

	//�迭�� �������� ����
	for (int i = 0; i < MAX_MIXING_COUNT; i++) {
		x = rand() % MAX_LEN;
		y = rand() % MAX_LEN;
		if (x != y) {
			temp = unsortedArr[x];
			unsortedArr[x] = unsortedArr[y];
			unsortedArr[y] = temp;
		}
	}

	key = rand() % MAX_LEN;
	cout << "ã�� ���� ��: " << key << endl;
	cout << endl;

	//���ĵ� �����͸� ����Ž������ ã�� ���
	cout << "���ĵ� �����͸� ����Ž������ ã�� ���" << endl;
	clock_t sorted_tic1 = clock();
	num1 = linearSearch(sortedArr, key);
	clock_t sorted_toc1 = clock();
	cout << "key ���� " << num1 << "��°�� �ֽ��ϴ�." << endl;
	printf("�ɸ� �ð�: %lf\n", (double)(sorted_toc1 - sorted_tic1) / CLOCKS_PER_SEC);

	//���ĵ� �����͸� ����Ž������ ã�� ���
	cout << "���ĵ� �����͸� ����Ž������ ã�� ���" << endl;
	clock_t sorted_tic2 = clock();
	num2 = binarySearch(sortedArr, key);
	clock_t sorted_toc2 = clock();
	cout << "key ���� " << num2 << "��°�� �ֽ��ϴ�." << endl;
	printf("�ɸ� �ð�: %lf\n", (double)(sorted_toc2 - sorted_tic2) / CLOCKS_PER_SEC);

	//���ĵ��� ���� �����͸� ����Ž������ ã�� ���
	cout << "���ĵ��� ���� �����͸� ����Ž������ ã�� ���" << endl;
	clock_t unsorted_tic1 = clock();
	num3 = linearSearch(unsortedArr, key);
	clock_t unsorted_toc1 = clock();
	cout << "key ���� " << num3 << "��°�� �ֽ��ϴ�." << endl;
	printf("�ɸ� �ð�: %lf\n", (double)(unsorted_toc1 - unsorted_tic1) / CLOCKS_PER_SEC);

	//���ĵ��� ���� �����͸� ����Ž������ ã�� ���
	cout << "���ĵ��� ���� �����͸� ����Ž������ ã�� ���" << endl;
	clock_t unsorted_tic2 = clock();
	sort(unsortedArr, unsortedArr + MAX_LEN);
	num4 = binarySearch(unsortedArr, key);
	clock_t unsorted_toc2 = clock();
	cout << "key ���� " << num4 << "��°�� �ֽ��ϴ�." << endl;
	printf("�ɸ� �ð�: %lf\n", (double)(unsorted_toc2 - unsorted_tic2) / CLOCKS_PER_SEC);

	return 0;
}