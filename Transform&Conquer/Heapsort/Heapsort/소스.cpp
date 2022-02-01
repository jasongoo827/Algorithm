#include <bits/stdc++.h>

using namespace std;

int arr[26] = { 0, 31, 30, 23, 2, 33, 61, 87, 58, 53, 32, 68, 29, 38, 34, 66, 42, 8, 21, 125, 341, 221, 648, 62, 1, 921 };

void make_maxheap(int root, int n) {
	int temp = arr[root]; // 해당 부모 노드
	int child = root * 2; // 왼쪽 자식 노드
	while (child <= n) {
		// 더 큰 자식 노드 찾기
		if (child < n && arr[child] < arr[child + 1])
			child++;
		if (temp < arr[child]) { // 자식 노드가 더 클 경우
			arr[child / 2] = arr[child];
			child *= 2; // 레벨 낮추기
		}
		else break;
	}
	arr[child / 2] = temp;

}

void make_minheap(int root, int n) {
	int temp = arr[root]; // 해당 부모 노드
	int child = root * 2; // 왼쪽 자식 노드
	while (child <= n) {
		// 더 작은 자식 노드 찾기
		if (child < n && arr[child] > arr[child + 1])
			child++;
		if (temp > arr[child]) { // 자식 노드가 더 작을 경우
			arr[child / 2] = arr[child];
			child *= 2; // 레벨 낮추기
		}
		else break;
	}
	arr[child / 2] = temp;

}

void heapsort(int n, int type) {
	// 최대 힙 구성
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

	cout << "최소 힙을 만드려면 min, 최대 힙을 만드려면 max를 입력하세요" << endl;
	cin >> cmd;

	if (cmd == "min") {
		heapsort(25, 0);
		for (int i = 25; i > 0; i--) cout << arr[i] << " ";
	}
	else if (cmd == "max") {
		heapsort(25, 1);
		for (int i = 25; i > 0; i--) cout << arr[i] << " ";
	}
	else cout << "잘못 입력하셨습니다." << endl;

	return 0;
}