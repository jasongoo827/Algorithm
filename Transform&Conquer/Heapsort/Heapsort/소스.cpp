#include <bits/stdc++.h>

using namespace std;

int arr[26] = { 0, 31, 30, 23, 2, 33, 61, 87, 58, 53, 32, 68, 29, 38, 34, 66, 42, 8, 21, 125, 341, 221, 648, 62, 1, 921 };

void make_maxheap(int root, int n) {
	int temp = arr[root]; // �ش� �θ� ���
	int child = root * 2; // ���� �ڽ� ���
	while (child <= n) {
		// �� ū �ڽ� ��� ã��
		if (child < n && arr[child] < arr[child + 1])
			child++;
		if (temp < arr[child]) { // �ڽ� ��尡 �� Ŭ ���
			arr[child / 2] = arr[child];
			child *= 2; // ���� ���߱�
		}
		else break;
	}
	arr[child / 2] = temp;

}

void make_minheap(int root, int n) {
	int temp = arr[root]; // �ش� �θ� ���
	int child = root * 2; // ���� �ڽ� ���
	while (child <= n) {
		// �� ���� �ڽ� ��� ã��
		if (child < n && arr[child] > arr[child + 1])
			child++;
		if (temp > arr[child]) { // �ڽ� ��尡 �� ���� ���
			arr[child / 2] = arr[child];
			child *= 2; // ���� ���߱�
		}
		else break;
	}
	arr[child / 2] = temp;

}

void heapsort(int n, int type) {
	// �ִ� �� ����
	if (type == 0) {
		for (int i = n / 2; i > 0; i--) {
			make_minheap(i, n);
		}
	}
	else if (type == 1) {
		for (int i = n / 2; i > 0; i--) {
			make_maxheap(i, n);
		}
	}

	int temp;
	if (type == 0) {
		for (int i = n; i > 0; i--) {
			swap(arr[1], arr[i]);
			make_minheap(1, i - 1);
		}
	}
	else if (type == 1) {
		for (int i = n; i > 0; i--) {
			swap(arr[1], arr[i]);
			make_maxheap(1, i - 1);
		}
	}
}


int main()
{
	string cmd;

	cout << "�ּ� ���� ������� min, �ִ� ���� ������� max�� �Է��ϼ���" << endl;
	cin >> cmd;

	if (cmd == "min") {
		heapsort(25, 0);
		for (int i = 25; i > 0; i--) cout << arr[i] << " ";
	}
	else if (cmd == "max") {
		heapsort(25, 1);
		for (int i = 25; i > 0; i--) cout << arr[i] << " ";
	}
	else cout << "�߸� �Է��ϼ̽��ϴ�." << endl;

	return 0;
}